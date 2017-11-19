#include <iostream>
#include <fstream>
using namespace std;
ifstream in("pic.in");
ofstream out("pic.out");
long long n,pic,v[55][55],a[55][55],dr,st,mid;
long long maxx,imax,caz,sum;
long long magie(long long picaturi)
{
    long long pelanga=0;
    a[1][1]=picaturi;
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            a[i+1][j]+=(a[i][j]-v[i][j]+1)/2;
            a[i+1][j+1]+=(a[i][j]-v[i][j])/2;
        }
    }
    for(int i=1;i<=n;++i)if(v[n][i]>a[n][i])return -1;
    for(int i=1;i<=n;++i)pelanga+=(a[n][i]-v[n][i]);
    return pelanga;
}
void curatare()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)a[i][j]=0;
}
int main()
{
    in>>caz;
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)in>>v[i][j];
    if(caz==1)
    {
        for(int i=1;i<=n;++i)
        {
            sum=0;
            for(int j=1;j<=i;++j)sum+=v[i][j];
            if(sum>maxx)
            {
                maxx=sum;
                imax=i;
            }
        }
        out<<imax<<'\n';
    }
    else
    {
        pic=1;
        while(magie(pic)==-1)
        {
            pic*=2;
            curatare();
        }
        curatare();
        dr=pic+10;
        st=max(pic/2-10,(long long)0);
        while(dr-st>1)
        {
            mid=st+(dr-st)/2;
            if(magie(mid)!=-1)dr=mid;
            else st=mid;
            curatare();
        }
        if(magie(st)==-1)++st;
        curatare();
        out<<st<<" "<<magie(st)<<'\n';
    }
    return 0;
}
