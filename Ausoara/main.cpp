#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ausoara.in");
ofstream out("ausoara.out");
int n,m[101],a[101][1010],ind[101],maxx,nr,sol[1002],poz=0,sem,stop=1;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>m[i];
        ind[i]=1;
        for(int j=1;j<=m[i];++j)in>>a[i][j];
    }
    while(stop)
    {
        sem=1;
        for(int i=1;i<=n;++i)maxx=max(maxx,a[i][ind[i]]);///bine
        for(int i=1;i<=n;++i)
        {
            for(int j=ind[i];a[i][j]<maxx && j<=m[i]+1;++j)ind[i]=j;
            if(a[i][ind[i]]<maxx)++ind[i];
            if(a[i][ind[i]]==0)stop=0;
            if(maxx!=a[i][ind[i]])sem=0;
        }
        if(sem==1)
        {
            sol[++poz]=maxx;
            for(int i=1;i<=n;++i)ind[i]++;
        }
    }
    out<<poz;
    for(int i=1;i<=poz;++i)out<<" "<<sol[i];
    return 0;
}
