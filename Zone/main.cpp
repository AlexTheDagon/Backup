#include <iostream>
#include <fstream>
using namespace std;
ifstream in("parcela.in");
ofstream out("parcela.out");
int n,a[101][101],m,viz[101][101],arie,nr,ariemax,nrmax;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
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
        if(ins(ii,jj) && 1==a[ii][jj] && viz[ii][jj]==0)
        {
            par(ii,jj);
        }
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            arie=0;
            if(a[i][j]==1 && viz[i][j]==0)
            {
                ++nr;
                par(i,j);
                if(arie>ariemax)
                {
                    ariemax=arie;
                    nrmax=nr;
                }
            }
        }
    }
    out<<nr<<" "<<ariemax<<" "<<nrmax;
    return 0;
}
