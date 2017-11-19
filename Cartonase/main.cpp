#include <iostream>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,maxim,a[10000],ca,x=1,primacifra;
int ucif(int x)
{
    return x%10;
}
int pcif(int x)
{
    while(x>9)
    {
        x/=10;
    }
    return x;
}
int lip(int a,int b)
{
    int cb=b;
    while(cb)
    {
        a*=10;
        cb/=10;
    }
    return a+b;
}
int main()
{
    in>>n;
    for(int i=0;i<n;i++)in>>a[i];
    for(int j=0;j<n;j++)
    {
        primacifra=pcif(a[j]);
        for(int i=0;i<n;i++)
        {
            if(primacifra==ucif(a[i]) && lip(a[i],a[j])>maxim && j!=i)maxim=lip(a[i],a[j]);
        }
    }
    out<<maxim;
    return 0;
    in.close();
    out.close();
}
