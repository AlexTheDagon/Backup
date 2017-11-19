#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cool.in");
ofstream out("cool.out");
int caz,n,a[5005],minn,maxx,fr[1005],l,lmax,sem,dist,k,nrmax;
int main()
{
    in>>caz>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
    }
    if(caz==1)
    {
        minn=10000;
        maxx=0;
        for(int i=1;i<=k;++i)
        {
            if(fr[a[i]])sem=1;
            ++fr[a[i]];
            minn=min(minn,a[i]);
            maxx=max(maxx,a[i]);
        }
        if(sem==0 && maxx-minn==k-1)out<<maxx<<'\n';
        else
        {
            for(int i=1;i<=1002;++i)if(fr[i]==1)++dist;
            out<<dist<<'\n';
        }
    }
    else
    {
        for(int i=1;i<=n;++i)
        {
            minn=10000;
            maxx=0;
            sem=1;
            for(int j=i;j<=n && sem;++j)
            {
                if(fr[a[j]])sem=0;
                fr[a[j]]=1;
                minn=min(minn,a[j]);
                maxx=max(maxx,a[j]);
                if(maxx-minn==j-i && sem)
                {
                    if(j-i+1>lmax)
                    {
                        lmax=j-i+1;
                        nrmax=0;
                    }
                    if(lmax==j-i+1)++nrmax;
                }

            }
            for(int j=1;j<=1003;++j)fr[j]=0;
        }
        out<<lmax<<'\n'<<nrmax;
    }
    return 0;
}
