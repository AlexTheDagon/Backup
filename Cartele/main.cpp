#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cartele.in");
ofstream out("cartele.out");
int n,c,a[55][55],model[55][55],sem,verif;
int main()
{
    in>>n>>c;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)in>>model[i][j];
    for(int teste=1;teste<=c;++teste)
    {
        verif=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)in>>a[i][j];
        ///verificarea:
        sem=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]!=model[i][j])sem=0;
            }
        }
        if(sem)verif=1;
        sem=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]!=model[n+1-j][i])sem=0;
            }
        }
        if(sem)verif=1;
        sem=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]!=model[n+1-i][n+1-j])sem=0;
            }
        }
        if(sem)verif=1;
        sem=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]!=model[j][n+1-i])sem=0;
            }
        }
        if(sem)verif=1;
        sem=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]!=model[j][i])sem=0;
            }
        }
        if(sem)verif=1;
        sem=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]!=model[i][n+1-j])sem=0;
            }
        }
        if(sem)verif=1;
        sem=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]!=model[n+1-j][n+1-i])sem=0;
            }
        }
        if(sem)verif=1;
        sem=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]!=model[n+1-i][j])sem=0;
            }
        }
        if(sem)verif=1;
        out<<verif<<'\n';
    }
    return 0;
}
