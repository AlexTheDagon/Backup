#include <iostream>
#include <fstream>
#include <functional>
#define mp make_pair
#define NM 1005
#define triple pair<int,pair<int,int> >
#define x first
#define y second.first
#define z second.second
#include <queue>
#define inf 1000000000

using namespace std;
ifstream in("taxa.in");
ofstream out("taxa.out");
int is,js,ifin,jfin,n,m;
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
priority_queue <triple,vector<triple>,greater<triple> > q;
triple fr;
int a[NM][NM],fol[NM][NM],maxx;
int cost[NM][NM];
int ok(int i,int j)
{
    return (i<=n && i>0 && j<=m && j>0);
}
int main()
{
    in>>n>>m>>is>>js>>ifin>>jfin;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            cost[i][j]=inf;
        }
    }
    cost[is][js]=0;
    q.push(mp(0,mp(is,js)));
    while(!q.empty())
    {
        ++maxx;
        fr=q.top();
        fol[fr.y][fr.z]=1;
        q.pop();
        for(int d=0;d<8;++d)
        {
            int ii=fr.y+dx[d];
            int jj=fr.z+dy[d];
            if(fol[ii][jj]==0)
            {
                if(ok(ii,jj))
                {
                    if(a[fr.y][fr.z]==a[ii][jj])
                    {
                        if(cost[fr.y][fr.z]<cost[ii][jj])
                        {
                            cost[ii][jj]=fr.x;
                            if(fol[ii][jj]==0)q.push(mp(fr.x,mp(ii,jj)));
                        }
                    }
                    else
                    {
                        int nr=a[fr.y][fr.z]*a[ii][jj];
                        if(fr.x+nr<cost[ii][jj])
                        {
                            cost[ii][jj]=fr.x+nr;
                            if(fol[ii][jj]==0)q.push(mp(cost[ii][jj],mp(ii,jj)));
                        }
                    }
                }
            }
        }
    }
    cout<<maxx;
    out<<cost[ifin][jfin];

    return 0;
}
///Daca nu iese incerc cu priority queue
