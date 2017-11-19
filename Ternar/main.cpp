#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ternar.in");
ofstream out("ternar.out");
int n,m,a[1250][1250],x[1250][1250],viz[1250][1250],sum,smax,s,s2;
int imin=1250;
int imax=0;
int jmin=1250;
int jmax=0;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int floodfill(int l,int c)
{
    ++sum;
    viz[l][c]=1;
    imin=min(l,imin);
    imax=max(l,imax);
    jmin=min(c,jmin);
    jmax=max(c,jmax);
    for(int d=0;d<=3;++d)
    {
        int ii=l+dx[d];
        int jj=c+dy[d];
        if(viz[ii][jj]==0 && x[ii][jj]==2)
        {
            floodfill(ii,jj);
        }
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            x[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)a[i][j]+=a[i][j-1];
    }
    for(int j=1;j<=m;++j)
    {
        for(int i=1;i<=n;++i)a[i][j]+=a[i-1][j];
    }
    ///bine
    for(int j=1;j<=m;++j)
    {
        for(int i=1;i<=n;++i)
        {
            if(viz[i][j]==0 && x[i][j]==2)
            {
                imin=1250;
                imax=0;
                jmin=1250;
                jmax=0;
                sum=0;
                floodfill(i,j);
                if(imin>1 && jmin>1)
                {
                    ///imax,imin,jmax,jmin bine
                    s=a[imax][jmax]-a[imin-1][jmax]-a[imax][jmin-1]+a[imin-1][jmin-1];
                    ///s bine
                    s2=a[imax+1][jmax+1]-a[imin-2][jmax+1]-a[imax+1][jmin-2]+a[imin-2][jmin-2];
                    ///s2 bine
                    if(s==2*sum && (s2-s)==2*(imax+2-imin+jmax+2-jmin))smax=max((imax-imin+3)*(jmax-jmin+3),smax);
                }
            }
        }
    }
    out<<smax;

    return 0;
}










