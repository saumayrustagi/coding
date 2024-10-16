#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);

    int road[100][2];

    int roadptr = 0;
    for (int i = 0, length, limit; i < n; ++i)
    {
        scanf("%d%d", &length, &limit);
        int j = roadptr;
        while (j < length + roadptr)
        {
            road[j][0] = limit;
            ++j;
        }
        roadptr = j;
    }

    roadptr = 0;
    for (int i = 0, length, actual; i < m; ++i)
    {
        scanf("%d%d", &length, &actual);
        int j = roadptr;
        while (j < length + roadptr)
        {
            road[j][1] = actual;
            ++j;
        }
        roadptr = j;
    }

    int maxDiff = 0;
    for(int i=0; i<100; ++i){
        maxDiff = max(maxDiff, road[i][1] - road[i][0]);
    }
    printf("%d\n", maxDiff);

    return 0;
}