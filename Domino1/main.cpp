#include <iostream>
#include <fstream>
#define f first
#define s second
#include <algorithm>
using namespace std;
ifstream in("domino1.in");
ofstream out("domino1.out");
int n,k1,k2,pozprim,elim[10005],sem;
pair <pair <int,int>,int> p[10005];
pair <int,int> pmax;
int main()
{
    in>>n>>k1>>k2;
    for(int i=1;i<=n;++i)
    {
        in>>p[i].f.f>>p[i].f.s;
        p[i].s=i;
    }
    if(k1==0)
    {
        pmax.f=p[1].f.f;
        pmax.s=p[1].f.s;
        pozprim=1;
        for(int i=1;i<=k2;++i)
        {
            if(p[i].f.f>pmax.f || (pmax.f==p[i].f.f && p[i].f.s>pmax.s))
            {
                pmax.f=p[i].f.f;
                pmax.s=p[i].f.s;
                pozprim=i;
            }
        }
        k2=k2-pozprim+1;
        out<<p[pozprim].f.f<<p[pozprim].f.s;
        sort(p+pozprim+1,p+n+1);
        for(int i=pozprim+1;i<=pozprim+k2;++i)elim[p[i].s]=1;
        for(int i=pozprim+1;i<=n;++i)swap(p[i].f.f,p[i].s);
        sort(p+pozprim+1,p+n+1);
        for(int i=pozprim+1;i<=n;++i)if(elim[p[i].f.f]==0)out<<p[i].s<<p[i].f.s;
    }
    else
    {
        pmax.f=p[1].f.f;
        pmax.s=p[1].f.s;
        pozprim=1;
        for(int i=1;i<=k2;++i)
        {
            if(p[i].f.f>pmax.f || (pmax.f==p[i].f.f && p[i].f.s>pmax.s))
            {
                pmax.f=p[i].f.f;
                pmax.s=p[i].f.s;
                pozprim=i;
            }
            else
            {
                if(p[i].f.s>pmax.f || (pmax.f==p[i].f.s && p[i].f.f>pmax.s))
                {
                    pmax.s=p[i].f.f;
                    pmax.f=p[i].f.s;
                    pozprim=i;
                    sem=1;
                }
            }
        }
        k2=k2-pozprim+1;
        k1=k1-sem;
        out<<pmax.f<<pmax.s;
        for(int i=pozprim+1;i<=n;++i)swap(p[i].f.f,p[i].f.s);
        sort(p+pozprim+1,p+n+1);
        for(int i=n;i>=pozprim+1 && k1>0;--i)
        {
            if(p[i].f.f>p[i].f.s)
            {
                swap(p[i].f.f,p[i].f.s);
                k1--;
            }
        }
        for(int i=pozprim+1;i<=n;++i)swap(p[i].f.f,p[i].f.s);
        ///ok
        sort(p+pozprim+1,p+n+1);
        for(int i=pozprim+1;i<=pozprim+k2;++i)elim[p[i].s]=1;
        for(int i=pozprim+1;i<=n;++i)swap(p[i].f.f,p[i].s);
        sort(p+pozprim+1,p+n+1);
        for(int i=pozprim+1;i<=n;++i)
        {
            if(elim[p[i].f.f]==0)
            {
                out<<p[i].s<<p[i].f.s;
            }

        }

    }

    return 0;
}
