#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char* argv[]){
	int i=0;
	while(i<25){
		cout << i << ' ' << argv[1][i] << '\n';
		++i;
	}
	return 0;
}
