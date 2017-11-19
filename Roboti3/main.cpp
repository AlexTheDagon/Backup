#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
using namespace std;
ifstream in("roboti3.in");
ofstream out("roboti3.out");
int a[200005],ult,l,lmax,x,n,caz,val[1005],fr[1005],minn=100000,maxx,act,sem,stop,nr,aux;
deque <int> d;
int main()
{
    in>>caz;
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        a[i+n]=a[i];
        minn=min(minn,a[i]);
        maxx=max(maxx,a[i]);
        ++fr[a[i]];
    }
    if(caz==1)
    {
        for(int i=1;i<=2*n;++i)
        {
            if(a[i]>ult)
            {
                ++l;
                ult=a[i];
            }
            else
            {
                l=1;
                ult=a[i];
            }
            lmax=max(l,lmax);
        }
        out<<lmax<<'\n';
    }
    else
    {
        act=maxx;
        for(int i=1;i<=fr[act];++i)d.push_back(act);
        --act;
        while(act>minn)
        {
            if(fr[act]>1)
            {
                d.push_back(act);
                for(int i=1;i<fr[act];++i)d.push_front(act);
            }
            else
            {
                if(fr[act]==1)
                {
                    if(d.front()>d.back())d.push_front(act);
                    else
                    {
                        if(d.front()<d.back())d.push_back(act);
                        else
                        {
                            aux=act;
                            nr=0;
                            while(fr[aux]==1 && aux>minn)
                            {
                                --aux;
                                ++nr;
                            }
                            if(nr%2==0)d.push_back(act);
                            else d.push_front(act);
                        }
                    }
                }
            }
            --act;
        }
        for(int i=1;i<=fr[minn];++i)d.push_front(minn);
        while(!d.empty())
        {
            out<<d.front()<<" ";
            d.pop_front();
        }
    }
    return 0;

}
