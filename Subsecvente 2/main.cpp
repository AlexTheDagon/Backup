#include <iostream>
#include <fstream>
#include <string.h>
#define NM 50005
using namespace std;
ifstream in("subsecvente2.in");
ofstream out("subsecvent2.out");
int n,m,S[NM],k,t;
char P[NM],T[NM],SIR[6][NM];
int main()
{
    in>>t;
    for(int i=1;i<=t;++i)in>>SIR[i]+1;
    for(int i=1;i<=t;++i)
    {
        strcpy(P,SIR[i]);
        n=strlen(P+1);
        for(int i=1;i<=n;++i)S[i]=0;
        for(int j=1;j<=t;++j)
        {

        }
        for(int i=2;i<=n;++i)
        {
            while(k>0 && P[k+1]!=P[i])k=S[k];
            if(P[k+1]==P[i])++k;
            S[i]=k;
        }
    }
    return 0;
}
