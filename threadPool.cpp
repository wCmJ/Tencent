/*
1.任务队列
2.线程池结构体
3.初始化线程池数目
4.销毁线程池
5.向任务池中加入一个任务
6.从任务池中取出一个任务
7.执行任务池中的任务
8.线程函数
*/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

#define NULL 0
struct task{
    task *pNext;
    int val;
};

struct thread_info{
    int thread_running;//线程运行标志
    int thread_num;//线程个数
    int tasknum;//任务个数
    task* tasks;//任务队列
    pthread_t* threadid;//线程数组
    pthread_mutex_t mutex;//互斥量
    pthread_cond_t cond;//条件变量    
};

thread_info g_threadinfo;
int thread_running = 0;



//初始化线程池
void init_thread_pool(int thread_num){

}

//销毁线程池
void destroy_thread_pool(){

}

//向任务池中增加一个任务
void thread_pool_add_task(task* t){

}

//从任务池中取出一个任务
task* thread_pool_retrieve_task(){

}

//执行任务池中的任务
void thread_pool_do_task(task* t){

}

//线程函数
void* thread_routine(void* thread_param){

}



