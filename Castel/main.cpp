#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#define pb push_back
#define cmax 155*155
using namespace std;
ifstream in("castel.in");
ofstream out("castel.out");
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
int cam,n,m,a[155][155],ii,jj,cm[155][155],sem,st;
int act;
vector<int> v[cmax],vec[cmax];
int viz[cmax],des[cmax],vv[cmax];
queue <int> q;
int x;
int ok(int i,int j);
int main()
{
    in>>n>>m>>st;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            ++cam;
            cm[i][j]=cam;
            des[cam]=a[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cam=cm[i][j];
            for(int d=0;d<4;++d)
            {
                ii=i+dx[d];
                jj=j+dy[d];
                if(ok(ii,jj))vec[cam].pb(cm[ii][jj]);
            }
        }
    }
    ///bine
    cam=0;
    q.push(st);
    viz[st]=1;
    while(!q.empty())
    {
        x=q.front();
        ++vv[x];
        q.pop();
        if(vv[x]==1)
        {
            for(auto z:v[x])
            {
                viz[z]=1;
                q.push(z);
            }
            ++cam;
        }
        for(auto y:vec[x])
        {
            if(viz[y]==0)
            {
                if(viz[des[y]]==1)
                {
                    q.push(y);
                    viz[y]=1;
                }
                else v[des[y]].pb(y);
            }
        }
        v[x].clear();
        vec[x].clear();
    }
    out<<cam;
    return 0;
}



int ok(int i,int j)
{
    return(i>0 && i<=n && j>0 && j<=m);
}
