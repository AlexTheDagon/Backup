#include <iostream>
#include <fstream>
using namespace std;
ifstream in("classictask.in");
ofstream out("classictask.out");
long long x,y,z;
long long lgmult(long long a,long long b,long long c)
{
    if(b==0)return 0;
    if(b==1)return a%c;
    long long aux=lgmult(a,b/2,c);
    if(b%2==0)return (aux+aux)%c;
    return ((a+aux)%c+aux)%c;

}
long long logaritmputere(long long a,long long b,long long c)
{
    if(b==1)return a%c;
    long long aux=logaritmputere(a,b/2,c);
    long long aux2=lgmult(aux,aux,c);
    if(b%2==0)
    {
        return aux2;
    }
    return lgmult(aux2,a,c);
}
int main()
{
    in>>x>>y>>z;
    out<<logaritmputere(x%z,y,z);

    return 0;
}
