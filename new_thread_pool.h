#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
#include<errno.h>
#include<string.h>
#include<pthread.h>
#include<queue>
#include<assert.h>
#include<functional>
#include<stdint.h>

typedef std::function<void(void)> CallBack;

template<typename T>
class Queue{
private:   
    T* m_pData;
    uint32_t m_nSize;
    uint32_t m_nReadIndex;
    uint32_t m_nWriteIndex;
public:
    Queue(int nSize):m_nSize(nSize){
        m_pData = new T[m_nSize];
        m_nReadIndex = m_nWriteIndex = 0;
    }
    ~Queue(){
        delete []m_pData;
    }

    int Enqueue(T item){
        m_pData[m_nWriteIndex] = item;
        m_nWriteIndex = (m_nWriteIndex + 1)%m_nSize;
    }

    T Dequeue(){
        T ret = m_pData[m_nReadIndex];
        m_nReadIndex = (m_nReadIndex + 1)%m_nSize;
        return ret;
    }

    bool Full(){
        return ((m_nWriteIndex + 1) % m_nSize == m_nReadIndex);
    }

    bool Empty(){
        return (m_nWriteIndex == m_nReadIndex);
    }

    bool Size(){
        return m_nSize - 1;
    }
};


class ThreadPool{
private:
    pthread_mutex_t m_mutex;
    pthread_cond_t m_notFull;
    pthread_cond_t m_notEmpty;
    pthread_cond_t m_idle;
    Queue<CallBack> _queue;
    int m_nSize;
    int m_nWorker;
    pthread_t* _threads;
    bool m_bQuit;
public:
    explicit ThreadPool(int nSize, int nWorker=4):m_nSize(nSize),m_nWorker(nWorker),_queue(nSize){
        pthread_mutex_init(&m_mutex, NULL);
        pthread_cond_init(&m_notFull, NULL);
        pthread_cond_init(&m_notEmpty,NULL);
        pthread_cond_init(&m_idle,NULL);
        m_bQuit = false;
    }

    ~ThreadPool(){
        pthread_mutex_destroy(&m_mutex);
        pthread_cond_destroy(&m_notFull);
        pthread_cond_destroy(&m_notEmpty);
        pthread_cond_destroy(&m_idle);
    }

    void Start(){
        _threads = new pthread_t[m_nWorker];
        for(int i = 0; i<m_nWorker;++i){
            pthread_create(&_thread[i],NULL, &ThreadPool::RunLoop, this);
        }
    }

    void Wait(){
        pthread_mutex_lock(&m_mutex);
        while(!_queue.Empty()){
            pthread_cond_wait(&m_idle, &m_mutex);
        }
        m_bQuit = true;
        pthread_cond_broadcast(&m_notEmpty);
        for(int i = 0;i<m_nWorker;++i){
            pthread_join(_thread[i], NULL);
        }
    }

    void Stop(){
        m_bQuit = true;
        pthread_cond_broadcast(&m_notEmpty);
        for(int i = 0;i<m_nWorker;++i){
            pthread_join(_thread[i], NULL);
        }
    }

    static void* RunLoop(void* arg){
        ThreadPool* p = (ThreadPool*)arg;
        p->Run();
        return NULL;
    }

    void Run(){
        while(!m_bQuit){
            pthread_mutex_lock(&m_mutex);
            while(!m_bQuit && _queue.Empty()){
                pthread_cond_wait(&m_notEmpty, &m_mutex);
            }
            CallBack cb;
            if(!_queue.Empty){
                cb = _queue.Dequeue();
            }
            if(_queue.Empty()){
                pthread_cond_signale(&m_idle);
            }
            pthread_mutex_unlock(&m_mutex);
            pthread_cond_signal(&m_notFull);
            if(cb){
                cb();
            }
        }
    }

    void Add(CallBack cb){
        pthread_mutex_lock(&m_mutex);
        while(_queue.Full()){
            pthread_cond_wait(&m_notFull, &m_mutex);
        }
        assert(!_queue.Full());
        _queue.Enqueue(cb);
        pthread_cond_signal(&m_notEmpty);
        pthread_mutex_unlock(&m_mutex);
    }
};

#endif
