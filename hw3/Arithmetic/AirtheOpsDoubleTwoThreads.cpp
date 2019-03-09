#include<iostream>
#include<cstdlib>
#include<ctime>
#include<pthread.h>
using namespace std;

double j = 1.01,k=1.01,l=1.11,m=1.10;
double c = 1.01,d=1.01,e=1.11,f=1.10;
#define MAX_THREAD 2 

//ll & mm equals to 62500000000
unsigned long int limit = 62500000000;

void* ThreadOne(void* arg) 
{ 
	for(unsigned long int ll=0;ll<limit;ll++)
	{
	j = j + 0.1;
	j = j * 1.00;
	j = j - 0.1;
	k = k + 1.00;
	k = k - 1.00;	
	l = l * 1.00;
	m = m * 1.00;		
	}
}

void* ThreadTwo(void* arg) 
{ 
	for(unsigned long int mm=0;mm<limit;mm++)
	{
	c = c + 0.1;
	c = c * 1.00;
	c = c - 0.1;
	d = d + 1.00;
	d = d - 1.00;	
	e = e * 1.00;
	f = f * 1.00;		
	}

}

int main()
{


// declaring two threads 
pthread_t threads[MAX_THREAD]; 
int* p;
int* q; 
int ThrCount = MAX_THREAD;
int start_s = clock();
pthread_create(&threads[ThrCount-1], NULL, ThreadOne, (void*)(p)); 
pthread_create(&threads[ThrCount-2], NULL, ThreadTwo, (void*)(q)); 

  
// joining and waiting for all threads to complete 
for (int ii = 0; ii < MAX_THREAD; ii++) 
{ 
pthread_join(threads[ii], NULL);
} 

int stop_s = clock();
cout<<"Time Rquired to run the code is in msec"<<(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000<<endl;
return 0;
}
