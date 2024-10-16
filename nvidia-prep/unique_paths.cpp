#include <bits/stdc++.h>

using namespace std;

int uniquePathsRecursive(vector<vector<int>> arr, vector<vector<int>> paths, int r, int c, int x, int y)
{
	if (x == r || y == c)
		return 0;

	if (arr[x][y] == 1)
		return 0;

	if (x == r - 1 && y == c - 1)
		return 1;

	if (paths[x][y] != -1)
	{
		return paths[x][y];
	}

	return paths[x][y] = uniquePathsRecursive(arr, paths, r, c, x + 1, y) + uniquePathsRecursive(arr, paths, r, c, x, y + 1);
}

int uniquePathsDP(vector<vector<int>> A, vector<vector<int>> paths, int r, int c, int x, int y)
{
	paths[x][y] = 1;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (A[i][j])
			{
				paths[i][j] = 0;
			}
			else if (i > 0 && j > 0)
				paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
			else if (i > 0)
			{
				paths[i][j] = paths[i - 1][j];
			}
			else if (j > 0)
			{
				paths[i][j] = paths[i][j - 1];
			}
		}
	}
	return paths[r - 1][c - 1];
}

int uniquePathsDP11(vector<vector<int>> A, int r, int c, int x, int y)
{
	vector<vector<int>> paths(r + 1, vector<int>(c + 1, 0));
	paths[x + 1][y] = 1;
	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			if (!A[i - 1][j - 1])
				paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
		}
	}
	return paths[r][c];
}

int uniquePathsDP1Row(vector<vector<int>> A, int r, int c, int x, int y)
{
	vector<int> path(c, 0);
	path[c - 1] = 1;
	for (int i = r - 1; i >= 0; --i)
	{
		for (int j = c - 1; j >= 0; --j)
		{
			if (A[i][j])
				path[j] = 0;
			else if (j < c - 1)
				path[j] += path[j + 1];
		}
	}
	return path[0];
}

int uniquePathsDPO1(vector<vector<int>> A, int r, int c)
{
	if (A[0][0])
		return 0;

	A[0][0] = 1;

	int i, j;

	for (i = 1; i < r; ++i)
	{
		if (!A[i][0])
			A[i][0] = A[i - 1][0];
		else
			A[i][0] = 0;
	}

	for (j = 1; j < c; ++j)
	{
		if (!A[0][j])
			A[0][j] = A[0][j - 1];
		else
			A[0][j] = 0;
	}

	for (i = 1; i < r; ++i)
	{
		for (j = 1; j < c; ++j)
		{
			if(A[i][j])
				A[i][j] = 0;
			else
				A[i][j] = A[i][j-1] + A[i-1][j];
		}
	}
	return A[r-1][c-1];
}

int uniquePaths(vector<vector<int>> A)
{
	int r = A.size();
	int c = A[0].size();

	// vector<vector<int>> paths(r, vector<int>(c, -1));

	return uniquePathsDPO1(A, r, c);
}

int main()
{
	vector<vector<int>> A = {{0, 0, 0},
							 {0, 1, 0},
							 {0, 0, 0}};

	cout << uniquePaths(A) << '\n';

	return 0;
}
