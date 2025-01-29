#include <iostream>
#include <string>

using namespace std;

void solution()
{
	int n;
	// string s;
	char c;
	cin >> n;
	cin.ignore(100, '\n');
	int choice[2] = {0, 0};
	while (n--)
	{
		c = cin.get();
		// cout<<c<<'\n';
		cin.ignore(100, '\n');
		if (c == 'F')
			choice[0]++;
		else
			choice[1]++;
		// cout<<choice[0]<<choice[1];
	}
	cout << (choice[0] - choice[1] >= 1 ? "Yes" : "No");

	return;
}

void solve(int n)
{
	do
	{
		solution();
	} while (--n);
	return;
}

int main(int argc, char *argv[])
{
	solve(1);
	return 0;
}
