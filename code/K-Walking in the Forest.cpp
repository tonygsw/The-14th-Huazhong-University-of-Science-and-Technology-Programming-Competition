/*
    data:2018.5.22
    author:gsw
    link:https://www.nowcoder.com/acm/contest/106/K
*/
#define ll long long
#define IO ios::sync_with_stdio(false);

#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005

ll l,r,mid;
int n,k;
ll dis[maxn];
bool judge(ll d)
{
    ll tem=0;int kk=0;
    for(int i=0;i<n-1;i++)
    {
        if(dis[i]>d)return false;
        if(tem+dis[i]>d)
        {
            tem=dis[i];
            kk++;
        }
        else tem+=dis[i];
    }
    kk++;
    if(kk>k)return false;
    return true;
}
int main()
{
    l=r=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        scanf("%lld",&dis[i]);
        r+=dis[i];
    }ll mid=0;
    while(l<r-1)
    {
        mid=(l+r)>>1;
        if(judge(mid))r=mid;
        else l=mid;
    }
    printf("%lld\n",r);
    return 0;
}
