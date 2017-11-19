#include <iostream>
#include <fstream>

int n,apare=0,b;
int a[10000];


using namespace std;

int main()
{ifstream in("date.in");
ofstream out("date.out");
in>>n>>b;
for(int i=0;i<n;i++)
{
    in>>a[i];
    if(b==a[i])
    {
        apare=1;
    }
}
if(apare==1)
{
    out<<"Apare";
}
else{out<<"Nu apare";}
    return 0;
}
