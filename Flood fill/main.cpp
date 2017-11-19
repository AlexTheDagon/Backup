#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,a[100][100];
int xs,ys,suma;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int inside(int x,int y)
{
    if(x>0 && x<=n && y>0 && y<=n)return 1;
    return 0;
}
int floodfill(int l,int c)
{
    ++suma;
    a[l][c]=1;
    for(int d=0;d<=3;++d)
    {
        int ii=l+dx[d];
        int jj=c+dy[d];
        if(inside(ii,jj) && a[ii][jj]==0)floodfill(ii,jj);
    }
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)in>>a[i][j];
    in>>xs>>ys;
    floodfill(xs,ys);
    out<<suma;
    return 0;
}
