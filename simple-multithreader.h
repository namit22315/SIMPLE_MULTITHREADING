#ifndef SIMPLE_MULTITHREADER_H
#define SIMPLE_MULTITHREADER_H
#include <iostream>
#include <list>
#include <functional>
#include <stdlib.h>
#include <cstring>
#include <time.h>

int po=0;

typedef struct{
  int start;
  int end;
  std::function<void(int)> lambda;
}thread_args;

typedef struct{
  int start1;
  int start2;
  int end1;
  int end2;
  std::function<void(int,int)> lambda;
}thread_args_2;



void *thread_func(void *ptr) {
  thread_args *t = ((thread_args *)ptr);
  for(int k=t->start;k<t->end;k++){
t->lambda(k);
  }
  // t->lambda(t->start); // Use the lambda function directly

  return NULL;
}

void *thread_func_2(void *ptr){
  thread_args_2 *t2=((thread_args_2 *)ptr);
  for (int w=t2->start1;w<t2->end1;w++){
    for(int x=t2->start2;x<t2->end2;x++){
      t2->lambda(w,x);
    }
  }
  return NULL;
}



  // parallel_for accepts a C++11 lambda function and runs the loop body (lambda) in 
// parallel by using ‘numThreads’ number of Pthreads to be created by the simple-multithreader
void parallel_for(int low, int high, std::function<void(int)> &&lambda, int numThreads){
  clock_t start_time=clock();
  printf("executing parallel_for 1\n");
  pthread_t tid[numThreads];
  thread_args args[numThreads];
int chunk = high/numThreads;

for (int i = 0; i < numThreads; i++) {
  args[i].start=i*chunk;
   args[i].end=(i+1)*chunk;
  args[i].lambda=lambda;
        // Pass the lambda function as an argument to the creation id 140553190635200thread function
        po=i;
        pthread_create(&tid[i], nullptr, thread_func,(void*) &args[i]);
        
    }

    // Wait for threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(tid[i], nullptr);
    }
    clock_t end_time = clock(); // Record end time
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", elapsed_time);

}
// This version of parallel_for is for parallelizing two-dimensional for-loops, i.e., an outter for-i loop and 
// an inner for-j loop. Loop properties, i.e. low, high are mentioned below for both outter 
// and inner for-loops. The suffixes “1” and “2” represents outter and inner loop properties respectively. 
void parallel_for(int low1, int high1, int low2, int high2,
std::function<void(int, int)> &&lambda, int numThreads){
  clock_t start_time = clock(); 
    printf("executing parallel_for 2\n");
    pthread_t tid2[numThreads];
    thread_args_2 args2[numThreads];
    int chunk = high1/numThreads;
    for (int i = 0; i < numThreads; i++) {
      args2[i].start1=i*chunk;
      args2[i].end1=(i+1)*chunk;
      args2[i].start2=0;
      args2[i].end2=high2;
      args2[i].lambda=lambda;
  //     args2[i].start1=i*chunk;
  //  args2[i].end1=(i+1)*chunk;
  // args2[i].lambda=lambda;
  //   args2[i].start2=j*chunk;
  //   args2[i].end2=(j+1)*chunk;
    po=i;
    // printf("j: %d i: %d \n",j,i);
        pthread_create(&tid2[i], nullptr, thread_func_2,(void*) &args2[i]);
  
        // Pass the lambda function as an argument to the creation id 140553190635200thread function
        
        
    }

    // Wait for threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(tid2[i], nullptr);
    }
    clock_t end_time = clock(); // Record end time
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", elapsed_time);

}






#endif
