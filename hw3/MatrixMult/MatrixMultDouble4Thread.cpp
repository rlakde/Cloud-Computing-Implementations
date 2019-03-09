#include<iostream>
#include<cstdlib>
#include<ctime>
#include<pthread.h>
using namespace std;

static double matrx1[16384][16384], matrx2[16384][16384], mult[16384][16384] = {0.000000};
int nrow = 16384;
int count = 0;
#define MAX_THREAD 4 

double GeneRandom(int k)
{
	srand(k);
    return ((double)rand())/RAND_MAX * 2.0 - 1.0;
}

void* multply(void* arg) 
{ 
int core = count++;
for(int l = core * nrow/4; l < (core+1)*nrow/4; l++)
{
        for(int m = 0; m < nrow; m++)
	{
            for(int o = 0; o < nrow; o++)
            {
             mult[l][m] += matrx1[l][o] * matrx2[o][m];
            }
	}
}} 

int main()
{

int k;
//cout<<"Enter the number of rows in given square matrices"<<endl;
//cin>>nrow;

for(int i=0;i<nrow;i++)
{
		for(int j=0;j<nrow;j++)
		{	k = k + 10;
			matrx1[i][j] = GeneRandom(k);
			k = k + 10;
			matrx2[i][j] = GeneRandom(k);
		}
}
int start_s = clock();
// declaring four threads 
pthread_t threads[MAX_THREAD]; 
  
// Creating four threads, each evaluating its own part 
for (int i = 0; i < MAX_THREAD; i++) 
{ 
 int* p; 
 pthread_create(&threads[i], NULL, multply, (void*)(p)); 
} 
  
// joining and waiting for all threads to complete 
for (int i = 0; i < MAX_THREAD; i++) 
{ 
pthread_join(threads[i], NULL);
} 

int stop_s = clock();
cout<<"Time Rquired to run the code is "<<(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000<<"msec"<<endl;
return 0;
}
