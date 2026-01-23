//
// Created by ZA on 2026/1/14.
//
#include <bits/stdc++.h>

using namespace std;
const int N = ;
long long dp[N][N];
int n,m;
void floyd()
{
    for(int k = 1;k <= n;k++) //以k为中转点
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}
int main()
{

    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            dp[i][j] = 1e18;//不能设为longmax,后面dp[i][k]+dp[k][i]会爆ll
            if(i == j)
                dp[i][j] = 0;
        }
    }
    for(int i =1;i <= m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        dp[u][v]=min(dp[u][v],w);//重边取最小
        dp[v][u]=min(dp[v][u],w);
    }
    floyd();
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }

}