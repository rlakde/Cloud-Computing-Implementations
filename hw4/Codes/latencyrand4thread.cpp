#include<iostream>
#include<new>
#include<string.h>
#include<time.h>
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
using namespace std;

#define MAX_THREAD 4 
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
	 for(i=0;i<realnum/4;i++)
	 {	
      int randloc = GeneRandom(i,realnum/4-1,0); 
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
	 for(i=realnum/4;i<realnum/2;i++)
	 {
      int randloc = GeneRandom(i,realnum/2-1,realnum/4); 		 
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
	 for(i=realnum/2;i<(0.75*realnum);i++)
	 {
      int randloc = GeneRandom(i,0.75*realnum-1,realnum/2);		 
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
	 for(i=(0.75*realnum);i<=realnum;i++)
	 {	
      int randloc = GeneRandom(i,realnum,0.75*realnum); 
	  memcpy(destptr+randloc,srcptr+randloc, 1);
	 }
	 i=0;
  }
}
  
int main () 
{
  int* p;
  int* q;
  int* r;
  int* s;
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
  {   clock_t start = clock();
      pthread_create(&threads[0], NULL, ThreadOne, (void*)(p)); 
      pthread_create(&threads[1], NULL, ThreadTwo, (void*)(q));
	  pthread_create(&threads[2], NULL, ThreadThree, (void*)(r)); 
      pthread_create(&threads[3], NULL, ThreadFour, (void*)(s));
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
