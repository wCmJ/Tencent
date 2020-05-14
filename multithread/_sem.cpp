#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<deque>

sem_t g_not_full, g_not_empty;
pthread_mutex_t g_mutex;
std::deque<int> g_queue;


void* produce(void* arg){
    int val = *((int*)arg);
    int num = 10;
    while(num--){
        sem_wait(&g_not_full);
        pthread_mutex_lock(&g_mutex);        
        g_queue.push_back(val);
        std::cout<<pthread_self()<<" : produce: "<<val<<std::endl;
        val += 2;
        pthread_mutex_unlock(&g_mutex);
        sem_post(&g_not_empty);
    }
}


void* consume(void* arg){
    while(true){
        sem_wait(&g_not_empty);
        pthread_mutex_lock(&g_mutex); 
        //sleep(3);
        int val = g_queue.front();
        g_queue.pop_front();
        std::cout<<pthread_self()<<" : --------consume: "<<val<<std::endl;
        pthread_mutex_unlock(&g_mutex);
        sem_post(&g_not_full);
    }
}

int main(){
    pthread_t p1, p2, c1;
    pthread_mutex_init(&g_mutex, NULL);
    sem_init(&g_not_full, 0, 3);
    sem_init(&g_not_empty, 0, 0);
    int val2 = 1, val3 = 2;
    pthread_create(&p1, NULL, &produce, (void*)&val2);
    pthread_create(&p2, NULL, &produce, (void*)&val3);
    pthread_create(&c1, NULL, &consume, NULL);

    pthread_join(p1,NULL);
    pthread_join(c1,NULL);

    sem_destroy(&g_not_empty);
    sem_destroy(&g_not_full);

    return 0;
}

