#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <vector>
#define maxn 50005
using namespace std;
struct point
{
    long long x,y;
    point(){}
    point(long long _x,long long _y):x(_x),y(_y){}
    point operator -(const point p)
    {
        return point(x - p.x,y - p.y);
    }
    long long norm2()
    {
        return x * x + y * y;
    }
}p[maxn],c;
typedef set <pair<long long,int> > SET;
SET S;
SET::iterator it;
long long ab(long long x)
{
    return x >= 0?x : -x;
}
bool cmp(const point &a,const point &b)//for sort
{
    return a.x < b.x;
}
int n,l;
long long r;
int f[maxn],ra[maxn];
bool has[maxn];
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
void un(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a != b)
    {
        if(ra[a] > ra[b])
        {
            f[b] = a;
            ra[a] += ra[b];
        }
        else
        {
            f[a] = b;
            ra[b] += ra[a];
        }
    }
}
void gao()
{
    S.clear();
    int front = 1;
    int a,b;
    for(int i = 1;i <= n;i++)
    {
        while(ab(p[i].x - p[front].x) > l)
        {
            S.erase(make_pair(p[front].y,front));
            front++;
        }
        it = S.insert(make_pair(p[i].y,i)).first;
        if(it != S.begin())
        {
            it--;
            if(ab(p[i].y - (it -> first)) <= l)
            {
                a = i;
                b = it -> second;
                un(a,b);
            }
            it++;
        }
        it++;
        if(it != S.end() && ab(p[i].y - (it -> first)) <= l)
        {
            a = i;
            b = it -> second;
            un(a,b);
        }
    }
}
int main()
{
    while(scanf("%d %lld %d",&n,&r,&l) == 3)
    {
        fill(ra,ra + n + 1,1);
        l /= 2;
        for(int i = 1;i <= n;i++)
            f[i] = i;
        for(int i = 1;i <= n;i++)
            scanf("%lld %lld",&p[i].x,&p[i].y);
        sort(p + 1,p + n + 1,cmp);
        scanf("%lld %lld",&c.x,&c.y);
        gao();
        int ans = 0;
        memset(has,0,sizeof(has));
        for(int i = 1;i <= n;i++)
        {
            if((p[i] - c).norm2() <= r * r)
            {
                int fuck = find(i);
                if(!has[fuck])
                {
                    ans += ra[fuck];
                    has[fuck] = true;
                }
            }
        }
        printf("%d\n",ans);
    }
}