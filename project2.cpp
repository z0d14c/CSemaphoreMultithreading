#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <pthread.h> //for POSIX threads
#include <semaphore.h> //for semaphore control
using namespace std;

pthread_t thread1; //place threads in global scope
pthread_t thread2;
sem_t guestReady;
sem_t workerReady;
int main() {
    sem_init(&guestReady, 0, 2);
    sem_init(&workerReady, 0, 1);
	cout<<"hello world";
	return 0;
}

void guest() {
	while(true){

	}
}

void frontdesk() {

}