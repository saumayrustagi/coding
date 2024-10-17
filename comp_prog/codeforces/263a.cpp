#include <iostream>

using namespace std;

int main()
{
    const int N = 5;
    const int MID = N / 2;

    bool cell;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> cell;
            if (cell == 1)
            {
                cout << (abs(MID - i) + abs(MID - j)) << '\n';
                return 0;
            }
        }

    return 0;
}