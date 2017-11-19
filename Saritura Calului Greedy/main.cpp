#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int dx[]= {2,2,-2,-2,1,1,-1,-1};
int dy[]= {1,-1,1,-1,2,-2,2,-2};
int n,viz[50][50],a[50][50],sem,is,js;
int ok(int i,int j)
{
    return(i>0 && i<=n && j>0 && j<=n && !viz[i][j] && sem==0);
}
int sarituri_posibile(int i,int j)
{
    int ii,jj,numar_sarituri_posibile=0;
    for(int d=0; d<8; ++d)
    {
        ii=i+dx[d];
        jj=j+dy[d];
        if(ok(ii,jj))++numar_sarituri_posibile;
    }
    return numar_sarituri_posibile;
}
void greedy(int i,int j,int ocupat)
{
    int ii,jj,minn=10,ind=-1;
    viz[i][j]=1;
    a[i][j]=ocupat;
    if(ocupat==n*n)sem=1;
    for(int d=0; d<8; ++d)
    {
        ii=i+dx[d];
        jj=j+dy[d];
        if(ok(ii,jj))
        {
            if(sarituri_posibile(ii,jj)<minn)
            {
                minn=sarituri_posibile(ii,jj);
                ind=d;
            }
        }
    }
    if(ind>-1)greedy(i+dx[ind],j+dy[ind],ocupat+1);
    viz[i][j]=0;
}
int main()
{
    in>>n>>is>>js;
    greedy(is,js,1);
    if(!sem)out<<"Nu se poate";
    else
    {
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)out<<a[i][j]<<" ";
            out<<endl;
        }
    }
    return 0;
}
