#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string s;
    cin >> s;
    const int N = s.size();
    // const int ans_size = (N & 1) ? (N / 2) + 1 : (N / 2);
    string ans;

    for (int i = 0; i < N; ++i)
    {
        if (s[i] == '.')
        {
            ans += '0';
        }
        if (s[i] == '-')
        {
            if (s[i + 1] == '.')
                ans += '1';
            if (s[i + 1] == '-')
                ans += '2';
            ++i;
        }
    }

    for (char &c : ans)
        cout << c;

    cout << '\n';

    return 0;
}