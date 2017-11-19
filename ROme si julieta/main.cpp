#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#define x first
#define y second
using namespace std;
ifstream in("rj.in");
ofstream out("rj.out");
string v;
int dx[]={0,-1,0,1,1,1,-1,-1},dy[]={-1,0,1,0,1,-1,1,-1};
int n,m,x,y,a[101][101],fi,fj,p;
queue <pair <int,int>  > c;
int main()
{
    in>>n>>m;
    while(getline(in,v));
    for(int i=0;i<n;++i)
    {
        getline(in,v);
        for(int j=0;j<m;++j)
        {
            if(v[j]=='R')x=i+1,y=j+1;
            if(v[j]=='J')fi=i+1,fj=j+1;
            if(v[j]=='X')a[i+1][j+1]=-1;
        }
    }
    for(int i=1;i<=n;)
    a[x][y]=0;
    c.push(make_pair(x,y));
    while(!c.empty())
    {
        pair <int,int> fr=c.front();
        c.pop();
        int ii,jj;
        for(int d=0;d<4;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ii>0 && ii<=n && jj>0 && jj<=n && a[ii][jj]==0)
            {
                a[ii][jj]=a[fr.x][fr.y]+1;
                c.push(make_pair(ii,jj));
            }
        }
    }
    out<<(a[fi][fj]+1)/2;
    int ii=fi,jj=fj;
    while(a[ii][jj]!=(a[fi][fj]+1)/2)
    {
        int iii,jjj;
        for(int d=0;d<4;++d)
        {
            iii=ii+dx[d];
            jjj=jj+dy[d];
            if(a[iii][jjj]==a[ii][jj]-1)
            {
                d=4;
                ii=iii;
                jj=jjj;
            }
        }
    }
    out<<" "<<ii<<" "<<jj;
    return 0;
}
