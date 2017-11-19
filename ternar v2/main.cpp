#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("ternar.in");
ofstream out("ternar.out");
int n,m,a[1250][1250],viz[1250][1250],sum,smax,s,s2,ii,jj,x[1250][1250],sem;
int imin=1250;
int imax=0;
int jmin=1250;
int jmax=0;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
queue <pair<int,int> > c;
pair <int,int> fr;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(viz[i][j]==0 && a[i][j]==2)
            {
                imin=1250;
                imax=0;
                jmin=1250;
                jmax=0;
                c.push(make_pair(i,j));
                viz[i][j]=1;
                ///floodfill iterativ
                while(!c.empty())
                {
                    fr=c.front();
                    c.pop();///verif
                    imin=min(fr.x,imin);
                    imax=max(fr.x,imax);
                    jmin=min(fr.y,jmin);
                    jmax=max(fr.y,jmax);
                    for(int d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(a[ii][jj]==2 && viz[ii][jj]==0)
                        {
                            c.push(make_pair(ii,jj));
                            viz[ii][jj]=1;
                        }
                    }
                }
                sem=1;
                for(int l=imin;l<=imax;++l)
                {
                    for(int k=jmin;k<=jmax;++k)if(a[l][k]!=2)sem=0;
                }
                for(int l=imin-1;l<=imax+1;++l)if(a[l][jmin-1]!=1 || a[l][jmax+1]!=1)sem=0;
                for(int k=jmin-1;k<=jmax+1;++k)if(a[imin-1][k]!=1 || a[imax+1][k]!=1)sem=0;
                if((imax-imin+3)*(jmax-jmin+3)>smax && sem==1)smax=(imax-imin+3)*(jmax-jmin+3);
            }
        }
    }
    out<<smax;

    return 0;
}
