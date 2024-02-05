#include <iostream>
#include <vector>

using namespace std;

void fn1(int a){
	++a;
}

void fn2(int& a){
	++a;
}

int main()
{
	int a,b;
	a = 1; b = 1;
	fn1(a);
	fn2(b);
	cout << a << ' ' << b << '\n';
	return 0;
}
