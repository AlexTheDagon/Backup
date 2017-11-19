#include <iostream>
#include <fstream>
using namespace std;
ifstream in("minusk.in");
ofstream out("minusk.out");
int n,k,a[1000000],cop,s;
int nr[1001][1001];
int main()
{
    in>>n>>k;
    nr[1][0]=1;
    nr[1][1]=1;
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<k;++j)
        {
            nr[i][j]=nr[i-1][j-1]%2011;
        }
        for(int j=0;j<k;++j)nr[i][0]+=nr[i-1][j];
        nr[i][0]=nr[i][0]%2011;
    }
    for(int i=0;i<k;++i)s+=nr[n][i];
    s=s%2011;
    out<<s;

    return 0;
}

