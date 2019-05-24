#include <cstdio>
struct {
    int std, vote, time;
} cand[100001];

int main()
{
    int n, m, k, i, j;
    scanf("%d", &n);
    m = 0;
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        int std;
        scanf("%d", &std);
        for (j = 0; j < m; j++)
            if (cand[j].std == std)
            {
                cand[j].vote++;
                break;
            }
        if (j < m)
            continue;
        if (m < n)
        {
            j = m;
            m++;
        }
        else
        {
            j = 0;
            for (int t = 1; t < m; t++)
                if ((cand[t].vote < cand[j].vote) ||
                    (cand[t].vote == cand[j].vote && cand[t].time < cand[j].time))
                {
                    j = t;
                }
        }
        cand[j].std = std;
        cand[j].vote = 1;
        cand[j].time = i;
    }
    for (i = 0; i < m; i++)
            printf("%d ", cand[i].std);
    return 0;
}
