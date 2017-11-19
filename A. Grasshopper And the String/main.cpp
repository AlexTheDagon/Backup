#include <iostream>

using namespace std;
string s,v;
int p=-1,minn=0,ss;
int main()
{
    cin>>s;
    v="AEIOUY";
    for(int i=0;i<s.size();++i)
    {
        for(int j=0;j<v.size();++j)
        {
            if(s[i]==v[j])
            {
                minn=max(minn,(i-p));
                p=i;
            }
        }
    }
    ss=s.size();
    minn=max(minn,(ss-p));
    cout<<minn;
    return 0;
}
