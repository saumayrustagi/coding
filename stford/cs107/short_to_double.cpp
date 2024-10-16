#include <iostream>
using namespace std;

int main(){
	short s = 45;                            // 00000000 00101101
	// int i = *(int *)&s; // xxxxxxxx xxxxxxxx 00000000 00101101
	double d = *(double *)&s;
	cout<<s<<' '<<d<<' '<<endl;
	return 0;
}
