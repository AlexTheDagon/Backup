#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,x[1000][1000],sp[1000][1000],a1,a2,b1,b2,maxx;
int main()
{
    in>>n;
    for(int i=0;i<n;++i)
    {
        in>>a1>>b1>>a2>>b2;
        x[a1][b1]++;
        x[a2+1][b1]--;
        x[a2+1][b2+1]++;
        x[a1][b2+1]--;

    }
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<n;++j)
        {
            sp[i][j]=sp[i-1][j]+sp[i][j-1]+x[i][j]-sp[i-1][j-1];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(sp[i][j]>maxx)maxx=sp[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(sp[i][j]==maxx)out<<i<<" "<<j<<'\n';
        }
    }
    return 0;
}
