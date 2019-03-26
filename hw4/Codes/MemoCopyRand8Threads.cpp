#include<iostream>
#include<new>
#include<string.h>
#include<time.h>
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
using namespace std;

#define MAX_THREAD 8
long int realnum=1000000000,cntr;  
int num,blkbyte;
char *srcptr = new char [realnum];
char *destptr = new char [realnum];

int GeneRandom(int k,int max,int min)
{
	srand(k);
    return rand()%(max+1-min)+min;
}

void* ThreadOne(void* arg) 
{ 
    int i;
	for(int l=0;l<100;l++)
  {	
	 for(i=0;i<cntr/8;i++)
	 {	
      int randloc = GeneRandom(i,cntr/8-1,0);	
	  memcpy(destptr+randloc,srcptr+randloc, blkbyte);
	 }
	 i = 0;
  }
}

void* ThreadTwo(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=cntr/8;i<2*cntr/8;i++)
	 {	
      int randloc = GeneRandom(i,2*cntr/8-1,cntr/8);	 
	  memcpy(destptr+randloc,srcptr+randloc, blkbyte);
	 }
	 i=0;
  }
}

void* ThreadThree(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=2*cntr/8;i<3*cntr/8;i++)
	 {	
      int randloc = GeneRandom(i,3*cntr/8-1,2*cntr/8);	 
	  memcpy(destptr+randloc,srcptr+randloc, blkbyte);
	 }
	 i=0;
  }
}

void* ThreadFour(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=3*cntr/8;i<4*cntr/8;i++)
	 {	
      int randloc = GeneRandom(i,4*cntr/8-1,(3*cntr)/8);	 
	  memcpy(destptr+randloc,srcptr+randloc, blkbyte);
	 }
	 i=0;
  }
}

void* ThreadFive(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=4*cntr/8;i<5*cntr/8;i++)
	 {	
      int randloc = GeneRandom(i,5*cntr/8-1,(4*cntr)/8);	 
	  memcpy(destptr+randloc,srcptr+randloc, blkbyte);
	 }
	 i=0;
  }
}

void* ThreadSix(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=5*cntr/8;i<6*cntr/8;i++)
	 {	
      int randloc = GeneRandom(i,6*cntr/8-1,(5*cntr)/8);	 
	  memcpy(destptr+randloc,srcptr+randloc, blkbyte);
	 }
	 i=0;
  }
}

void* ThreadSeven(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=6*cntr/8;i<7*cntr/8;i++)
	 {	
      int randloc = GeneRandom(i,7*cntr/8-1,(6*cntr)/8);	 
	  memcpy(destptr+randloc,srcptr+randloc, blkbyte);
	 }
	 i=0;
  }
}

void* ThreadEight(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=7*cntr/8;i<=cntr;i++)
	 {	
      int randloc = GeneRandom(i,cntr,(7*cntr)/8);	 
	  memcpy(destptr+randloc,srcptr+randloc, blkbyte);
	 }
	 i=0;
  }
}
  
int main () 
{
  int* p,* r,* t,* u;
  int* q,* s,* v,* w;
  int blksize;
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
	  pthread_create(&threads[4], NULL, ThreadOne, (void*)(t)); 
      pthread_create(&threads[5], NULL, ThreadTwo, (void*)(u));
	  pthread_create(&threads[6], NULL, ThreadThree, (void*)(v)); 
      pthread_create(&threads[7], NULL, ThreadFour, (void*)(w));
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
