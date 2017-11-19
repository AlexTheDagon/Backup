#include <iostream>
#include <fstream>
#include <algorithm>
#define x first
#define y second
#define mp make_pair
using namespace std;
ifstream in("coach.in");
ofstream out("coach.out");
int n,m,t,d[105][105],dmin[105][105],cost,nnod[105],a,b,c[105],st,fin,solmax,solmin,sem=0,ind[105],maxx[105][105];
pair <int,int> nod[105];
int cmin,cmax;
int main()
{
    in>>n>>m>>t;
    for(int i=1;i<=n;++i)
    {
        in>>cost;
        c[i]=cost;
        nod[i]=mp(cost,i);
    }
    sort(nod+1,nod+n+1);
    for(int i=1;i<=n;++i)
    {
        ind[nod[i].y]=i;
    }
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>cost;
        d[ind[a]][ind[b]]=cost;
        d[ind[b]][ind[a]]=cost;
    }
    ///bine
    for(int ic=1;ic<=n && sem==0;++ic)
    {
        cmin=nod[ic].x;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                maxx[i][j]=max(nod[i].x,nod[j].x);
                if(nod[i].x>=cmin && nod[j].x>=cmin)dmin[i][j]=d[i][j];
                else dmin[i][j]=0;
            }
        }
        for(int k=ic;k<=n && sem==0;++k)
        {
            for(int i=ic;i<=n && sem==0;++i)
            {
                for(int j=ic;j<=n && sem==0;++j)
                {
                    if(i!=j)
                    {
                        if(dmin[i][k] && dmin[k][j] &&(dmin[i][j]>dmin[i][k]+dmin[k][j] || dmin[i][j]==0))
                        {
                            dmin[i][j]=dmin[i][k]+dmin[k][j];
                            maxx[i][j]=max(maxx[i][k],maxx[k][j]);
                        }
                        if(dmin[i][j]==t)
                        {
                            solmin=cmin;
                            solmax=maxx[i][j];
                            st=i;
                            fin=j;
                            sem=1;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(ind[i]==st)out<<i<<" ";
    }
    for(int i=1;i<=n;++i)
    {
        if(ind[i]==fin)out<<i<<" ";
    }
    out<<solmin<<" "<<solmax;
    return 0;
}
