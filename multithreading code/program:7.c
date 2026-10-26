
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t s1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t s2 = PTHREAD_MUTEX_INITIALIZER;

void* b1(void *arg) {
    pthread_mutex_lock(&s1);
    puts("Bag 1 : 1");
    usleep(1e5);
    pthread_mutex_lock(&s2);
    puts("Bag 1 : 2");
    return NULL;
}

void* b2(void *arg) {
    pthread_mutex_lock(&s2);
    puts("Bag 2 : 1");
    usleep(1e5);
    pthread_mutex_lock(&s1);
    puts("Bag 2 : 2");
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, b1, NULL);
    pthread_create(&t2, NULL, b2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
