#include <iostream>
#include <fstream>
using namespace std;
ifstream in("sumall.in");
ofstream out("sumall.out");
int n,fr[10];
long long s=1,x,sum,fact,aux,sf=1;
char c;
int main()
{
    while(in>>c)
    {
        fr[c-'0']++;
        ++n;
    }
    for(int i=2;i<=n;++i)s*=i;
    for(int i=1;i<=n;++i)x=x*10+1;
    for(int i=0;i<=9;++i)
    {
        if(fr[i]!=0)
        {
            sf+=fr[i];
            fact=1;
            for(int j=2;j<=fr[i];++j)fact=fact*j;
            s=s/fact;
        }
    }
    for(int i=0;i<=9;++i)
    {
        if(fr[i]!=0)
        {
            sum=sum+i*x*(s*fr[i]/n);
        }
    }
    cout<<s;
    out<<sum;
    return 0;
}
///am numarul de permutari s
///am nuarul de cifre s
///am frecventa lor
