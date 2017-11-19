#include <iostream>
#include <fstream>
#define modulo 64997
using namespace std;
ifstream in("robot1.in");
ofstream out("robot1.out");
int br[3][2805],n,k;
long long s;
int main()
{
    in>>n>>k;
    br[1][1]=1;
    for(int i=k;i<n;++i)
    {
        for(int j=1;j<i;++j)
        {
            if(j+1<i)br[1][j+1]=(br[1][j+1]+br[1][j])%modulo;
            br[2][j]=(br[2][j]+br[1][j])%modulo;
        }
        for(int j=1;j<i;++j)
        {
            br[1][j]=br[2][j];
            br[2][j]=0;
        }
    }
    for(int i=1;i<n;++i)
    {
        s+=br[1][i];
        s=s%modulo;
    }
    out<<s<<'\n';
    return 0;
}
