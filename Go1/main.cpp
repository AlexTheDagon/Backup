#include <iostream>
#include <fstream>
#include <set>
#define N 1000
#define M 1000
using namespace std;
ifstream in("go.in");
ofstream out("go.out");
set<pair<int,int> > s;
int a[N][M],viz[N][M],n,m,x,y,S[N][M],arie,vecini,maxx,sem;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int ins(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<m)return 1;
    return 0;
}
void par(int i,int j)
{
    int ii,jj;
    viz[i][j]=1;
    ++arie;
    for(int d=0;d<=3;++d)
    {
        ii=i+dx[d];
        jj=j+dy[d];
        if(ins(ii,jj) && viz[ii][jj]==0)
        {
            if(a[ii][jj]==2)par(ii,jj);
            if(a[ii][jj]==0)
            {
                x=ii;
                y=jj;
                s.insert(make_pair(x,y));
            }
        }
    }
}
int main()
{
    in>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)in>>a[i][j];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j]==2 && viz[i][j]==0)
            {
                x=0,y=0;
                arie=0;
                par(i,j);
                if(s.size()==1)
                {
                    S[x][y]+=arie;
                }
                s.clear();
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(maxx<S[i][j])
            {
                maxx=S[i][j];
                x=i;
                y=j;
                sem=1;
            }
        }
    }
    if(sem==1)out<<x<<" "<<y;
    else
    {
        for(int i=0;i<n && sem==0;++i)
        {
            for(int j=0;j<m && sem==0;++j)if(a[i][j]==0){out<<i<<" "<<j;sem=1;}
        }
        cout<<"nu ba";
    }
    return 0;
}
