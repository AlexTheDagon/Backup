#include <iostream>
#include <fstream>
using namespace std;
ifstream in("numar4.in");
ofstream out("numar4.out");
int nz,ni,a[2005],num[2005],numi[2005];
void divide(int A[],int B)
{
      int i,t=0;
      for (i=A[0];i>0;i--,t%=B)A[i]=(t=t*10+A[i])/B;
      while(!A[A[0]])--A[0];
}
int main()
{
    in>>ni>>nz;
    for(int i=ni+nz;i>0;--i)in>>a[i];
    if(a[ni+nz]==0)--ni;
    a[0]=ni+nz;
    numi[nz+1]=1;
    numi[0]=nz+1;
    while(a[1]%2==0 && numi[1]%2==0)
    {
        divide(a,2);
        divide(numi,2);
    }
    while(a[1]%5==0 && numi[1]%5==0)
    {
        divide(a,5);
        divide(numi,5);
    }
    out<<a[0]<<'\n';
    for(int i=a[0];i>0;--i)out<<a[i];
    out<<'\n';
    out<<numi[0]<<'\n';
    for(int i=numi[0];i>0;--i)out<<numi[i];
    out<<'\n';
    return 0;
}
