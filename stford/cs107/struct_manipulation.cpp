#include <iostream>
using namespace std;

typedef struct fractum{
	int num; int denom;
} fractum;

int main(){
	fractum pi;
	cout<<((((fractum *)&(pi.denom))->denom=33))<<endl;
	return 0;
}
