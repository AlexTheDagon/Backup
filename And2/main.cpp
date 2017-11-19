#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#define nmax 100000
using namespace std;
ifstream in("and2.in");
ofstream out("and2.out");
int gen(int a,int b)
{
	return a+rand()%(b-a+1);
}

int n,a[100000],k,maxim,nr;
int main()
{
	srand(time(0));
	int n=rand()%nmax+1;
	for(int i=0;i<n;i++)
    {
        a[i]=gen(0,10000000);
        out<<a[i]<<" ";
    }

for(int i=0;i<n;i++)
{
    nr=a[i];
    k=0;
    for(int j=i;(nr & a[j])!=0;j++)
    {
        nr=nr & a[j];
        k++;
    }
    if(k>maxim)maxim=k;
}
out<<'\n';
out<<maxim;
    return 0;
}
