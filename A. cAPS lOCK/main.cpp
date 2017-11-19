#include <iostream>

using namespace std;
char a[100];
int sem,c1,c2;
int main()
{
    cin>>a;
    for(int i=1;a[i]!=(char)0;++i)
    {
        if(a[i]-'a'>=0)c1++;
        else c2++;
    }
    if(c1>0 && c2>1)sem=1;
    if(c2==0 && c1>1)sem=1;
    if(c1>0 && c2>0)sem=1;
    if(sem==0)
    {
        if(a[0]-'a'<0 && c1==0 && c2==0)a[0]=a[0]-'A'+'a';
        else
        {if(c2>0 && c1==0 && a[0]-'a'<0)a[0]=a[0]-'A'+'a';
        else if(a[0]-'a'>=0)a[0]=a[0]-'a'+'A';}
        for(int i=1;a[i]!=(char)0;++i)
        {
            if(a[i]-'a'<0)a[i]=a[i]-'A'+'a';
        }
    }
    for(int i=0;a[i]!=(char)0;++i)cout<<a[i];
    return 0;
}
