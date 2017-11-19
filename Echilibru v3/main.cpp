#include <iostream>
#include <fstream>
using namespace std;
int lim,n,t,nr,sem;
long long rez;
float a[20],sum,s;
ifstream in("echilibru.in");
ofstream out("echilibru.out");
int main()
{
    in>>t;
    for(int l=0;l<t;++l)
    {
        sum=0;
        sem=0;
        in>>n;
        for(int i=1;i<=2*n;++i)
        {
            in>>a[i];
            sum+=a[i];
        }
        ///bine
        lim=1<<2*n-1;
        for(int i=0;i<lim;i++)
        {
            s=0;
            nr=0;
            for(int j=1;j<=2*n;j++)
            {
                if(i&(1<<(j-1)))
                {
                    s+=a[j];
                    ++nr;
                }
            }
            if(s==sum/2 && nr==n)sem=1;///bine
        }
        rez|=(sem<< (t-l-1));
    }
    out<<rez;
    return 0;
}
