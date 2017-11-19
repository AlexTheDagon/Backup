#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
ifstream in("placare.in");
ofstream out("placare.out");

int a[305],r[305],nr,n,m,jj,ii,ind,sem;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        jj=1;
        sem=1;
        while(r[jj]>0 && jj<=m)++jj;
        while(jj<=m)
        {
            sem=0;
            while(r[jj]>0 && jj<=m)++jj;
            if(jj<=m)
            {
                in>>nr;
                if(nr>0)
                {
                    for(int j=jj;j<jj+nr;++j)
                    {
                        a[j]=nr;
                        r[j]=1;
                    }
                    jj=jj+nr;
                }
                else
                {
                    a[jj]=abs(nr);
                    r[jj]=abs(nr);
                    ++jj;
                }
            }
        }
        if(sem)in>>nr;
        for(int j=1;j<=m;++j)
        {
            out<<a[j]<<" ";
            --r[j];
        }
        out<<'\n';
    }
    return 0;
}
