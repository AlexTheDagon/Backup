#include <iostream>
#include <fstream>
using namespace std;
ifstream in("culori3.in");
ofstream out("culori3.out");
int cur[7][1000],p[7][1000],cifc[7],cifp[7],n,nr[1000],cifnr,s,ad;
int main()
{
    in>>n;
    for(int i=1;i<=5;++i)
    {
        cifc[i]=1;
        cur[i][1]=1;
    }
    for(int k=2;k<=n;++k)
    {
        for(int i=1;i<=5;++i)
        {
            cifp[i]=cifc[i];
            for(int j=1;j<=cifc[i];++j)
            {
                p[i][j]=cur[i][j];
                cur[i][j]=0;
            }
        }///bine
        for(int i=1;i<=5;++i)
        {
            cifc[i]=max(cifp[i-1],cifp[i+1]);
            for(int j=1;j<=cifc[i];++j)
            {
                cur[i][j]=cur[i][j]+p[i-1][j]+p[i+1][j];
                if(cur[i][j]>9)
                {
                    cur[i][j+1]=cur[i][j]/10;
                    cur[i][j]=cur[i][j]%10;
                }
            }
            if(cur[i][cifc[i]+1]!=0)cifc[i]++;
        }
    }
    for(int i=1;i<=5;++i)cifnr=max(cifnr,cifc[i]);
    for(int i=1;i<=cifnr;++i)
    {
        for(int j=1;j<=5;++j)
        {
            nr[i]+=cur[j][i];
        }
        if(nr[i]>9)
        {
            nr[i+1]=nr[i]/10;
            nr[i]=nr[i]%10;
        }
    }
    if(nr[cifnr+1]!=0)++cifnr;
    for(int i=cifnr;i>0;--i)out<<nr[i];
    return 0;
}
