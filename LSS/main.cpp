#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("lss.in");
ofstream out("lss.out");
long long n,k,s;
long long a[100005];
int main()
{
    in>>k>>n;
    for(int i=0;i<n;++i)
        in>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;++i)
        s+=max((a[i]-1)%k+1-i,1LL);
    out<<s;
    return 0;
}
