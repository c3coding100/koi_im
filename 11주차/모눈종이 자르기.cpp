#include <stdio.h>
#define MAXN 700004

int Lx, Ly;
int N;
int a[MAXN+2][2];
int AnsNum = 0, AnsMax = 0;

void input()
{
    int i;
    scanf("%d%d", &Lx, &Ly);
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
    a[N+1][0] = a[1][0];
    a[N+1][1] = a[1][1];
}

int abs(int a)
{
    if (a < 0) return a * (-1);
    return a;
}

int length(int x1, int y1, int x2, int y2)
{
    int sum = 0;
    while (1) {
        if (y1 == 0 && x1 != Lx) {
            if (y2 == 0 && x2 > x1) {
                sum += (x2 - x1);
                return sum;
            }
            else {
                sum += (Lx - x1);
                x1 = Lx;
            }
        }
        else if (x1 == Lx && y1 != Ly) {
            if (x2 == Lx && y2 > y1) {
                sum += (y2 - y1);
                return sum;
            }
            else {
                sum += (Ly - y1);
                y1 = Ly;
            }
        }
        else if (y1 == Ly && x1 != 0) {
            if (y2 == Ly && x2 < x1) {
                sum += (x1 - x2);
                return sum;
            }
            else {
                sum += x1;
                x1 = 0;
            }
        }
        else if (x1 == 0 && y1 != 0) {
            if (x2 == 0 && y2 < y1) {
                sum += (y1 - y2);
                return sum;
            }
            else {
                sum += y1;
                y1 = 0;
            }
        }
    }
    return 0;
}
void process()
{
    int i, sum = 0, s, tmp;
    bool chk = 0, chk2 = 1;
    for (s = 1; s <= N; s++) {
        if ((a[s][0]==a[s + 1][0] && (a[s][0]==0 || a[s][0]==Lx))
            || (a[s][1]==a[s + 1][1] && (a[s][1]==0 || a[s][1]==Ly))) {
            chk = 1;
            break;
        }
    }

    if( chk==0) {
        AnsNum = 1;
        AnsMax = Lx + Lx + Ly + Ly;
        for (s = 1; s <= N; s++) {
            AnsMax += abs(a[s][0]-a[s+1][0]) + abs(a[s][1]-a[s+1][1]);
        }
        return;
    }

    tmp = s + 1;
    if (tmp > N) tmp = 1;
    for (i = 1; i <= N; i++) {
        s++;
        if (s > N) s = 1;
        if ((a[s][0]==a[s+1][0] && (a[s][0]==0 || a[s][0]==Lx))
            || (a[s][1]==a[s+1][1] && (a[s][1]==0 || a[s][1]==Ly))) {
            if (chk2 == 0) {
                AnsNum++;
                sum += length(a[tmp][0], a[tmp][1], a[s][0], a[s][1]);
                if (AnsMax < sum)
                    AnsMax = sum;
                sum = 0;
                chk2 = 1;
            }
            tmp = s + 1; if (tmp > N) tmp = 1;
        }
        else {
            chk2 = 0;
            sum += abs(a[s][0]-a[s+1][0]) + abs(a[s][1]-a[s+1][1]);
        }
    }
}
void output()
{
    printf("%d %d\n", AnsNum, AnsMax);
}
int main()
{
    input();
    process();
    output();
    return 0;
}
