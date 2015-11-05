#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h> //for POSIX threads
#include <semaphore.h> //for semaphore control
using namespace std;

int guests = 0;
int workers = 0;
int bellhops = 0;
int guestsRetired = 0;
pthread_t guestThreads[25]; //place threads in global scope
pthread_t workerThreads[2];
pthread_t bellhopThreads[2];
sem_t guestReady;
sem_t workerReady;
sem_t allGuestsRetired;

void *guest(void* param) {
	int bags = rand() % 5 + 1;
	int id = guests++;
	cout<<bags<<endl;
	cout<<"Guest "<<id<<" has been created"<<endl;
	sem_post(&guestReady);
	sem_wait(&workerReady);
	if(++guestsRetired >= 25) {
		sem_post(&allGuestsRetired);		
	}
}

void *frontdesk(void* param) {
	int id = workers++;
    sem_post(&workerReady);
    while(guestsRetired < 25){
		cout<<"Front desk employee "<<id<<" created"<<endl;
    	sem_wait(&guestReady);
		cout<<"hello world frontdesk thread"<<endl;
    	sem_post(&workerReady);
	}
}

int main() {
	cout<<"Simulation starts"<<endl;
	srand(time(NULL));
    sem_init(&guestReady, 0, 0);
    sem_init(&workerReady, 0, 0);
    sem_init(&allGuestsRetired, 0, 0);
    for(int i=0; i<25; i++) {
    	pthread_create(&guestThreads[i], 0, &guest, NULL);   
    	pthread_detach(guestThreads[i]); 	
    }
    for(int i=0; i<2; i++) {
	    pthread_create(&workerThreads[i], 0, &frontdesk, NULL);
    	pthread_detach(workerThreads[i]); 	
    }
    sem_wait(&allGuestsRetired);
	cout<<"Simulation ends"<<endl;
	return 0;
}
