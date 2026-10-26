#include <stdio.h>
#include <pthread.h>

int signal = 0;

void* reader() {
    printf("vehicle checked signal = %d\n", signal);
}

void* writer() {
    signal++;
    printf("controller updated signal = %d \n", signal);
}

int main() {
    pthread_t r1, r2, w1;
    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);
    return 0;
}
