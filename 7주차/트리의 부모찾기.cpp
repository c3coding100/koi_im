#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100111;
vector<int> a[MAX];
int parent[MAX];
bool check[MAX];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        int u,v,w;
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    check[1] = true;
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i=0; i<a[x].size(); i++) {
            int y = a[x][i];
            if (!check[y]) {
                check[y] = true;
                parent[y] = x;
                q.push(y);
            }
        }
    }
    for (int i=2; i<=n; i++) {
        printf("%d\n",parent[i]);
    }
    return 0;
}
