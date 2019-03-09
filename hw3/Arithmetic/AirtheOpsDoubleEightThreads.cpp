#include<iostream>
#include<cstdlib>
#include<ctime>
#include<pthread.h>
using namespace std;

double j = 1.01,k=1.01,l=1.11,m=1.10;
double c = 1.01,d=1.01,e=1.11,f=1.10;
double jj = 1.01,kk=1.01,ll=1.11,mm=1.10;
double cc = 1.01,dd=1.01,ee=1.11,ff=1.10;
double aj = 1.01,ak=1.01,al=1.11,am=1.10;
double ac = 1.01,ad=1.01,ae=1.11,af=1.10;
double ajj = 1.01,akk=1.01,all=1.11,amm=1.10;
double acc = 1.01,add=1.01,aee=1.11,aff=1.10;

#define MAX_THREAD 8 

//limit equals to 15625000000
unsigned long int limit = 15625000000;

void* ThreadOne(void* arg) 
{ 
	for(unsigned long int a=0;a<limit;a++)
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
	for(unsigned long int b=0;b<limit;b++)
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

void* ThreadThree(void* arg) 
{ 

	for(unsigned long int aa=0;aa<limit;aa++)
	{
	jj = jj + 0.1;
	jj = jj * 1.00;
	jj = jj - 0.1;
	kk = kk + 1.00;
	kk = kk - 1.00;
	ll = ll * 1.00;
	mm = mm * 1.00;		
	}
}

void* ThreadFour(void* arg) 
{ 
	for(unsigned long int bb=0;bb<limit;bb++)
	{
	cc = cc + 0.1;
	cc = cc * 1.00;
	cc = cc - 0.1;
	dd = dd + 1.00;
	dd = dd - 1.00;
	ee = ee * 1.00;
	ff = ff * 1.00;		
	}

}


void* ThreadFive(void* arg) 
{ 
	for(unsigned long int aaa=0;aaa<limit;aaa++)
	{
	aj = aj + 0.1;
	aj = aj * 1.00;
	aj = aj - 0.1;
	ak = ak + 1.00;
	ak = ak - 1.00;
	al = al * 1.00;
	am = am * 1.00;		
	}
}

void* ThreadSix(void* arg) 
{ 
	for(unsigned long int bbb=0;bbb<limit;bbb++)
	{
	ac = ac + 0.1;
	ac = ac * 1.00;
	ac = ac - 0.1;
	ad = ad + 1.00;
	ad = ad - 1.00;
	ae = ae * 1.00;
	af = af * 1.00;		
	}

}

void* ThreadSeven(void* arg) 
{ 

	for(unsigned long int as=0;as<limit;as++)
	{
	ajj = ajj + 0.1;
	ajj = ajj * 1.00;
	ajj = ajj - 0.1;
	akk = akk + 1.00;
	akk = akk - 1.00;	
	all = all * 1.00;
	amm = amm * 1.00;		
	}
}

void* ThreadEight(void* arg) 
{ 
	for(unsigned long int bs=0;bs<limit;bs++)
	{
	acc = acc + 0.1;
	acc = acc * 1.00;
	acc = acc - 0.1;
	add = add + 1.00;
	add = add - 1.00;
	aee = aee * 1.00;
	aff = aff * 1.00;		
	}

}


int main()
{
pthread_t threads[MAX_THREAD]; 
int* p;
int* q; 
int* r;
int* s;
int* t;
int* u; 
int* v;
int* w;  
int ThrCount = MAX_THREAD;
int start_s = clock();
pthread_create(&threads[ThrCount-1], NULL, ThreadOne, (void*)(p)); 
pthread_create(&threads[ThrCount-2], NULL, ThreadTwo, (void*)(q)); 
pthread_create(&threads[ThrCount-3], NULL, ThreadThree, (void*)(r)); 
pthread_create(&threads[ThrCount-4], NULL, ThreadFour, (void*)(s)); 
pthread_create(&threads[ThrCount-5], NULL, ThreadFive, (void*)(t)); 
pthread_create(&threads[ThrCount-6], NULL, ThreadSix, (void*)(u)); 
pthread_create(&threads[ThrCount-7], NULL, ThreadSeven, (void*)(v)); 
pthread_create(&threads[ThrCount-8], NULL, ThreadEight, (void*)(w)); 

  
// joining and waiting for all threads to complete 
for (int ii = 0; ii < MAX_THREAD; ii++) 
{ 
pthread_join(threads[ii], NULL);
} 

int stop_s = clock();
cout<<"Time Rquired to run the code is in msec"<<(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000<<endl;
return 0;
}
