#include <iostream>
#include <fstream>
using namespace std;
ifstream in("roata.in");
ofstream out("roata.out");
long long n,p,c,a[361],ordine[361],k,i,poz,x,ultimul;
long long s,b[100005],minn;
int main()
{in>>n>>p;
for(i=1;i<=n;i++)
{
    in>>a[i];
    s=s+a[i];
    ordine[i]=i;
}
for(k=n+1;k<=p;k++)
{
    minn=100000000000;
    in>>c;
    s=s+c;
    for(i=1;i<=n;i++)
    {
        if(a[i]<minn)
        {
            minn=a[i];
            poz=i;
        }
    }
    a[poz]+=c;
    b[x]=ordine[poz];
    ordine[poz]=k;
    x++;
}
for(int j=0;j<n;j++)
{
    minn=100000000000;
    for(i=1;i<=n;i++)
    {
        if(a[i]<minn && a[i]!=0)
        {
            minn=a[i];
            poz=i;
        }
    }
    a[poz]=0;
    b[x]=ordine[poz];
    x++;
}
out<<s<<'\n';
for(int i=0;i<p;i++)out<<b[i]<<" ";
out<<'\n';
out<<poz;


    return 0;
}
