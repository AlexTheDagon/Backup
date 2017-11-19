#include <iostream>

using namespace std;
int scif(int n)
{
    if(n<10)return n;
    else return n%10+scif(n/10);
}
int main()
{
    cout << scif(123);

    return 0;
}
