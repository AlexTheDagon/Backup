#include <iostream>
#include <fstream>
using namespace std;
ifstream in("interesant.in");
ofstream out("interesant.out");
int n,v,x[201],l,lmax,nr;
char a[201][5001],c[201];
int main()
{
    in>>v>>n;
    for(int i=1;i<=n;++i)
    {
        in>>c;
        l=0;
        for(int j=1;c[j-1]!=(char)0;++j)
        {
            a[i][j]=c[j-1];
            ++l;
        }
        x[i]=l;
        lmax=max(l,lmax);
    }
    if(v==1)
    {
        for(int i=1;i<=n;++i)
        {
            if(x[i]!=lmax)x[i]=0;
            else
            {
                if(v==0)
                {
                    v=i;
                    x[i]=0;
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(x[i]==lmax)
            {
                for(int j=1;j<=lmax;++j)
                {
                    if(a[v][j]>a[i][j])
                    {
                        v=i;
                    }
                }
            }
        }
        for(int i=1;i<=lmax;++i)out<<a[v][i];
    }
    else
    {
        for(int i=1;i<=n;++i)x[i]=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i!=j && x[j]==1)
                {
                    l=1;
                    for(int k=1;a[j][k]!=(char)0;++k)
                    {
                        if(a[i][l]==a[j][k])++l;
                    }
                    if(a[i][l]==(char)0)x[i]=0;
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(x[i]==1)++nr;
        }
        out<<nr<<'\n';
        for(int i=1;i<=n;++i)
        {
            if(x[i]==1)
            {
                for(int j=1;a[i][j]!=(char)0;++j)out<<a[i][j];
                out<<'\n';
            }
        }
    }
    return 0;
}
