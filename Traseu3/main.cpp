#include <iostream>
#include <queue>
#include <fstream>
#include <stack>
#define mp make_pair
#define x first.first
#define y first.second
#define z second
using namespace std;
ifstream in("traseu3.in");
ofstream out("traseu3.out");
queue<pair<pair<int,int>,int> > q;
pair<pair<int,int>,int> fr,aux,viz,st,fin,cur;
int dx[]={-1,0,0,0,0,1};
int dy[]={0,-1,0,0,1,0};
int dz[]={0,0,-1,1,0,0};
int a[105][105][105],venit[105][105][105];
int n,m,is,js,ks,ifin,jfin,kfin,ii,jj,kk;
stack <pair<pair<int,int>,int> > s;
int ok(int i,int j,int k)
{
    return(i>0 && j>0 && k>0 && i<=n && j<=n && k<=n);
}
int main()
{
    in>>n>>m;
    viz.x=-1;
    viz.y=-1;
    viz.z=-1;
    in>>st.x>>st.y>>st.z>>fin.x>>fin.y>>fin.z;
    for(int i=1;i<=m;++i)
    {
        in>>aux.x>>aux.y>>aux.z;
        a[aux.x][aux.y][aux.z]=-1;
    }
    a[st.x][st.y][st.z]=1;
    q.push(st);
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int d=0;d<6;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            kk=fr.z+dz[d];
            if(ok(ii,jj,kk) && a[ii][jj][kk]==0)
            {
                q.push(mp(mp(ii,jj),kk));
                venit[ii][jj][kk]=d;
                a[ii][jj][kk]=a[fr.x][fr.y][fr.z]+1;
            }
        }
    }
    ii=fin.x;
    jj=fin.y;
    kk=fin.z;
    while(st!=mp(mp(ii,jj),kk))
    {
        s.push(mp(mp(ii,jj),kk));
        cur=mp(mp(ii,jj),kk);
        ii=ii-dx[venit[cur.x][cur.y][cur.z]];
        jj=jj-dy[venit[cur.x][cur.y][cur.z]];
        kk=kk-dz[venit[cur.x][cur.y][cur.z]];
        cur=mp(mp(ii,jj),kk);
    }
    s.push(st);
    out<<s.size()<<'\n';
    while(!s.empty())
    {
        out<<s.top().x<<" "<<s.top().y<<" "<<s.top().z<<'\n';
        s.pop();
    }

    return 0;
}
