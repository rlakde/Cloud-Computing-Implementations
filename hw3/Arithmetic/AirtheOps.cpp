#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
unsigned long long int i;
float j = 1.01,k=1.01,l=1.11,m=1.10;
int start_s = clock();
//i<125000000000	
for(i=0;i<125000000000;i++)
{
j = j + 0.1;
j = j - 0.1;
k = k + 1.00;
k = k - 1.00;
k = k * 1.00;	
l = l * 1.00;
m = m * 1.00;	
}
int stop_s = clock();
cout<<"Time Rquired to run the code is in msec"<<(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000<<endl;
return 0;
}
