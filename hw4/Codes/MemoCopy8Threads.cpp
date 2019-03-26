#include<iostream>
#include<new>
#include<string.h>
#include<pthread.h>
#include<time.h>
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
using namespace std;

#define MAX_THREAD 8 
long int realnum=1000000000,cntr;
int num,blksize,blkbyte;
char *srcptr = new char [realnum];
char *destptr = new char [realnum];

void* ThreadOne(void* arg) 
{   int j = 0,i;
	for(int l=0;l<100;l++)
  {	
	 for(i=0;i<cntr/8;i++)
	 {		
	  memcpy(destptr+j,srcptr+j, blkbyte);
	  j = j + blkbyte;
	 }
	 i = 0;
	 j = 0;
  }
  
}

void* ThreadTwo(void* arg) 
{   int j = 0,i;
	for(int l=0;l<100;l++)
  {	
	 for(i=cntr/8;i<cntr/4;i++)
	 {		
	  memcpy(destptr+j,srcptr+j, blkbyte);
	  j = j + blkbyte;
	 }
	 i = 0;
	 j = 0;
  }
  
}

void* ThreadThree(void* arg) 
{   int j = 0,i;
	for(int l=0;l<100;l++)
  {	
	 for(i=cntr/4;i<3*cntr/8;i++)
	 {		
	  memcpy(destptr+j,srcptr+j, blkbyte);
	  j = j + blkbyte;
	 }
	 i = 0;
	 j = 0;
  }
  
}

void* ThreadFour(void* arg) 
{   
    int i,k=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=3*cntr/8;i<cntr/2;i++)
	 {		
	  memcpy(destptr+k,srcptr+k, blkbyte);
	  k = k + blkbyte;
	 }
	 i = 0;
	 k = 0;
  }
}

void* ThreadFive(void* arg) 
{   
    int i,k=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=cntr/2;i<5*cntr/8;i++)
	 {		
	  memcpy(destptr+k,srcptr+k, blkbyte);
	  k = k + blkbyte;
	 }
	 i = 0;
	 k = 0;
  }
}

void* ThreadSix(void* arg) 
{   
    int i,k=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=5*cntr/8;i<6*cntr/8;i++)
	 {		
	  memcpy(destptr+k,srcptr+k, blkbyte);
	  k = k + blkbyte;
	 }
	 i = 0;
	 k = 0;
  }
}

void* ThreadSeven(void* arg) 
{   
    int i,k=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=6*cntr/8;i<7*cntr/8;i++)
	 {		
	  memcpy(destptr+k,srcptr+k, blkbyte);
	  k = k + blkbyte;
	 }
	 i = 0;
	 k = 0;
  }
}

void* ThreadEight(void* arg) 
{   
    int i,k=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=7*cntr/8;i<=cntr;i++)
	 {		
	  memcpy(destptr+k,srcptr+k, blkbyte);
	  k = k + blkbyte;
	 }
	 i = 0;
	 k = 0;
  }
}
  
int main () 
{
  int* p,* q,* r,* s,* t,* u,* v,* w;
  pthread_t threads[MAX_THREAD];
  //cout<<"Enter for how many bytes you want to do memory copy"<<endl;
  //cin>>realnum;
  cout<<"Enter block size in KB"<<endl;
  cin>>blksize; 
  blkbyte = blksize * 1000;
  cntr = realnum/blkbyte;
  for(int k=0;k<realnum;k++)
  {
	 *(srcptr+k) = '0';
  }  
  if (srcptr==nullptr || destptr==nullptr)
	  cout<<"Memory not allocated"<<endl;
  else
  {   clock_t start = clock();
      pthread_create(&threads[0], NULL, ThreadOne, (void*)(p)); 
      pthread_create(&threads[1], NULL, ThreadTwo, (void*)(q));
	  pthread_create(&threads[2], NULL, ThreadThree, (void*)(r)); 
      pthread_create(&threads[3], NULL, ThreadFour, (void*)(s));
	  pthread_create(&threads[4], NULL, ThreadFive, (void*)(t)); 
      pthread_create(&threads[5], NULL, ThreadSix, (void*)(u));
	  pthread_create(&threads[6], NULL, ThreadSeven, (void*)(v)); 
      pthread_create(&threads[7], NULL, ThreadEight, (void*)(w));
	  //joining and waiting for all threads to complete 
	  for (int ii = 0; ii < MAX_THREAD; ii++) 
	  { 
	   pthread_join(threads[ii], NULL);
	   
	  } 
	  clock_t timeElapsed = clock() - start;
	  unsigned msElapsed = timeElapsed / CLOCKS_PER_MS;
	  cout<<"Time Required in ms "<<msElapsed<<endl;
	  delete[] srcptr;
	  delete[] destptr;
	  cout<<"Memory transfer done"<<endl;
  } 
  return 0; 
} 

