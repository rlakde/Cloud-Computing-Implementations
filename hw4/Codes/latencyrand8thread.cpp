#include<iostream>
#include<new>
#include<string.h>
#include<time.h>
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
using namespace std;

#define MAX_THREAD 8 
long int realnum=1000000000; 
int num;
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
	 for(i=0;i<(realnum/8);i++)
	 {
      int randloc = GeneRandom(i,realnum/8-1,0);		 
	  memcpy(destptr+randloc,srcptr+randloc, 1);
	 }
	 i = 0;
  }
}

void* ThreadTwo(void* arg) 
{ 
    int i;
	for(int l=0;l<100;l++)
  {	
	 for(i=(realnum/8);i<((2*realnum)/8);i++)
	 {	
      int randloc = GeneRandom(i,realnum/4-1,realnum/8); 
	  memcpy(destptr+randloc,srcptr+randloc, 1);
	 }
	 i = 0;
  }
}

void* ThreadThree(void* arg) 
{ 
    int i;
	for(int l=0;l<100;l++)
  {	
	 for(i=((2*realnum)/8);i<((3*realnum)/8);i++)
	 {
      int randloc = GeneRandom(i,3*realnum/8-1,realnum/4); 		 
	  memcpy(destptr+randloc,srcptr+randloc, 1);
	 }
	 i = 0;
  }
}

void* ThreadFour(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=((3*realnum)/8);i<((4*realnum)/8);i++)
	 {
      int randloc = GeneRandom(i,realnum/2-1,3*realnum/8);		 
	  memcpy(destptr+randloc,srcptr+randloc, 1);
	 }
	 i=0;
  }
}

void* ThreadFive(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=((4*realnum)/8);i<((5*realnum)/8);i++)
	 {
      int randloc = GeneRandom(i,5*realnum/8-1,realnum/2);		 
	  memcpy(destptr+randloc,srcptr+randloc, 1);
	 }
	 i=0;
  }
}

void* ThreadSix(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=((5*realnum)/8);i<((6*realnum)/8);i++)
	 {
      int randloc = GeneRandom(i,6*realnum/8-1,5*realnum/8);		 
	  memcpy(destptr+randloc,srcptr+randloc, 1);
	 }
	 i=0;
  }
}

void* ThreadSeven(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=((6*realnum)/8);i<((7*realnum)/8);i++)
	 {
      int randloc = GeneRandom(i,7*realnum/8-1,6*realnum/8);		 
	  memcpy(destptr+randloc,srcptr+randloc, 1);
	 }
	 i=0;
  }
}

void* ThreadEight(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=((7*realnum)/8);i<=realnum;i++)
	 {	
      int randloc = GeneRandom(i,realnum,7*realnum/8); 
	  memcpy(destptr+randloc,srcptr+randloc, 1);
	 }
	 i=0;
  }
}
  
int main () 
{
  int* p,* t,* u,* v,* x;
  int* q,* r,* s;
  pthread_t threads[MAX_THREAD];
  //cout<<"Enter for how many bytes you want to do memory copy"<<endl;
  //cin>>realnum;
  for(int k=0;k<realnum;k++)
  {
	 *(srcptr+k) = '0';
  }  
  if (srcptr==nullptr || destptr==nullptr)
	  cout<<"Memory not allocated"<<endl;
  else
  {
	  clock_t start = clock();
      pthread_create(&threads[0], NULL, ThreadOne, (void*)(p)); 
      pthread_create(&threads[1], NULL, ThreadTwo, (void*)(q));
	  pthread_create(&threads[2], NULL, ThreadThree, (void*)(r)); 
      pthread_create(&threads[3], NULL, ThreadFour, (void*)(s));
	  pthread_create(&threads[4], NULL, ThreadFive, (void*)(t)); 
      pthread_create(&threads[5], NULL, ThreadSix, (void*)(u));
	  pthread_create(&threads[6], NULL, ThreadSeven, (void*)(v)); 
      pthread_create(&threads[7], NULL, ThreadEight, (void*)(x));
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
