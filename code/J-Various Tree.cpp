/*
    data:2018.5.20
    author:gsw
    link:https://www.nowcoder.com/acm/contest/106#question
*/
#define ll long long
#define IO ios::sync_with_stdio(false);

#include<math.h>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 1000005

int brainy[maxn];
int vis[maxn];
int getbrainy(int a)
{
    int ans=0;
    while(a>0)
    {
        if(a&1)ans++;
        a=a>>1;
    }
    return ans;
}
void init()
{
    for(int i=1;i<maxn;i++)
        brainy[i]=getbrainy(i);
    memset(vis,0,sizeof(vis));
}
class Step
{
    public:
        int x,st;
};
void bfs(int a,int b)
{
    Step be,ne;
    be.x=a;be.st=0;
    queue<Step> q;
    q.push(be);
    vis[be.x]=1;
    while(!q.empty())
    {
        be=q.front();
        q.pop();
        if(be.x==b)
        {
            cout<<be.st<<endl;
            return;
        }

        if(!vis[be.x+1])
        {
            vis[be.x+1]=1;
            ne.x=be.x+1;ne.st=be.st+1;
            q.push(ne);
        }
        if((be.x-brainy[be.x])>=0&&!vis[be.x-brainy[be.x]])
        {
            vis[be.x-brainy[be.x]]=1;
            ne.x=be.x-brainy[be.x];ne.st=be.st+1;
            q.push(ne);
        }
        if((be.x-1)>=0&&!vis[be.x-1])
        {
            vis[be.x-1]=1;
            ne.x=be.x-1;ne.st=be.st+1;
            q.push(ne);
        }
        if(!vis[be.x+brainy[be.x]])
        {
            vis[be.x+brainy[be.x]]=1;
            ne.x=be.x+brainy[be.x];ne.st=be.st+1;
            q.push(ne);
        }
    }
}
int main()
{
    int a,b;
    init();
    scanf("%d%d",&a,&b);
    bfs(a,b);
}
