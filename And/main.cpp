#include <iostream>
#include <fstream>
using namespace std;
int n,maxx,a[100000],v[100000],consec;
ifstream in("and.in");
ofstream out("and.out");
int main()
{in>>n;
for(int i=0;i<n;i++)in>>a[i];
for(int k=0;k<31;k++)
{
    for(int i=0;i<n;i++)
    {
        v[i]=(a[i]&1);
        a[i]>>=1;
    }
    consec=1;
    for(int i=1;i<n;i++)
    {
        if(v[i-1]==v[i] && v[i]==1)consec++;
        else
        {
            if(consec>maxx)maxx=consec;
            consec=1;
        }
    }

}
out<<maxx;


    return 0;
}
