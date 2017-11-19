#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lift.in");
ofstream out("lift.out");
long long t[100],q,nr,s,sem,ind,n,inv,saux;
bool v[100];
int main()
{
    t[1]=t[2]=1;
    in>>n;
    for(int i=3;i<=80;++i)t[i]=t[i-2]+t[i-1];
    for(int i=1;i<=n;++i)
    {
        in>>nr;
        inv=0;
        if(nr<0)
        {
            inv=1;
            nr*=-1;
        }
        s=0;
        sem=0;
        for(ind=1;sem==0;++ind)
        {
            s+=t[ind];
            v[ind]=1;
            if(s>=nr)
            {
                saux=s;
                    for(int j=ind;j>0 && saux>nr;--j)
                    {
                        if(saux-2*t[j]>=nr)
                        {
                            v[j]=0;
                            saux-=2*t[j];
                        }
                    }
                if(saux==nr)sem=1;
                else
                {
                    for(int j=1;j<=ind;++j)v[j]=1;
                }
            }
        }
        out<<ind-1<<" ";
        if(inv==0)
        {
            for(int j=1;j<ind;++j)
            {
                if(!v[j])out<<"-";
                else out<<"+";
                v[j]=0;
            }
        }
        else
        {
            for(int j=1;j<ind;++j)
            {
                if(v[j])out<<"-";
                else out<<"+";
                v[j]=0;
            }
        }
        out<<'\n';

    }
    return 0;
}
