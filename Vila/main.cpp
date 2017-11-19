#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("vila.in");
ofstream out("vila.out");
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int ii,jj,n,m,viz[128][128],a[128][128],arie,amax=-100,cmax,iz,jz,camere,sc[4],cam[200000],sz;
char c;
pair <int,int> fr,crd;
queue <pair<int,int> > q,ind,zid;
int inside(int i,int j)
{
    if(i>0 && i<=n && j>0 && j<=m)return 1;
    return 0;
}
int sumzid(int i,int j)
{
    int sum=0;
    for(int d=0;d<4;++d)
    {
        ii=i+dx[d];
        jj=j+dy[d];
        if(inside(ii,jj) && a[ii][jj]!=-1)sc[d]=viz[ii][jj];
    }
    for(int i1=0;i1<4;++i1)
    {
        for(int j1=i1+1;j1<4;++j1)if(sc[i1]==sc[j1])sc[i1]=0;
    }
    for(int d=0;d<4;++d)sum=sum+cam[sc[d]];
    for(int d=0;d<4;++d)sc[d]=0;
    return sum;
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>c;
            if(c=='1')a[i][j]=-1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]==0 && viz[i][j]==0)
            {
                arie=0;
                ++camere;
                viz[i][j]=camere;
                q.push({i,j});
                while(!q.empty())
                {
                    ++arie;
                    fr=q.front();
                    ind.push(q.front());
                    q.pop();
                    for(int d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(inside(ii,jj) && viz[ii][jj]==0)
                        {
                            if(a[ii][jj]==0)
                            {
                                q.push({ii,jj});
                                viz[ii][jj]=camere;
                            }
                            else
                            {
                                zid.push({ii,jj});
                                viz[ii][jj]=-1;
                            }
                        }
                    }
                }
                cam[camere]=arie;
                while(!ind.empty())///bine
                {
                    fr=ind.front();
                    a[fr.x][fr.y]=arie;
                    ind.pop();
                }
                cmax=max(cmax,arie);
            }
        }
    }
    while(!zid.empty())
                {
                    fr=zid.front();
                    sz=sumzid(fr.x,fr.y);
                    if(sz>amax)
                    {
                        amax=sz;
                        iz=fr.x;
                        jz=fr.y;
                    }
                    else
                    {
                        if(sz==amax)
                        {
                            if(fr.x<iz)
                            {
                                iz=fr.x;
                                jz=fr.y;
                            }
                            else
                            {
                                if(fr.x==iz)jz=min(jz,fr.y);
                            }
                        }
                    }
                    zid.pop();
                }
    out<<camere<<'\n';
    out<<cmax<<'\n';
    out<<iz<<" "<<jz<<" "<<amax+1;
    return 0;
}
