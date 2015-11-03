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
sem_t testSem;
void *guest(void* param) {
	cout<<"hello world guest thread";
	while(true){

	}
}

void *frontdesk(void* param) {
	cout<<"hello world frontdesk thread";

}
int main() {
    sem_init(&guestReady, 0, 2);
    sem_init(&workerReady, 0, 1);
    sem_init(&testSem, 0, 0);
    pthread_create(&thread1, 0, guest, NULL);
    pthread_create(&thread2, 0, frontdesk, NULL);
	cout<<"hello world";
	pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    sem_wait(&testSem);
	return 0;
}