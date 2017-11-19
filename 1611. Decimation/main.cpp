#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int n,poz[55],k,a[10105],minn=10000000,sol[55];
string s;
vector <int> v;
void backtracking(int pas,int upoz)
{
    if(pas>k)
    {
        int t=0,nrtax=0,j=1;
        for(int i=0;i<n;++i)
        {
            while(poz[j]<=i && j<=k)
            {
                ++j;
                v.pb(1);
            }
            v.pb(s[i]-'0');
        }
        for(int i=0;i<v.size();++i)if(v[i] && (i+1)%10==0)++nrtax;
        if(nrtax<minn)
        {
            minn=nrtax;
            for(int i=1;i<=k;++i)sol[i]=poz[i]+i;
        }
        v.clear();
    }
    else
    {
        for(int i=upoz;i<n;++i)
        {
            poz[pas]=i;
            backtracking(pas+1,i);
        }
    }
}
int main()
{
    cin>>n>>k;
    cin>>s;
    backtracking(1,0);
    cout<<minn<<endl;
    cout<<k<<" ";
    for(int i=1;i<=k;++i)cout<<sol[i]<<" ";
    return 0;
}
///dp[i][j]---nr minim de 1 pana la poz i in sirul initial folosind j dogers
///se tine cont de lungime si k
