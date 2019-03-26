#include<iostream>
#include<new>
#include<string.h>
#include<time.h>
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)
using namespace std;
  
int main () 
{
  long int realnum,cntr; 	
  int num,blksize,i,j=0;	
  cout<<"Enter for how many bytes you want to do memory copy"<<endl;
  cin>>realnum;
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
	 for(i=0;i<realnum;i++)
	 {		
	  memcpy(destptr+i,srcptr+i, 1);
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

