#include <iostream>
#include <fstream>
using namespace std;
ifstream in("reactivi.in");
ofstream out("reactivi.out");
int n,a,b,c[300],container,maxim;
int main()
{in>>n;
for(int i=0;i<n;i++)
{
    for(in>>a>>b;a<=b;a++)c[a+120]++;
}
for(int i=1;i<299;i++)
{
    if(maxim<c[i])maxim=c[i];
    if(c[i]<maxim)
    {
        maxim=0;
        container++;
    }
}
out<<container-1;

    return 0;
}
