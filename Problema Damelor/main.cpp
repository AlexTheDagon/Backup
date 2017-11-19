#include <iostream>
#include <fstream>
using namespace std;
ifstream in("damesah.in");
ofstream out("damesah.out");
int a[100][100],n,c[100],l[100],d=0,sem=0,m,dgs[100],dgd[100];
void bk(int i,int j)
{
    if(i>n && d==n)
    {
        m++;
        return;
    }
    if(i>n)return;
    if(j>n)return;
    if(c[j]==0 && l[i]==0 && dgs[2*n-j+i]==0 && dgd[i+j]==0)
    {
        c[j]=1;
        dgs[2*n-j+i]=1;
        dgd[i+j]=1;
        d++;
        bk(i+1,1);
        d--;
        dgd[i+j]=0;
        dgs[2*n-j+i]=0;
        c[j]=0;
    }
    bk(i,j+1);
}
void afis(int i,int j)
{
    if(sem==1)return;
    if(i>n && d==n)
    {
        for(int l=1;l<=n;++l)
            for(int k=1;k<=n;++k)if(a[l][k]==1)out<<k<<" ";
        out<<'\n';
        sem=1;
        return;
    }
    if(i>n)return;
    if(j>n)return;
    if(c[j]==0 && l[i]==0 && dgs[2*n-j+i]==0 && dgd[i+j]==0)
    {
        c[j]=a[i][j]=1;
        dgs[2*n-j+i]=1;
        dgd[i+j]=1;
        d++;
        afis(i+1,1);
        d--;
        dgd[i+j]=0;
        dgs[2*n-j+i]=0;
        c[j]=a[i][j]=0;
    }
    afis(i,j+1);
}
int main()
{
    in>>n;
    afis(1,1);
    for(int i=1;i<=n;++i)l[i]=c[i]=0;
    d=0;
    bk(1,1);
    out<<m;
    return 0;
}
