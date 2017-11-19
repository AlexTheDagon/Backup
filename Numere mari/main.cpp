#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m,a[1000],b[1000],nrmaimare;
int main()
{in>>n>>m;
for(int i=0;i<n;i++)
{
    in>>a[i];
}
for(int i=0;i<m;i++)
{
    in>>b[i];
}



    return 0;
}
