#include <iostream>

using namespace std;
int n,a[1000],freq[1001],bucurie;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        freq[a[i]]++;
    }
    while(n>0)
    {
        for(int i=1;i<1001;++i)
        {
            if(freq[i]!=0)
            {
                bucurie++;
                freq[i]--;
                n--;
            }
        }
        bucurie--;
    }
    cout<<bucurie;

    return 0;
}
