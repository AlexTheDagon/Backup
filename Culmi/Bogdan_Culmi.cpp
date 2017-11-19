#include <iostream>
#include <fstream>
#define NM 110
using namespace std;
ifstream in("culmi.in");
ofstream out("culmi.out");
long long dp[71][141][NM],n,k;
int main()
{
    in>>n>>k;
    if(n==k || k==1)
    {
        out<<"1";
        return 0;
    }
    dp[0][0][0]=1;
    for(int i=0;i<k;++i)///nr varfuri
        for(int j=0;j<=2*n;++j)///lungime
            for(int s=0;s<=100;++s)///suma secv
                for(int p=1;p<=2*n-j;++p)///nr plusuri
                    for(int m=1;m<=2*n-p-j && s+p-m>=0;++m)dp[i+1][j+m+p][s+p-m]+=dp[i][j][s];///nr minusuri+adaugare
    out<<dp[k][2*n][0];
    return 0;
}
///i nr varfuri
///j lungime secv curenta
///s suma secventei
///m nr minusuri
///p nr plusuri
