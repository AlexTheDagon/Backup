#include <iostream>
#include <fstream>
#define NM 5005
#define inf 1e9
using namespace std;
ifstream in("split.in");
ofstream out("split.out");
int maxs[NM],maxd[NM],mins[NM],mind[NM],a[NM],n,ii,jj,kk,minn,maxx,sol,i1,k1,s1,s2;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    maxs[1]=mins[1]=a[1];
    maxd[n]=mind[n]=a[n];
    for(int i=2;i<=n;++i)
    {
        mins[i]=min(mins[i-1],a[i]);
        maxs[i]=max(maxs[i-1],a[i]);
    }
    for(int i=n-1;i>0;--i)
    {
        mind[i]=min(mind[i+1],a[i]);
        maxd[i]=max(maxd[i+1],a[i]);
    }
    ///bine
    for(int j=4;j<=n-4;++j)
    {
        s1=0;
        minn=min(a[j-1],a[j]);
        maxx=max(a[j-1],a[j]);
        for(int i=j-1;i>2;--i)
        {
            minn=min(minn,a[i]);
            maxx=max(maxx,a[i]);
            if(maxx-minn+maxs[i-1]-mins[i-1]>=s1)
            {
                s1=maxx-minn+maxs[i-1]-mins[i-1];
                i1=i-1;
            }
        }
        ///ar tb sa fie bine
        s2=0;
        minn=min(a[j+1],a[j+2]);
        maxx=max(a[j+1],a[j+2]);
        for(int k=j+2;k<n-1;++k)
        {
            minn=min(minn,a[k]);
            maxx=max(maxx,a[k]);
            if(maxx-minn+maxd[k+1]-mind[k+1]>s2)
            {
                s2=maxx-minn+maxd[k+1]-mind[k+1];
                k1=k;
            }
        }
        if(s1+s2>sol)
        {
            sol=s1+s2;
            ii=i1;
            jj=j;
            kk=k1;
        }
    }
    out<<sol<<'\n'<<ii<<" "<<jj<<" "<<kk;
    return 0;
}
