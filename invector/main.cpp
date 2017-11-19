#include <iostream>
#include <fstream>
using namespace std;
ifstream in("invector.in");
ofstream out("invector.out");
int n,v[100001];
void inv(int primul,int ultimul,int v[])
{
    if(primul<ultimul)
    {
        swap(v[primul],v[ultimul]);
        inv(primul+1,ultimul-1,v);
    }
    else for(int i=1;i<=n;++i)out<<v[i]<<" ";
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>v[i];
    inv(1,n,v);
    return 0;
}
