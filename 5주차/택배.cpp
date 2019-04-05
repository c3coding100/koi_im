#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=2222,M=11111; //
int n,c,m;
struct Box
{
    int a,b,t;
};
Box a[M];
int truck[N],x,v;
int ans;
int cmp(const Box &p,const Box &q)
{
    return p.b<q.b||(p.b==q.b&&p.a>q.a);
}
int min(int p,int q)
{
    return p<q?p:q;
}

int main()
{
    int i,j;
    scanf("%d%d%d",&n,&c,&m);
    for(i=0; i<m; ++i)
        scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].t);
    sort(a,a+m,cmp);
    ans=0;
    for(i=0; i<m; ++i)
    {
        x=0;
        for(j=a[i].a; j<a[i].b; ++j)
            if(truck[j]>x) x=truck[j];
        v=min(a[i].t,c-x);
        for(j=a[i].a; j<a[i].b; ++j)
            truck[j]+=v;
        ans+=v;
    }
    printf("%d\n",ans);
    return 0;
}
