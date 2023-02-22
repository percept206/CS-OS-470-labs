#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#define NUM_THREADS 2
int* numbers;
int num_count;
int max, min;
void *calc_max(void *arg) {
    max = numbers[0];
    for (int i = 1; i < num_count; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    pthread_exit(NULL);
}
void *calc_min(void *arg) {
    min = numbers[0];
    for (int i = 1; i < num_count; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    pthread_exit(NULL);
}
int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    numbers = new int[argc-1];
    for (int i = 1; i < argc; i++){
        numbers[i-1] = (int)strtol(argv[i], NULL, 10);
    }
    num_count = argc-1;
    int rc;
    rc = pthread_create(&threads[0], NULL, calc_max, NULL);
    if (rc) {
        printf("Error: Unable to create thread.\n");
        exit(-1);
    }
    rc = pthread_create(&threads[1], NULL, calc_min, NULL);
    if (rc) {
        printf("Error: Unable to create thread.\n");
        exit(-1);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: Unable to join thread.\n");
            exit(-1);
        }
    }
    printf("The minimum value is %d\n", min);
    printf("The maximum value is %d\n", max);
    pthread_exit(NULL);
}
