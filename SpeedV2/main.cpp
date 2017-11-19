#include <iostream>

using namespace std;
double t1,t2,k1,k2,T1,T2,T;
int main()
{
    cin>>t1>>k1>>t2>>k2;
    T1=t1*1.0/k1;
    T2=t2*1.0/k2;
    T=1.0*T1*T2/(T1+T2);
    cout<<T<<'\n';
    return 0;
}
