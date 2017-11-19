#include <iostream>
#include <fstream>
using namespace std;
ifstream in("elicop.in");
ofstream out("elicop.out");
int n,m,k,a[105][105],x11,x22,y11,y22,v,elicop[41],elicop1,elicop0,x,y,val;
int cnt(int x1,int y1,int x2,int y2)
{
    int patratele1=0,totalpatratele=0;
    if(x1>x2)
    {
        swap(x1,x2);
        swap(y1,y2);
    }
    if(v==-1 && y1>y2)
    {
        for(int i=y2;i<=y1;++i)
        {
            for(int j=i;j<=y1;++j)
            {
                if(a[x2][j])++patratele1;
                ++totalpatratele;
            }
            --x2;
        }
    }
    if(v==1 && y1>y2)
    {
        for(int i=y2;i<=y1;++i)
        {
            for(int j=y2;j<=i;++j)
            {
                if(a[x2][j])++patratele1;
                ++totalpatratele;
            }
            --x2;
        }
    }
    if(v==-1 && y1<y2)
    {
        for(int i=y2;i>=y1;--i)
        {
            for(int j=y1;j<=i;++j)
            {
                if(a[x2][j])++patratele1;
                ++totalpatratele;
            }
            --x2;
        }
    }
    if(v==1 && y1<y2)
    {
        for(int i=y1;i<=y2;++i)
        {
            for(int j=i;j<=y2;++j)
            {
                if(a[x1][j])++patratele1;
                ++totalpatratele;
            }
            ++x1;
        }
    }
    if(patratele1==totalpatratele) return 2;
    if(2*patratele1<totalpatratele)return 0;
    return 1;

}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)in>>a[i][j];
    in>>k;
    for(int i=1;i<=k;i++)
    {
        in>>x11>>y11>>x22>>y22>>v;
        val=cnt(x11,y11,x22,y22);
        if(val==2)elicop1++;
        if(val==0)
        {
            elicop[i]=1;
            elicop0++;
        }
    }
    out<<elicop1<<'\n';
    out<<elicop0<<" ";
    for(int i=1;i<=k;i++)if(elicop[i]==1)out<<i<<" ";
    return 0;
}
