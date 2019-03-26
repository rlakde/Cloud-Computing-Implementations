#include<iostream>
#include<new>
#include<string.h>
#include<time.h>
using namespace std;
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
  
int main () 
{
  long int realnum,cntr;	
  int blksize,i,j=0,blkbyte;	
  cout<<"Enter for how many bytes you want to do memory copy"<<endl;
  cin>>realnum;
  cout<<"Enter block size in KB"<<endl;
  cin>>blksize; 
  blkbyte = blksize * 1000;
  cntr = realnum/blkbyte; 
  char *srcptr = new char [realnum];
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
	  memcpy(destptr+j,srcptr+j, blkbyte);
	  j = j + blkbyte;
	 }
	 i = 0;
	 j = 0;
  }
	 cout<<"Memory transfer done"<<endl;
	 clock_t timeElapsed = clock() - start;
	 unsigned msElapsed = timeElapsed / CLOCKS_PER_MS;
	 cout<<"Time Required in ms "<<msElapsed<<endl;
	 delete[] srcptr;
	 delete[] destptr;
  }
  return 0; 
} 

