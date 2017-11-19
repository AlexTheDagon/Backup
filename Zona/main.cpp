#include <iostream>
#include <fstream>
#include <queue>
#define f first
#define s second
using namespace std;
ifstream in("zona.in");
ofstream out("zona.out");
int n,l,v[2550],a[65][65],x,y,ii,jj,traseu,p,xf,yf,sem=1,aux,lungime=1,arie;
int dx[]={0,-1,0,1,0};
int dy[]={0,0,1,0,-1};
int opus[]={0,3,4,1,2};
int ok(int i,int j)
{
    return(i>=0 && i<=n+2 && j>=0 && j<=n+2);
}
pair<int,int> fr;
queue <pair<int,int> > q;
int main()
{
    in>>x>>y>>n>>l;
    ++x;
    ++y;
    ii=x;
    jj=y;
    for(p=1;p<=l && a[ii][jj]==0;++p)
    {
        a[ii][jj]=1;
        in>>v[p];
        ii+=dx[v[p]];
        jj+=dy[v[p]];
        aux=p;
    }
    p=aux;
    xf=ii;
    yf=jj;
    while(p>0)
    {
        ii+=dx[opus[v[p]]];
        jj+=dy[opus[v[p]]];
        if(sem==0)a[ii][jj]=0;
        if(ii==xf && jj==yf)sem=0;
        --p;
        if(sem==1)++lungime;
    }
    out<<lungime<<'\n';
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int d=1;d<=4;++d)
        {
            ii=fr.f+dx[d];
            jj=fr.s+dy[d];
            if(ok(ii,jj) && a[ii][jj]==0)
            {
                a[ii][jj]=1;
                q.push(make_pair(ii,jj));
            }
        }
    }
    for(int i=0;i<=n+2;++i)
    {
        for(int j=0;j<=n+2;++j)if(a[i][j]==0)++arie;
    }
    arie+=lungime/2-1;
    out<<arie;
    return 0;
}
