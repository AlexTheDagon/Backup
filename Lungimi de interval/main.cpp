#include <iostream>
#include <fstream>
using namespace std;
ifstream in("linterv.in");
ofstream out("linterv.out");
int a[2000010],x,y,n,s;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>x>>y;
        a[x+1000005]=1;
        a[y+1000006]=-1;
    }
    for(int i=0;i<=2000009;++i)a[i]=a[i-1];
    for(int i=0;i<=2000009;++i)is(a[i]==1)++s;
    return 0;
}
