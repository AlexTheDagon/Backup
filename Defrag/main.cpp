#include <iostream>
#include <fstream>
using namespace std;
ifstream in("defrag.in");
ofstream out("defrag.out");
int m[105][365];
int v,q,p,s,c,fr,a,b,k,maxx;
int main()
{
    in>>v;
    in>>p>>s;
    in>>c;
    for(int i=1;i<=c;++i)
    {
        in>>a>>b;
        m[a][b]=1;
    }
    for(int i=1;i<=p;++i)
    {
        fr=0;
        for(int j=1;j<=s;++j)if(m[i][j]==1)++fr;
        m[i][0]=fr;
    }
    if(v==1)
    {
        fr=0;
        for(int i=1;i<=p;++i)
        {
            if(m[i][0]==0)
            fr++;
        }
        out<<fr;
    }
    else
    {
        for(int i=1;i<=p;++i)
        {
            k=m[i][0];
            maxx=0;
            if(k!=0)
            {
                for(int t=1;t<=s-k+1;++t)
                {
                    fr=0;
                    for(int j=t;j<=t+k-1;++j)if(m[i][j]==1)++fr;
                    if(fr>maxx)maxx=fr;
                }
                q=0;
                for(int t=s-k+2;t<=s;++t)
                {
                    fr=0;
                    for(int j=t;j<=s;++j)if(m[i][j]==1)++fr;
                    ++q;
                    for(int j=1;j<=q;++j)if(m[i][j]==1)++fr;
                    if(fr>maxx)maxx=fr;
                }
                out<<k-maxx<<" ";
            }
            else out<<"0 ";
        }
    }
    return 0;
}
