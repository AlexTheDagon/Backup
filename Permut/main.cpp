#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("permut.in");
ofstream out("permut.out");
long long sum,a[100000],b[100000];
int n;
int main()
{in>>n;
for(int i=0;i<n;i++)in>>a[i];
for(int i=0;i<n;i++)in>>b[i];
sort(a,a+n);
sort(b,b+n);
for(int i=0;i<n;i++)sum=sum+a[i]*b[i];
out<<sum;
    return 0;
}
