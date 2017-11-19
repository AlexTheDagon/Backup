#include <iostream>
#include <set>
using namespace std;

int main()
{

set<int>  st;
st.insert(3);
st.insert(1);
st.insert(10);
for(set<int>::iterator it=st.begin();it!=st.end();++it)
{
    		cout<<*it<<" ";
}
    return 0;
}
