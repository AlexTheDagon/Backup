#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int a[10000],b[10000],x[10000];
int main()
{
    int n,na=1,nb=0;
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>x[i];
    int pr=2;
    a[1]=x[1];
    while(x[pr]>x[pr-1])
    {
        na++;
        a[na]=x[pr];
        pr++;
    }
    for(int j=pr;j<=n;j++)
    {
        nb++;
        b[nb]=x[j];
    }
    for(int i=1;i<=na;i++)
    {
        nb++;
        b[nb]=a[i];
    }
    int element;
    fin>>element;
    int st=1,dr=nb;
    while(st<=dr)
    {
        int mij=(st+dr)/2;
        if(b[mij]==element)
        {
            fout<<mij;
            st=dr+1
        }
        else if(b[mij]>element) dr=mij-1;
        else if(b[mij]<element) st=mij+1
    }
    return 0;
}
