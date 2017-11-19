#include <iostream>

using namespace std;
int sem;
char a[100];
int main()
{
    cin>>a;
    for(int i=0;i<100;++i)
    {
        if(a[i]=='H' || a[i]=='Q' || a[i]=='9')sem=1;
    }
    if(sem==1)cout<<"YES";
    else cout<<"NO";
    return 0;
}
