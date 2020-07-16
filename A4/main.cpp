
//==============================================================================
//HW#: Assignment4
//Name: Fernando Juarez & Michael Trani
//Date: November 22, 2019
//Course: CS433 Prog 4
//Complier:  g++
//File type: main.cpp - Only file in this program as it has the implementation of
// producer and consumer code as well as adding items and deleting them from the
// buffer created, It is also the driver of the program as it reads user input
// and then from user given input it becomes the commands for the main to create
// the amount of items created by consumers and producers wanted by the user input.
//==============================================================================

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

const int buffSize =10; //No given size was given so why not 10
typedef int item;       // as shown in page P-40 #define BUFFER_SIZE 5

// Mutex
pthread_mutex_t mutex;
sem_t isEmpty;
sem_t isFull;

//Pthreads - page 170 similar implementation
pthread_t threadID;
pthread_attr_t num;

//declaring buffer - page 126 similar implementation of of buffer size
item buffer[buffSize];
int top = 0;
int end = 0;
int count = 0;

//showBuffer function
void showBuffer() {
    std::cout << "The current content of the Buffer is[ ";
    for(int x = top; x < end; x++) {
        std::cout << buffer[x] << " ";
    }
    std::cout << "]";
	std::cout << std::endl << std::endl;
}

//Add item into buffer - works like a stack where item would be pushed
bool addItem(item item) {
    if(count < buffSize) {
        buffer[end] = item;
        // initially had buffer[top] = item  and top instead of end in the next line but had errors
	end = (end + 1)% buffSize;
        count++;
        // Displaying instruction requirements
        std::cout << "Item " << item << " inserted by a producer." << std::endl;
        return true;
    }
    return false;
}

//Removes item function - works as FIFO removal process
bool deleteItem() { // works similar to a stack where ite would be popped
  if(count > 0) { // If not empty meaning that if it is greater than 0
        // initially had buffer[end] = item  and end instead of top in the next line but had minor bugs
        item item = buffer[top];
	top = (top + 1) % buffSize;
        count--;
        std::cout << "Item " << item << " removed by a consumer." << std::endl;
        // return 0 on P41 but was getting some errors so changed to return true and false
	return true;
    }
    return false;
}

//Producer 
void *producer(void *param) {
    item item;
    while(true) {
      srand(time(0)); //srand will give us true random values every time
      sleep((rand() % 4));    // range of 0 - 4
	    // srand(time(0));    // initially had it here but had duplicate values
        item = rand() % 95 + 1; // range of 1 and 95

        // linux sem_wait = if semaphores value is greater than 0 it proceeds
        sem_wait(&isEmpty);
        pthread_mutex_lock(&mutex);

        if(!addItem(item)) {
            std::cout << "Invalid. Buffer is full." << std::endl;
        } else {
            showBuffer();
        }

        pthread_mutex_unlock(&mutex);
        sem_post(&isFull);
    }

}

//Consumer code 
void *consumer(void *param) {
    item item;
    while(true) {
        sleep((rand() % 4));

	// as mentioned on top sem_wait relies on waiting to check if it is full or not to proceed
        sem_wait(&isFull);
        pthread_mutex_lock(&mutex);

        if(!deleteItem()) {
            std::cout << "Woah Can't do that. Buffer is currently empty." << std::endl;
        } else {
            showBuffer();
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&isEmpty);
    }

}
// main driver of assignment - prints out header and then waits for user input
int main(int argc, char* argv[]) {
    std::cout << "=================================================================" << std::endl;
    std::cout << "CS 433 Programming assignment 4" << std::endl;
    std::cout << "Author: Fernando Juarez and Michael Trani" << std::endl;
    std::cout << "Date: 11/22/2019" << std::endl;
    std::cout << "Course: CS433 - Prof.Zhang: Operating Systems" << std::endl;
    std::cout << "Description : Program to simulate Producer Consumer" << std::endl;
    std::cout << "=================================================================\n" << std::endl;

    //Error handling - decided to restrict user input
    if (argc < 4 || argc > 4) {
        std::cout << "Wrong Input Format. Please execute the program in the following format:" << std::endl;
        std::cout << "./output <sleeptime> <#ofProd> <#ofCons>" << std::endl;;
        return -1;
    }

    //Input conversion of string to int
    int sTime = atoi(argv[1]);
    int numProd = atoi(argv[2]);
    int numCons = atoi(argv[3]);

    // implementation of page 170 to set the attributes of thread
    pthread_mutex_init(&mutex, NULL);
    sem_init(&isFull, 0, 0);
    sem_init(&isEmpty, 0, buffSize);
    pthread_attr_init(&num);

    // Part where user input now becomes the command of the program
    for(int x = 0; x < numProd; x++) {
        pthread_create(&threadID, &num, producer, NULL);// number of Producer Threads
    }
    for(int x = 0; x < numCons; x++) {
        pthread_create(&threadID, &num, consumer, NULL);// number of Consumer Threads
    }
    
    // usleep = ms and sleep function accepts in seconds
    sleep(sTime); // function in linux that accepts in seconds
    
    return 0;
}

