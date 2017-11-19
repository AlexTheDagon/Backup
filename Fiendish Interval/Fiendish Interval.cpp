#include <iostream>

using namespace std;
long long dp[3][20],a,b,cs,cf,nrc,l,cb,pos[20],posb[20],bb[20];
long long sol;
int main()
{
    cin>>a>>b;
    cb=b;
    while(cb)
    {
        cb/=10;
        ++l;
    }
    cb=b;
    for(int i=1;i<=l;++i)
    {
        bb[l+1-i]=cb%10;
        cb/=10;
    }
    ///bine
    cs=max(a,1LL);
    cf=min(9LL,b-1);
    nrc=cf-cs+1;
    if(cs>9)
    {
        cout<<"0";
        return 0;
    }
    if(a==0)
    {
        cout<<b-a;
        return 0;
    }
    ///posb[i]---->posibilitatile ca pe pozitia i sa am cifrele mai mici decat a i-a cifra a lui b
    for(int i=1;i<=l;++i)
    {
        posb[i]=max(bb[i]-cs,0LL);
    }
    dp[1][0]=1;
    for(int i=1;i<=l;++i)
    {
        dp[1][i]=dp[1][i-1];
        dp[0][i]=dp[0][i-1]*nrc+dp[1][i-1]*posb[i]+1;
    }
    cout<<dp[0][l]-1;
    return 0;
}
/**
dp[0][i]--->nr de numere de lungime i care au ultima cifra in [cs,cf]
dp[1][i]--->nr de numere de lungime i care au toate cifrele pana la pasul i egale cu cifra lui b
**/
