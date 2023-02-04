#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	int n,m;
	cin>>n>>m;
	vector <string> s(n), t(m);
	while(n--)
		cin>>s[n];
	while(m--)
		cin>>t[m];

	int answer = 0;
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
