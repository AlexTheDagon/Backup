#include <iostream>
#include <fstream>
using namespace std;
ifstream in("random.in");
ofstream out("random.out");
int n;
int main()
{
    in>>n;
    if(n==1982)out<<"Robert Tarjan";
    else if(n==1986)out<<"Leslie Valiant";
    else if(n==1990)out<<"Alexander Razborov";
    else if(n==1994)out<<"Avi Wigderson";
    else if(n==1998)out<<"Peter Shor";
    else if(n==2002)out<<"Madhu Sudan";
    else if(n==2006)out<<"Jon Kleinberg";
    else if(n==2010)out<<"Daniel Spielman";
    else out<<"Subhash Khot";
    return 0;
}
