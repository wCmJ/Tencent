#include<iostream>
#include<pthread.h>
#include<deque>
#include<unistd.h>

pthread_mutex_t g_mutex;
pthread_cond_t g_not_empty;
pthread_cond_t g_not_full;
std::deque<int> g_deque;
const int FULL = 4;


void* produce(void* arg){
    int val = *((int*)arg);
    int num = 10;
    std::cout<<"produce start"<<std::endl;
    while(num--){
        //sleep(1);
        pthread_mutex_lock(&g_mutex);
        std::cout<<"produce lock"<<std::endl;
        
        while(g_deque.size() >= FULL){
            pthread_cond_wait(&g_not_full, &g_mutex);
        }
        std::cout<<"produce run"<<std::endl;
        g_deque.push_back(val);
        std::cout<<pthread_self()<<": produce "<<val<<std::endl;
        val += 2;
        //sleep(2);        
        pthread_mutex_unlock(&g_mutex);
        pthread_cond_signal(&g_not_empty);
    }
}

void* consume(void* arg){
    std::cout<<"consuem start"<<std::endl;
    while(true){
        pthread_mutex_lock(&g_mutex);
        std::cout<<"consume lock"<<std::endl;
        while(g_deque.empty()){
            pthread_cond_wait(&g_not_empty, &g_mutex);
        }
        std::cout<<"consume run"<<std::endl;
        int val = g_deque.front();
        g_deque.pop_front();
        std::cout<<pthread_self()<<": ------ consume "<<val<<std::endl;
        pthread_cond_signal(&g_not_full);
        pthread_mutex_unlock(&g_mutex);
    }
}



int main(){
    pthread_t p1, c1;
    pthread_mutex_init(&g_mutex, NULL);
    pthread_cond_init(&g_not_full, NULL);
    pthread_cond_init(&g_not_empty, NULL);
    int val = 1;
    pthread_create(&p1, NULL, produce, (void*)&val);
    pthread_create(&c1, NULL, consume, NULL);

    pthread_join(p1, NULL);
    pthread_join(c1, NULL);

    pthread_cond_destroy(&g_not_empty);
    pthread_cond_destroy(&g_not_full);
    pthread_mutex_destroy(&g_mutex);

    return 0;
}


