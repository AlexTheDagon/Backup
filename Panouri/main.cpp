#include <iostream>
#include <fstream>
#define T 20005
#define N 200005
using namespace std;
ifstream in("panouri.in");
ofstream out("panouri.out");
int n,t,p[T],a[N],fr[T],x,ramas,st,dr,minn=1000000;
int main()
{
    in>>n>>t;
    for(int i=1;i<=n;++i)in>>a[i];
    for(int i=1;i<=t;++i)
    {
        in>>x;
        p[x]=1;
    }
    ramas=t;
    while(dr<n)
    {
        ++dr;
        if(p[a[dr]])
        {
            ++fr[a[dr]];
            if(fr[a[dr]]==1)ramas--;
        }
        if(ramas==0)
        {
            while(ramas==0)
            {
                --fr[a[st]];
                if(!fr[a[st]] && p[a[st]])++ramas;
                ++st;
            }
            minn=min(minn,dr-st+1);
        }
    }
    out<<minn;
    return 0;
}
