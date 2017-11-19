#include <iostream>
#include <bits/stdc++.h>
#define NM 1005
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int a[NM],c[NM],n,m,minn,poz,sol,ramas,pozitive;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)in>>c[i];
    for(int i=1;i<=m;++i)in>>a[i];
    for(int i=1;i<=m;++i)
    {
        minn=1000000000;
        for(int j=i;j<=m;++j)
        {
            if(a[j]<minn)
            {
                minn=a[j];
                poz=j;
            }
        }
        swap(a[i],a[poz]);
    }
    for(int i=1;i<=n;++i)
    {
        minn=1000000000;
        for(int j=i;j<=n;++j)
        {
            if(c[j]<minn)
            {
                minn=c[j];
                poz=j;
            }
        }
        swap(c[i],c[poz]);
    }
    for(int i=1;i<=n;++i)
        if(c[i]>0)++pozitive;
    for(int i=1;i<=n-pozitive;++i)
    {
        out<<c[i]<<" "<<a[i]<<'\n';
        sol+=c[i]*a[i];
    }
    for(int i=n-pozitive+1;i<=n;++i)
    {
        out<<c[i]<<" "<<a[i+(m-n)]<<'\n';
        sol+=c[i]*a[i+(m-n)];
    }
    out<<sol;
    return 0;
}
