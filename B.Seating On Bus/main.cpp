#include <iostream>

using namespace std;
int lc[101],lw[101],rc[101],rw[101],n,mpr,p=1,k=1,m;
int main()
{
    cin>>n>>m;
    if(m<=2*n)
    {
        for(int i=1;i<=m;i++)
        {
            cout<<i<<" ";
        }
    }
    else
    {
        mpr=m-2*n;
        for(int i=1;i<=n;++i)
        {
            lw[i]=p;
            p=p+2;
        }
        p=2;
        for(int i=1;i<=n;++i)
        {
            rw[i]=p;
            p=p+2;
        }
        p=2*n+1;
        for(int i=1;i<=(mpr+1)/2;++i)
        {
            lc[i]=p;
            p=p+2;
        }
        p=2*n+2;
        for(int i=1;i<=mpr/2;++i)
        {
            rc[i]=p;
            p=p+2;
        }
        p=1;
        while(k<=m)
        {
            if(lc[p]!=0)
            {
                cout<<lc[p]<<" ";
                ++k;
            }
            if(k>m)break;
            cout<<lw[p]<<" ";
            ++k;
            if(k>m)break;
            if(rc[p]!=0)
            {
                cout<<rc[p]<<" ";
                ++k;
            }
            if(k>m)break;
            cout<<rw[p]<<" ";
            ++k;
            if(k>m)break;
            ++p;
        }
    }
    return 0;
}
