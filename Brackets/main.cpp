#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
ifstream in("brackets.in");
ofstream out("brackets.out");
int t,n,cnt;
string s;
stack <char> st;
stack <pair<char,int> > stt;
vector<int> v1,v2;
int main()
{
    in>>t;
    while(t)
    {
        --t;
        in>>n>>s;
        for(auto c:s)
        {
            if(st.size()!=0)
            {
                if(st.top()=='(' && c==')')st.pop();
                else st.push(c);
            }
            else st.push(c);
        }
        if(st.size()==0)
        {
            for(int i=0;i<s.size();++i)
            {
                if(stt.size()!=0)
                {
                    if(stt.top().x=='(' && s[i]==')')
                    {
                        if(cnt%2==1)
                        {
                            v1.pb(stt.top().y);
                            v1.pb(i);
                        }
                        else
                        {
                            v2.pb(stt.top().y);
                            v2.pb(i);
                        }
                        ++cnt;
                        stt.pop();
                    }
                    else stt.push(mp(s[i],i));
                }
                else stt.push(mp(s[i],i));
            }
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            out<<v1.size()<<'\n';
            for(auto i:v1)out<<i+1<<" ";
            out<<'\n';
            out<<v2.size()<<'\n';
            for(auto i:v2)out<<i+1<<" ";
            out<<'\n';

        }
        else out<<"-1"<<'\n';
        while(!st.empty())st.pop();
        while(!stt.empty())stt.pop();
        v1.clear();
        v2.clear();
        s.clear();
    }
    return 0;
}
