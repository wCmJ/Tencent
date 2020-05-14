
static void* run_loop(void* arg){
    TP* p = (TP*)arg;
    p->run();
    return NULL;
}

void run(){
    while(!_quit){        
        pthread_mutex_lock(&_mutex);
        while(!_quit && _queue.empty()){// system call with block will return when receiving signal that means it may be not ready when return.
            pthread_cond_wait(&_not_empty, &_mutex); // unlock mutex, start waiting -> lock mutex.
        }
        callback cb;
        if(!_queue.empty()){
            cb = _queue.dequeue();
        }
        if(_queue.empty()){
            pthread_cond_signal(&_idle);
        }
        pthread_cond_signal(&_not_full);
        pthread_mutex_unlock(&_mutex);
        if(cb){
            cb();
        }
    }
}

wait is implemented as a call to the futex system call.
the moment we return from futex call, another thread can send us notification, 
and since we are not waiting inside futex, we'll miss the notification.
So, we need to return to the caller, and have it reevaluate the predicate.

each blocking system call on Linux returns abruptly when the process receives a signal-- because calling signal handler from kernel call is tricky.





read: it does it in a loop, and if 'read' returns EINTR, calls 'read' again.
EINTR means wait is brokened by signal interrupt.

















