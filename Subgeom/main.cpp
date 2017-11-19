#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("subgeom.in");
ofstream out("subgeom.out");
int a[5005],smax[5005],n,t,l,lmax,act,ultind,pre,sem;
vector <int> fr[100005];
int main()
{
    in>>t;
    for(int teste=0;teste<t;++teste)
    {
        in>>n;
        for(int i=1;i<=n;++i)
        {
            in>>a[i];
            fr[a[i]].pb(i);
        }
        lmax=1;
        for(int k=2;k<=50;++k)
        {
            for(int i=1;i<=n;++i)
            {
                l=1;
                act=a[i]*k;
                pre=a[i];
                ultind=i;
                sem=1;
                while(fr[act].size() && pre<act && sem)
                {
                    sem=0;
                    for(int ind=0;ind<fr[act].size() && sem==0;++ind)
                    {
                        if(fr[act][ind]>ultind)
                        {
                            ultind=fr[act][ind];
                            sem=1;
                        }
                    }
                    if(sem)
                    {
                        ++l;
                        pre=act;
                        act=pre*k;
                    }
                }
                lmax=max(lmax,l);
            }
        }
        if(lmax<2)
        {
            for(int i=1;i<=n && lmax<2;++i)
            {
                for(int j=1;j<i;++j)
                {
                    if(a[i]%a[j]==0 && a[i]/a[j]>1)lmax=2;
                }
            }
        }
        out<<lmax<<'\n';
        for(int i=1;i<=n;++i)
        {
            fr[a[i]].clear();
        }
    }
    return 0;
}
