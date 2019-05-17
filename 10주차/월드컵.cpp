#include <cstdio>
using namespace std;
#define n 6 // n denotes the number of teams
#define m 15 // m denotes the number of games = n choose 2
int win[n], lose[n], draw[n];
int genWin[n], genLose[n], genDraw[n];
int gen[m], p1[m], p2[m];
bool feasibility;
int ans[4];
void recur( int cnt )
{
    if (cnt == m)
    {
        feasibility = true;
        return;
    }
    int n1 = p1[cnt];
    int n2 = p2[cnt];
    genWin[n1]++;
    genLose[n2]++;
    if (genWin[n1]<=win[n1] && genLose[n2]<=lose[n2])
        recur(cnt+1);
    genWin[n1]--;
    genLose[n2]--;
    genDraw[n1]++;
    genDraw[n2]++;
    if (genDraw[n1]<=draw[n1] && genDraw[n2]<=draw[n2])
        recur(cnt+1);
    genDraw[n1]--;
    genDraw[n2]--;
    genLose[n1]++;
    genWin[n2]++;
    if (genLose[n1]<=lose[n1] && genWin[n2]<=win[n2])
        recur(cnt+1);
    genLose[n1]--;
    genWin[n2]--;
}
void process()
{
    int i, j, cnt = 0;
    feasibility = false;
    for (i=0; i<n; i++)
    {
        genWin[i] = 0;
        genLose[i] = 0;
        genDraw[i] = 0;
        if (win[i]+lose[i]+draw[i] != n-1) return;
    }
    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
        {
            p1[cnt] = i;
            p2[cnt] = j;
            cnt++;
        }
    recur(0);
}
int main()
{
    for (int loop = 0; loop<4; loop++)
    {
        for (int i=0; i<n; i++)
            scanf("%d%d%d", &win[i], &draw[i], &lose[i]);

        process();

        if (feasibility)
            ans[loop] = 1;
        else
            ans[loop] = 0;
    }

    for (int loop = 0; loop<4; loop++)
        printf("%d ", ans[loop]);

    return 0;
}
