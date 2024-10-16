#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, multiply;
    scanf("%d%d%d\n", &m, &n, &multiply);

    char str[m][n];
    for (int i = 0; i < m; ++i)
    {
        scanf("%s", str[i]);
        for (int j = 0; j < multiply; ++j){
            for (char c : str[i])
            {
                for(int k = 0; k<multiply; ++k){
                    printf("%c", c);
                }
            }
            printf("\n");
        }
    }
    return 0;
}