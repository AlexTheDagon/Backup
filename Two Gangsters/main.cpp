#include <iostream>
#include <fstream>

using namespace std;
int a,b,s;
ifstream in("date.in");
ofstream out("date.out");

int main()
{
    int a,b;
    cin>>a>>b;
    s=a+b-2;
    b=s-b;
    a=s-a;
    return 0;
    cout<<a<<b;
}
