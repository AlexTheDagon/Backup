#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cern.in");
ofstream out("cern.out");
char c;
int t;
int sens;
int dist[]={1,5,1,5,1,5};
char c[]={'A','B','C','D','E','F'};
int main()
{
    in>>c>>sens>>t;
    t=t%1080;

    return 0;
}
///vedem sensul de parcurgere
///vedem de unde pornim
///tinem unitati de 60 grade
