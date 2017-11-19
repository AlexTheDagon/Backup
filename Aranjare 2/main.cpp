#include <iostream>
#include <fstream>
#define x first
#define y second
using namespace std;
ifstream in("aranjare2.in");
ofstream out("aranjare2.out");
int n;
int a[200005],b[100005],poz[200005];
int main()
{
    in>>n;
    for(int i=1;i<=2*n;++i)a[i]=(i-1)%n+1;
    for(int i=n;i>1;--i)
    {
        out<<i<<" "<<2*i-1<<'\n';
        swap(a[i],a[2*i-1]);
    }
    ///bine
    for(int i=1;i<=n;++i)
    {
        b[i]=a[2*i];
        poz[b[i]]=2*i;
    }
    ///bine
    for(int i=1;i<=n;++i)
    {
        if(b[i]!=i)
        {
            out<<2*i<<" "<<poz[i]<<'\n';
            swap(b[i],b[poz[i]/2]);
            swap(poz[b[poz[i]/2]],poz[b[i]]);

        }
    }
    return 0;
}
///b[i]---elementul de pe poz i
///poz[i]-pozitia elementului i
