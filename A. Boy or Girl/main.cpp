#include <iostream>

using namespace std;
int c[30],k;
char a[100];
int main()
{
    cin>>a;
    for(int i=0;a[i]!=(char)0;++i)c[a[i]-'a']++;
    for(int  i=0;i<=29;++i)if(c[i]>0)++k;
    if(k%2==0)cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";
    return 0;
}
