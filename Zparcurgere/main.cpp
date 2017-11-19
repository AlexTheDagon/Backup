#include <iostream>
#include <fstream>
using namespace std;
ifstream in("z.in");
ofstream out("z.out");
long long s,t;
long long lgput(long long a,long long b)
{
    if(b==0)return 1;
    else if(b%2==0)return lgput(a*a,b/2);
    return lgput(a*a,b/2)*a;
}
int m,x,y;
int z(int n,int xst,int ys,int xdr,int yj)
{
    if(n==0)
    {
        s+=1;
        return s;
    }
    int midx=(xst+xdr)/2;
    int midy=(yj+ys)/2;
    long long sx=lgput(2,2*n-2);
    if(x>midx && y>midy)
    {
        s+=sx*3;
        z(n-1,midx, midy, xdr, yj);
    }
    if(x<=midx && y>midy)
    {
        s+=sx*2;
        z( n-1, xst, midy, midx, yj);
    }
    if(x<=midx && y<=midy)
    {
        z( n-1, xst, ys, midx,midy);
    }
    if(x>midx && y<=midy)
    {
        s+=sx;
        z( n-1, midx, ys, xdr, midy);
    }
    return s;
}
int main()
{
    in>>m>>t;
    for(int i=1;i<=t;++i)
    {
        s=0;
        in>>y>>x;
        out<<z(m,1,1,lgput(2,m),lgput(2,m))<<'\n';
    }
    return 0;
}
