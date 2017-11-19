#include <iostream>

using namespace std;
int n;
char a[101];
int main()
{
    cin>>a;
    for(int i=1;i<=100;++i)
    {
        if(a[i]-'a'>=0 && a[i]-'Z'<=0)n++;
        if(a[i])
    }
    return 0;
}
