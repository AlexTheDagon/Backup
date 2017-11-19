#include <iostream>
#include <fstream>
#include <queue>
#define mp make_pair
#define x first
#define y second

using namespace std;
ifstream in("rover.in");
ofstream out("rover.out");
int n,g,a[505][505],viz[505][505];
int caz;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int ii,jj,d;///parametrii lee
pair<int,int> fr;
queue<pair<int,int> >q[10005];
int ind=0;
int sem=1;
int inside(int i,int j)
{
    return (i>0 && i<=n && j>0 & j<=n);
}
int main()
{
    in>>caz;
    in>>n;
    if(caz==1)in>>g;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)in>>a[i][j];
    if(caz==1)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(a[i][j]>=g)a[i][j]=0;
                else a[i][j]=1;
            }
        }
        q[a[1][1]].push(mp(1,1));
        while(sem)
        {
            while(!q[ind].empty() && sem)
            {
                fr=q[ind].front();
                q[ind].pop();
                viz[fr.x][fr.y]=1;
                if(fr.x==n && fr.y==n)sem=0;
                else
                {
                    for(d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(inside(ii,jj) && viz[ii][jj]==0)
                        {
                            q[ind+a[ii][jj]].push(mp(ii,jj));
                        }
                    }
                }
            }
            ++ind;
        }
        out<<ind-1;
    }
    else
    {
        ind=min(a[1][1],a[n][n]);
        q[ind].push(mp(1,1));
        viz[1][1]=1;
        while(sem)
        {
            while(!q[ind].empty() && sem)
            {
                fr=q[ind].front();
                q[ind].pop();
                if(fr.x==n && fr.y==n)sem=0;
                else
                {
                    for(d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(inside(ii,jj) && viz[ii][jj]==0)
                        {
                            q[min(ind,a[ii][jj])].push(mp(ii,jj));
                            viz[ii][jj]=1;
                        }
                    }
                }
            }
            --ind;
        }
        out<<ind+1;
    }
    return 0;
}
