#include <iostream>
#include <fstream>
using namespace std;
ifstream in("echilibru.in");
ofstream out("echilibru.out");
int fol[20],a[20],t,n,s,sum,sem=0,nr,x;
void comb(int p)
{
    if(p==n+1)
    {
        if(s==sum/2)sem=1;
    }
    else
    {
        if(sem==0)
        {
            for(int i=1;i<=2*n;++i)
            {
                if(fol[i]==0)
                {
                    fol[i]=1;
                    s+=a[i];
                    comb(p+1);
                    s-=a[i];
                    fol[i]=0;
                }
            }
        }
    }
}
int main()
{
    in>>t;
    for(int i=1;i<=t;++i)
    {
        sem=0;
        sum=0;
        s=0;
        in>>n;
        for(int j=1;j<=2*n;++j)
        {
            in>>a[j];
            sum+=a[j];
        }
        if(sum%2==0)
        {
            comb(1);
        }
        if(sem)
        {
            x=1<<(t-i);
            nr+=x;
        }
    }
    out<<nr;
    return 0;
}
