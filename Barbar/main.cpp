#include <iostream>
#include <fstream>
#include <queue>
#include <deque>
#define NM 1005
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
ifstream in("barbar.in");
ofstream out("barbar.out");
int dist[NM][NM],maxx[NM][NM],n,m,viz[NM][NM],vizd[NM][NM],ii,jj,mij,stt,dr;
char c;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<pii> d,bar;
pii st,fn,fr;
int ok(int i,int j)
{
    return(i>0 && j>0 && i<=n && j<=m);
}
void reset()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)if(viz[i][j]==1)viz[i][j]=0;
}
int lee(int dmin)
{
    reset();
    if(maxx[st.x][st.y]>=dmin)bar.push(st);
    while(!bar.empty())
    {
        fr=bar.front();
        bar.pop();
        for(int dd=0;dd<4;++dd)
        {
            ii=fr.x+dx[dd];
            jj=fr.y+dy[dd];
            if(ok(ii,jj) && (viz[ii][jj]==2 || viz[ii][jj]==0) && maxx[ii][jj]>=dmin)
            {
                viz[ii][jj]=1;
                bar.push(mp(ii,jj));
            }
        }
    }
    return viz[fn.x][fn.y];
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>c;
            if(c=='D')
            {
                d.push(mp(i,j));
                viz[i][j]=2;
                vizd[i][j]=-1;
            }
            if(c=='*')
            {
                dist[i][j]=-1;
                vizd[i][j]=viz[i][j]=-1;
            }
            if(c=='I')st=mp(i,j);
            if(c=='O')fn=mp(i,j);
        }
    }
    while(!d.empty())
    {
        fr=d.front();
        d.pop();
        for(int dd=0;dd<4;++dd)
        {
            ii=fr.x+dx[dd];
            jj=fr.y+dy[dd];
            if(!vizd[ii][jj] && ok(ii,jj))
            {
                vizd[ii][jj]=1;
                maxx[ii][jj]=maxx[fr.x][fr.y]+1;
                d.push(mp(ii,jj));
            }
        }
    }
    dr=3000;
    stt=0;
    while(dr-stt>1)
    {
        mij=(dr+stt)/2;
        if(lee(mij)==1)stt=mij;
        else dr=mij;
    }
    while(!lee(mij) && mij>-1)--mij;
    while(lee(mij) && mij<2*n)++mij;
    if(mij==2*n || mij==-1)out<<"-1";
    else out<<mij-1;
    return 0;
}
