#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ferma3.in");
ofstream out("ferma3.out");
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char v,c[401][401];
int m,n,p,a[401][401],maxx,viz[401][401],arie,ariemax;
int ins(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)return 1;
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
        if(ins(ii,jj) && c[i][j]==c[ii][jj] && viz[ii][jj]==0)
        {
            par(ii,jj);
        }
    }
}
int main()
{
    in>>p>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)in>>c[i][j];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            arie=0;
            if(viz[i][j]==0)
            {
                par(i,j);
                if(arie>ariemax)
                {
                    ariemax=arie;
                }
            }
        }
    }
    out<<ariemax;
    return 0;
}
