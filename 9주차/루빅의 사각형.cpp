#include <stdio.h>
char arr[5][5];
int res1[7][3], res2[7][3], res_level = 8;

int count()
{
    int i, j, cnt = 0;
    for (i=0;i<4;++i)
        for (j=0;j<4;++j)
            if (arr[i][j] == i*4 + j + 1)
                cnt++;
    return cnt;
}

void rotate_x(int x)
{
    arr[x][4] = arr[x][3];
    arr[x][3] = arr[x][2];
    arr[x][2] = arr[x][1];
    arr[x][1] = arr[x][0];
    arr[x][0] = arr[x][4];
}

void rotate_y(int y)
{
    int i;
    for (i = 4; i > 0; i--)
        arr[i][y] = arr[i - 1][y];
    arr[0][y] = arr[4][y];
}

void dfs(int level)
{
    int i, j, cnt = count();
    if (cnt < (level - 3) * 4) return;
    if (cnt == 16) {
        res_level = level;
        for (i = 0; i < level; i++) {
            res2[i][0] = res1[i][0];
            res2[i][1] = res1[i][1];
            res2[i][2] = res1[i][2];
        }
        return;
    }
    if (level + 1 > res_level) return;

    res1[level][0] = 1;
    for (i = 0; i < 4; i++) {
        res1[level][1] = i + 1;
        for (j = 1; j < 4; j++) {
            rotate_x(i);
            res1[level][2] = j;
            dfs(level + 1);
        }
        rotate_x(i);
    }

    res1[level][0] = 2;
    for (i = 0; i < 4; i++) {
        res1[level][1] = i + 1;
        for (j = 1; j < 4; j++) {
            rotate_y(i);
            res1[level][2] = j;
            dfs(level + 1);
        }
        rotate_y(i);
    }
}

void input()
{
    int i, j;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            scanf("%d", &arr[i][j]);
}

void output()
{
    int i;
    printf("%d\n", res_level);
    for (i=0; i<res_level;i++)
    {
        printf("%d%d%d\n", res2[i][0], res2[i][1], res2[i][2]);
    }
}

int main()
{
    input();
    dfs(0);
    output();
    return 0;
}
