#include <iostream>

using namespace std;
long long a[100][10000],n,b,k=2,q=1,s=0,c,l;
void gen(int p)
{
    if(p>n)return;
    for(int i=1;i<k;++i)a[i][p]=1;
    c=1,l=k;
    for(int i=1;i<l;++i)
    {
        if(a[i][p-1]==1)
        {
            for(int j=1;j<p;++j)a[k][j]=a[c][j];
            a[k][p]=0;
            ++k;
        }
        ++c;
    }
    q=c;
    gen(p+1);
}
int main()
{
    cin>>n>>b;
    a[1][1]=1;
    gen(1);
    q++;
    for(int f=1;f<k;++f)
    {
        a[f][n+1]++;
        for(int i=1;i<=n;++i)if(a[f][i]!=0)a[f][n+1]*=(b-1);
        s+=a[f][n+1];
    }
    cout<<s;
    return 0;
}
