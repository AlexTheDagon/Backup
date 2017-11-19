#include <iostream>
#include <fstream>
using namespace std;
string s;
int a[20005],maxx;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();++i)a[i+1]=s[i]-'a'+1;
    for(int i=1;i<=s.size();++i)a[i]+=a[i-1];
    for(int i=1;i<=10;++i)maxx=max(maxx,a[i]);
    for(int i=11;i<=s.size();++i)
    {
        maxx=max(a[i]-a[i-10],maxx);
    }
    cout<<maxx;
    return 0;
}
