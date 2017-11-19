#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int cmmdc(int a,int b)
{
    while(a!=b)
    {
        if(a>b)b-=a;
        else a-=b;
    }
    return a;
}
int lst=2;
int poz[1000001],first[1000001],n,x;
int main()
{
    in>>n;
    poz[1]=1;
    poz[2]=2;
    for(int i=3;i<100;++i)
    {
        for(int j=3;j<=100;++j)
        {
            if(!poz[j] && cmmdc(lst,j)!=1)break;
            poz[j]=i;
            lst=j;
        }
    }
    for(int i=0;i<10;i++)out<<poz[i]<<" ";
    return 0;
}
