#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
char s[80];
char a[80];
char *poz;
int main()
{
    in.get(a,30);
    poz=strchr(a,'a');
    while(poz!=NULL)
    {
        out<<poz<<" ";
        poz=strchr(a,'a');

    }
    return 0;
}
