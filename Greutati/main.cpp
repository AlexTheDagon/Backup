#include <iostream>
#include <fstream>
#include <vector>
#define N 1000005
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,a[N],b[N],mmin=1000000005;
int verif(int m)
{
    vector <int> v;
    for(int i=1;i<=n;++i)if(a[i]>m)v.push_back(a[i]);
    for(int i=2;i<v.size()-1;++i)if(v[i]!=v[i-1] && v[i]!=v[i+1])return 0;
    return 1;
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    for(int i=1;i<=n;++i)in>>b[i];
    return 0;
}
