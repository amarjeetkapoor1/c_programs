#include<pthread.h>
#include<stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];
int size=0;
int start=0;
int end=0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t elementProduced = PTHREAD_COND_INITIALIZER;
pthread_cond_t elementConsumed  = PTHREAD_COND_INITIALIZER;

void increment() {
    
    if(size<MAX_SIZE) {
        arr[start]=start;
        printf("%d is created \n", start);
        if( start==MAX_SIZE) {
            start=0;
        } else {
            start++;
        }
        size++;
    }
}

void decrement() {
    
    if(size>0) {
        printf("%d is consumed \n",arr[end]);
        size--;
        if( end==MAX_SIZE) {
            end=0;
        } else {
            end++;
        }
    }
}


void produce() {

    pthread_mutex_lock(&mutex);
    while(size==MAX_SIZE) {
        pthread_cond_wait(&elementConsumed, &mutex);
    }
    increment();
    pthread_cond_signal(&elementProduced);
    pthread_mutex_unlock(&mutex);
}


void consume() {

    pthread_mutex_lock(&mutex);
    while (size==0) {
        pthread_cond_wait(&elementProduced, &mutex);
    }
    decrement();
    pthread_cond_signal(&elementConsumed);
    pthread_mutex_unlock(&mutex);

}

void *producer(void *param) {

    while(1)
        produce();
}

void *consumer(void *param) {

    while(1)
        consume();

}

int main() {

    pthread_t producerThread, consumerThread;
    pthread_create( &producerThread, NULL, producer, NULL);
    pthread_create( &consumerThread, NULL, consumer, NULL);
    pthread_join( producerThread, NULL);
    pthread_join( consumerThread, NULL);
}

