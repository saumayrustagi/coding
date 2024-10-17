#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int COORD = 3;
    int n;
    cin >> n;

    // vector<vector<int>> v(n, vector<int>(COORD, -1));

    int x, y, z;
    x = y = z = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0, tmp; j < COORD; ++j)
        {
            cin >> tmp;
            switch (j)
            {
            case 0:
                x += tmp;
                break;
            case 1:
                y += tmp;
                break;
            case 2:
                z += tmp;
                break;
            }
        }
    }

    cout << ((x == 0 && y == 0 && z == 0) ? "YES" : "NO");
    cout << '\n';

    return 0;
}