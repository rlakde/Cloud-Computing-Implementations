#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

double GeneRandom(int k)
{
    srand(k);
    return ((double)rand())/RAND_MAX * 2.0 - 1.0;
}

int main()
{

int k,nrow;
//cout<<"Enter the number of rows in given square matrices"<<endl;
//cin>>nrow;
nrow = 16384;
static double matrx1[16384][16384], matrx2[16384][16384], mult[16384][16384] = {0.00000000};
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
for(int l = 0; l < nrow; ++l)
{
        for(int m = 0; m < nrow; ++m)
		{
            for(int o = 0; o < nrow; ++o)
            {
                mult[l][m] += matrx1[l][o] * matrx2[o][m];
            }
		}
}
int stop_s = clock();
cout<<"Time Rquired to run the code is in msec"<<(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000<<endl;
return 0;
}
