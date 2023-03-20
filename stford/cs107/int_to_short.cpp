#include <iostream>
using namespace std;

int main(){
	// int a = 37;
	// float f = *(float *)&a;
	// cout<<f<<endl;

	// float f = 7.0;
	// short s = *(short*)&f;
	// cout<<s<<endl;

	// int a = 1+((1<<30)-1)*2;
	// short s = *(short*)&a;
	// cout << a <<' '<< s <<'\n';

	int a = (1<<15) + (1<<18); // 00000000 00000100 10000000 00000000
	short s = *(short*)&a;                       // 10000000 00000000

	/* 
		While I show the binary as Big-Endian, computers work with Little-Endian so it would be
		00000000 00000001 00100000 00000000 <- int a
		00000000 00000001 <- short s
	*/

	cout << (a-(1<<18)) << ' ' << s << ' ' << ((s == (short)(1<< 15)) ? "\nyes! only takes the first 15 bits." : "some error!") << '\n';

	return 0;
}

// 32768 -32768 
// yes! only takes the first 15 bits.
