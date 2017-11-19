#include <iostream>

using namespace std;
char a[1000];
int main()
{
    cin>>a;
    if(a[0]-'a'>-1)a[0]=a[0]-'a'+'A';
    for(int i=0;a[i]!=(char)0;++i)cout<<a[i];
    return 0;
}
