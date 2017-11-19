#include <iostream>

using namespace std;
int s;
char a[110],b[110];
int main()
{
    cin>>a;
    cin>>b;
    for(int i=0;a[i]!=(char)0;++i)
    {
        if(a[i]-'a'<0)a[i]=a[i]-'A'+'a';
        if(b[i]-'a'<0)b[i]=b[i]-'A'+'a';
    }
    for(int i=0;a[i]!=(char)0 && s==0;++i)
    {
        if(a[i]<b[i])s=-1;
        if(a[i]>b[i])s=1;
    }
    cout<<s;
    return 0;
}
