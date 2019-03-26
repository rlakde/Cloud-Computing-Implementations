#include<iostream>
#include<new>
#include<string.h>
#include<time.h>
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
using namespace std;

#define MAX_THREAD 2 
long int realnum=1000000000;
int num;
char *srcptr = new char [realnum];
char *destptr = new char [realnum];

void* ThreadOne(void* arg) 
{ 
    int i;
	for(int l=0;l<100;l++)
  {	
	 for(i=0;i<realnum/2;i++)
	 {		
	  memcpy(destptr+i,srcptr+i, 1);
	 }
	 i = 0;
  }
}

void* ThreadTwo(void* arg) 
{   
  int i=0;
	for(int l=0;l<100;l++)
  {	
	 for(i=realnum;i>realnum/2;i--)
	 {		
	  memcpy(destptr+i,srcptr+i, 1);
	 }
	 i=0;
  }
}
  
int main () 
{
  int* p;
  int* q;
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
