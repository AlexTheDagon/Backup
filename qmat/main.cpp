#include <iostream>
#include <bitset>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream in("qmat.in");
ofstream out("qmat.out");
bitset <10> a[10000][10];
bitset <10> mat[10];
int n[10005],m[10005],q,l,c,m1,m2,nrcol,nrlin,nr,st,dr,mij;
long long ind[10005],sum[10005];
long long sl,put,x,suma;
bool cmp(int a,int b)
{
    if(sum[a]<sum[b])return true;
    return false;
}
int main()
{
    in>>m1;
    for(int i=0;i<m1;++i)
    {
        in>>n[i]>>m[i];
        for(int l=0;i<n[i];++i)
        {
            sl=0;
            put=1;
            for(int c=0;c<m[i];++c)
            {
                in>>nr;
                a[i][l][c]=nr;
                sl|=nr<<(c-1);
            }
            sum[i]+=sl*put;
            put*=11;
        }
        ind[i]=i;
    }
    sort(ind,ind+m1,cmp);
    in>>m2;
    for(int i=0;i<m2;++i)
    {
        suma=0;
        put=1;
        in>>nrlin>>nrcol;
        for(int l=0;l<nrlin;++l)
        {
            sl=0;
            for(int c=0;c<nrcol;++c)
            {
                in>>nr;
                mat[l][c]=nr;
                sl|=nr<<(c-1);
            }
            suma+=sl*put;
            put=put*11;
        }
        st=0;
        dr=m1-1;
        mij;
    }
    return 0;
}

///   liniile le convertim in sume s1,s2,..,sn
///   converim in nr in baza 11 s1+s2*11+s3*11^2+...+sn*11^(n-1)
///   sortam dupa x si tinem minte in alt sir indicii


















///convertim liniile din linie->nr in baza 10
