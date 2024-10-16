#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
	for (int& n: a)
	{
		cout << n;
	}
	return 0;
}