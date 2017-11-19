#include <iostream>

using namespace std;
char c[20];
int k,sem,sem2,v;
int main()
{
    cin>>k;
    for(int i=1;i<=k;++i)
    {
        sem=0;
        sem2=1;
        cin>>c;
        if(c[0]=='B' && c[1]==' ')sem=1;
        if(c[0]-'0'<43 && c[0]-'0'>16 && c[1]-'0'<43 && c[1]-'0'>16 && c[2]==' ')v++;
        else sem2=1;
        cin>>c;
        if(sem==1)
        {

        }
    }
    return 0;
}
