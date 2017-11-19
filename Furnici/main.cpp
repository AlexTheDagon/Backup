#include <iostream>
#include <fstream>
using namespace std;
ifstream in("furnici.in");
ofstream out("furnici.out");
int dist,n,m,poz,sum;
char s;
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)
    {
        in>>poz>>s;
        if(s=='D')sum=max(sum,(n-poz));
        else sum=max(sum,poz);
    }
    out<<sum;
    return 0;
}
