#include <iostream>
#include <fstream>
using namespace std;
ifstream in("minusk.in");
ofstream out("minusk.out");
int a[1000010],k,sum,i=1,n,p,c;
int main()
{
    in>>n>>k;
    if(k!=1)
    {
        p=1;
        a[1]=1;
        sum=1;
        for(int l=2;l<=n;++l)
        {
            --i;
            if(i==0)i=k-1;
            c=p%2011;
            p+=sum;
            p=p%2011;
            sum=c-a[i]+sum;
            if(sum>10000)sum=sum-4022;
            a[i]=c;
        }
        out<<(p+sum)%2011;
    }
    else out<<"1";

    return 0;
}
