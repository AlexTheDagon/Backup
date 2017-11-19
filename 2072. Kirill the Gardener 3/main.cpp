#include <iostream>
#include <algorithm>
#include <stdlib.h>
#define x first
#define y second
#define NM 100010
using namespace std;
long long n,dp[NM][2],flori,ultim=-1,minn[NM],maxx[NM],cost;
pair <long long ,long long> a[NM];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].x;
        a[i].y=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=100003;++i)minn[i]=1<<29;
    for(int i=1;i<=n;++i)
    {
        if(a[i].x!=ultim)
        {
            ++flori;
            ultim=a[i].x;;
        }
        minn[flori]=min(minn[flori],a[i].y);
        maxx[flori]=max(maxx[flori],a[i].y);
    }
    dp[1][0]=maxx[1]+maxx[1]-minn[1]-1;
    dp[1][1]=maxx[1]-1;
    for(int i=2;i<=flori;++i)
    {
        dp[i][0]=min(dp[i-1][0]+abs(minn[i-1]-maxx[i])+abs(maxx[i]-minn[i]),dp[i-1][1]+abs(maxx[i-1]-maxx[i])+abs(maxx[i]-minn[i]));
        dp[i][1]=min(dp[i-1][0]+abs(minn[i-1]-minn[i])+abs(minn[i]-maxx[i]),dp[i-1][1]+abs(maxx[i-1]-minn[i])+abs(maxx[i]-minn[i]));
    }
    cout<<min(dp[flori][0],dp[flori][1])+n;
    return 0;
}
///  nr[i][j]-->nr minim de pasi astfel incat am udat primele
/// i flori si la ultima floare am terminat in j(0 sau 1-repezinta capatul)
