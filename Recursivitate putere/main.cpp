#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lgput.in");
ofstream out("lgput.out");
int n,p;
int logaritmputere(int a,int n)
{
    if(n==0)return 1;
    else if(n%2==0)return logaritmputere(1LL*a*a%1999999973,n/2);
    return logaritmputere(1LL*a*a%1999999973,n/2)*a%1999999973;
}
int main()
{
    in>>n>>p;
    out<<logaritmputere(n%1999999973,p);

    return 0;
}
