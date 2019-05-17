#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<double> a, b, c;
int n, m;
double average(vector<double> a)
{
    double sum = 0;
    for(size_t l1 = 0; l1 < a.size(); l1++)
    {
        sum += a[l1];
    }
    return sum / (double)a.size();
}
int main(void)
{
    int l1;
    scanf("%d %d",&n,&m);
    a.resize(n);
    for(l1=0;l1<n;l1++)
    {
        scanf("%lf",&a[l1]);
    }
    sort(a.begin(), a.end());

    for(l1 = m; l1 < n - m; l1++) b.push_back(a[l1]);
    for(l1 = m; l1 < n - m; l1++) c.push_back(a[l1]);
    for(l1=0;l1<m;l1++){
        c.push_back(a[m]);
        c.push_back(a[n-m-1]);
    }

    printf("%.2lf\n%.2lf\n", average(b), average(c));

    return 0;
}
