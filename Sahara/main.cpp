#include <iostream>
#include <fstream>
#define Nmax 1005
#define Mmax 1005
#define x first
#define y second
#include <queue>
using namespace std;
ifstream in("sahara.in");
ofstream out("sahara.out");
int a[Nmax][Mmax],viz[Nmax][Mmax];
int q,x1,x2,y1,y2,n,m,apa,t,i,j,smax,sum,ii,jj;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
queue < pair<int,int> > Q;
pair <int,int> fr;
int ok(int k,int l)
{
    return(k<=n && k>0 && l<=m && l>0);
}
int main()
{
    in>>n>>m>>apa;
    in>>t;
    for(i=1;i<=t;++i)
    {
        in>>x1>>y1>>x2>>y2>>q;
        a[x1][y1]+=q;
        a[x1][y2+1]-=q;
        a[x2+1][y1]-=q;
        a[x2+1][y2+1]+=q;
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }///bine
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            if(a[i][j]>=apa && viz[i][j]==0)
            {
                sum=0;
                viz[i][j]=1;
                Q.push({i,j});
                while(!Q.empty())
                {
                    sum++;
                    fr=Q.front();
                    Q.pop();
                    for(int d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(ok(ii,jj) && viz[ii][jj]==0 && a[ii][jj]>=apa)
                        {
                            Q.push({ii,jj});
                            viz[ii][jj]=1;
                        }
                    }
                }
                smax=max(smax,sum);
            }
        }
    }
    out<<smax;
    return 0;
}
