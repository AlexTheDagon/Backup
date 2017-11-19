#include <iostream>
#include <fstream>
using namespace std;
ifstream in("modulo.in");
ofstream out("modulo.out");
long long a,b,c;
long long logaritmputere(long long a,long long b,long long c)
{
    if(b==0)return 1;
    else if(b%2==0)return logaritmputere(1LL*a*a%c,b/2,c);
    return logaritmputere(1LL*a*a%c,b/2,c)*a%c;
}
int main()
{
    in>>a>>b>>c;
    out<<logaritmputere(a%c,b,c);

    return 0;
}
