#include<iostream.h>
#include<fstream.h>
int CMMDC(int x, int y)
{ while(x!=y)
	{if(x>y)
		x=x-y;
	else
		y=y-x;
	}
return x;
}
 int main()
 { int x,y, k=1;
 ifstream f("NUMERE.IN");
 ofstream g("NUMERE.OUT");
 f>>x>>y;
	 {g<<CMMDC(x,y)<<endl;}
 g.close();
 }
