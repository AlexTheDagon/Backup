#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#define x first
#define y second
#define mp make_pair
using namespace std;
ifstream in("lacuri.in");
ofstream out("lacuri.out");
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int a[105][105],sp[105][105];
int ii,jj,imin,jmin,imax,jmax,sem=1,lacuri,arie;
queue <pair<int,int> >q;
stack <pair<int,int> > s;
int n,viz[105][105];
pair<int,int> fr,venit[105][105];
int ok(int i,int j)
{
    return (i>0 && j>0 && i<=n && j<=n);
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)in>>a[i][j];
    for(int i=1;i<=n+1;++i)
    {
        for(int j=1;j<=n+1;++j)
        {
            sp[i][j]=a[i][j]+sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(viz[i][j]==0 && a[i][j]==1)
            {
                viz[i][j]=1;
                arie=1;
                q.push(mp(i,j));
                imin=1000;
                jmin=1000;
                imax=0;
                jmax=0;
                while(!q.empty())
                {
                    fr=q.front();
                    q.pop();
                    imin=min(imin,fr.x);
                    jmin=min(jmin,fr.y);
                    imax=max(imax,fr.x);
                    jmax=max(jmax,fr.y);
                    for(int d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(viz[ii][jj]==0 && ok(ii,jj) && a[ii][jj]==1)
                        {
                            viz[ii][jj]=1;
                            ++arie;
                            q.push(mp(ii,jj));
                        }
                    }
                }
                if(arie==sp[imax][jmax]+sp[imin-1][jmin-1]-sp[imax][jmin-1]-sp[imin-1][jmax] && (imax-imin)==(jmax-jmin) && arie==(imax-imin+1)*(jmax-jmin+1))++lacuri;
                else sem=0;
            }
        }
    }
    out<<lacuri<<'\n';
    if(sem)
    {
        int icur=n,jcur=n;
        q.push(mp(1,1));
        viz[1][1]=-1;
        while(!q.empty())
        {
            fr=q.front();
            q.pop();
            for(int d=0;d<4;++d)
            {
                ii=fr.x+dx[d];
                jj=fr.y+dy[d];
                if(ok(ii,jj) && viz[ii][jj]==0 && a[ii][jj]==0)
                {
                    a[ii][jj]=a[fr.x][fr.y]+1;
                    viz[ii][jj]=-1;
                    q.push(mp(ii,jj));
                    venit[ii][jj]=fr;
                }
            }
        }
        while(icur!=1 || jcur!=1)
        {
            s.push(mp(icur,jcur));
            ii=venit[icur][jcur].x;
            jj=venit[icur][jcur].y;
            icur=ii;
            jcur=jj;
        }
        s.push(mp(1,1));
        while(!s.empty())
        {
            out<<s.top().x<<" "<<s.top().y<<'\n';
            s.pop();
        }
    }
    return 0;
}
