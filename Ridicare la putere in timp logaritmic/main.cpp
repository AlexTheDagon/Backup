#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lgput.in");
ofstream out("lgput.out");
long long n,p;
long long logaritmputere(long long a,int n)
{
    if(n==0)return 1LL;
    else if(n%2==0)return logaritmputere(a*a%1999999973,n/2);
    return logaritmputere(a*a%1999999973,n/2)*a%1999999973;
}
int main()
{
    in>>n>>p;
    out<<logaritmputere(n,p);

    return 0;
}
