#include <iostream>
#define modulo 1000000007
using namespace std;
long long a[30],dp[1005],n,sem,impartiri[1005];
int lmax=1;
char c[1005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=0;i<26;++i)cin>>a[i];
    dp[1]=1;
    for(int i=1;i<=n;++i)impartiri[i]=1<<30;
    impartiri[1]=1;
    dp[0]=1;
    for(int k=2;k<=n;++k)
    {
        for(int l=1;l<=k;++l)
        {
            sem=1;
            for(int i=k-l+1;i<=k;++i)if(a[c[i]-'a']<l)sem=0;
            if(sem)
            {
                impartiri[k]=min(impartiri[k],impartiri[k-l]+1);
                dp[k]+=dp[k-l];
                dp[k]%=modulo;
                lmax=max(l,lmax);
            }
        }
    }
    cout<<dp[n]<<'\n';
    cout<<lmax<<'\n';
    cout<<impartiri[n];
    return 0;
}
