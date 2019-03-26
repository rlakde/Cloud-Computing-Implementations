#include<iostream>
#include<new>
#include<string.h>
#include<ctime>
#include<time.h>
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
using namespace std;
  
int GeneRandom(int k,int max,int min)
{
	srand(k);
    return rand()%(max+1-min)+min;
}

int main () 
{
  long int realnum,cntr; 	
  int num,blksize,i,j=0,blkbyte,max,min,randloc;	
  cout<<"Enter for how many bytes you want to do memory copy"<<endl;
  cin>>realnum;
  cout<<"Enter block size in KB"<<endl;
  cin>>blksize; 
  blkbyte = blksize * 1000;
  cntr = realnum/blkbyte; 
  char *srcptr = new char [realnum];
  min = atoi(srcptr);
  max = atoi(srcptr) + realnum - blksize;
  for(int k=0;k<realnum;k++)
  {
	 *(srcptr+k) = '0';
  }
  char *destptr = new char [realnum];  
  if (srcptr==nullptr || destptr==nullptr)
	  cout<<"Memory not allocated"<<endl;
  else
  {
  clock_t start = clock(); 	  
  for(int l=0;l<100;l++)
  {	
	 for(i=0;i<cntr;i++)
	 {	
      randloc = GeneRandom(i,max,min);	  
	  memcpy(destptr+randloc,srcptr+randloc, blkbyte);
	 }
	 i = 0;
  }
      clock_t timeElapsed = clock() - start;
	  unsigned msElapsed = timeElapsed / CLOCKS_PER_MS;
	  cout<<"Time Required in ms "<<msElapsed<<endl;
	  cout<<"Memory transfer done"<<endl;
	  delete[] srcptr;
	  delete[] destptr;
  }
  return 0; 
} 

