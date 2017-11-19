#include <iostream>
#include <fstream>
using namespace std;
ifstream in("expresie.in");
ofstream out("expresie.out");
int n;
long long s,maxx,cs,a[1000];
int main()
{in>>n;
for(int i=0;i<n;i++)
{
    in>>a[i];
    s+=a[i];
}
maxx=s;
cs=s;
for(int i=0;i<n-1;i++)
{
    for(int j=i+1;j<n;j++)
    {
        cs=s;
        cs=cs-a[i];
        cs=cs-a[i+1];
        cs=cs-a[j+1];
        if(j==i+1)
        {
            cs=cs+a[i]*a[j]*a[j+1];
        }
        else
        {
            cs=cs-a[j];
            cs=cs+a[j]*a[j+1];
            cs=cs+a[i]*a[i+1];
        }
        if(cs>maxx)maxx=cs;
    }
}
out<<maxx;

    return 0;
}
