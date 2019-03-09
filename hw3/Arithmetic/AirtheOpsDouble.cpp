#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

int main()
{
unsigned long long int i;
double j = 1.00000001,k=1.0000001,l=1.1000001,m=1.0000010;
int start_s = clock();
//i<125000000000	
for(i=0;i<125000000000;i++)
{
j = j + 0.0000001;
j = j * 1.0000000;
j = j - 0.0000001;
k = k + 1.0000001;
k = k - 1.0000001;	
l = l * 1.0000000;
m = m * 1.0000000;	
}
int stop_s = clock();
cout<<"Time Rquired to run the code is in msec"<<(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000<<endl;
return 0;
}
