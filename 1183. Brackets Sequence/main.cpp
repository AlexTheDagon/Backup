#include <iostream>
#define NM  110
using namespace std;
int dp[NM][NM],n,v[200];
string s,ans[NM][NM];
int main()
{
    cin>>s;
    v[')']=1;
    v['(']=-1;
    v['[']=-2;
    v[']']=2;
    n=s.size();
    for(int i=0;i<n;++i)
    {
        if(s[i]==')' || s[i]=='(')ans[i][i]="()";
        else ans[i][i]="[]";
    }
    for(int i=0;i<n;++i)dp[i][i]=1;
    for(int l=1;l<n;++l)
    {
        for(int i=0;i<n-l;++i)
        {
            dp[i][i+l]=100000000;
            for(int k=i;k<i+l;++k)
            {
                if(dp[i][k]+dp[k+1][i+l]<dp[i][i+l])
                {
                    dp[i][i+l]=dp[i][k]+dp[k+1][i+l];
                    ans[i][i+l]="";
                    ans[i][i+l]=ans[i][k]+ans[k+1][i+l];
                }
            }
            if(v[s[i]]+v[s[i+l]]==0 && v[s[i]]<0)
            {
                if(dp[i+1][i+l-1]<dp[i][i+l])
                {
                    dp[i][i+l]=dp[i+1][i+l-1];
                    ans[i][i+l]="";
                    ans[i][i+l]=s[i]+ans[i+1][i+l-1]+s[i+l];
                }
            }
        }
    }
    if(n==0)cout<<"";
    else cout<<ans[0][n-1];
    return 0;
}
