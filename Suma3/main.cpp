#include <iostream>
#include <fstream>
using namespace std;
ifstream in("suma3.in");
ofstream out("suma3.out");
int n,m,a[10][10],l,cost,minn,sol[100],viz[10][10];
void gen(int pas)
{

}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    l=n*m/2;
    return 0;
}
