#include <iostream>
#include <fstream>
using namespace std;
ifstream in("petrecere.in");
ofstream out("petrecere.out");
int nr[5][3005],n,st;
void mult(int ii,int B)
{
    int i,t=0;
    for(i=1;i<=nr[ii][0] || t;++i,t/=10)
    {
        nr[ii][i]=(t+=nr[ii][i]*B)%10;
    }
    nr[ii][0]=i-1;
}
void add(int ii,int jj,int kk)
{
    int i,t=0;
    for(i=1;i<=nr[ii][0] || i<=nr[jj][0] || t;++i,t/=10)
    {
        nr[kk][i]=(t+=nr[ii][i]+nr[jj][i])%10;
    }
    nr[kk][0]=i-1;
}
int main()
{
    in>>n;
    nr[1][1]=nr[1][0]=nr[2][0]=1;
    nr[2][1]=2;
    for(int i=3;i<=n;++i)
    {
        mult(1,i-1);
        add(1,2,3);
        st=max(nr[2][0],nr[1][0]);
        for(int j=st+1;j>=0;--j)nr[1][j]=nr[2][j];
        st=max(nr[3][0],nr[2][0]);
        for(int j=st+1;j>=0;--j)nr[2][j]=nr[3][j];
    }
    for(int i=nr[2][0];i>0;--i)out<<nr[2][i];
    return 0;
}
