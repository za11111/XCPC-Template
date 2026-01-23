#include <bits/stdc++.h>

using namespace std;
const int N = ;
int a[N];
int st[N][26];
void init(int n)
{
    for(int i = 0;i < n;i++)
    {
        st[i][0] = a[i];
    }
    for(int j = 1;(1 << j) <= n;j++)
    {
        for(int i = 0;i + (1 << j) <= n;i++)
        {
            st[i][j] = max(st[i][j - 1],st[i + (1 << j - 1)][j - 1]);

        }
    }
}
int query(int l,int r)
{
    int k = log2(r-l+1);//向下取,1<<k + 1<<k  >= r-l+1 可以覆盖
    //左右半边 l~l+1<<k-1, r-(1<<k)+1 ~ r
    //1-6分成1-4,3-6 k = 2
    return max(st[l][k],st[r-(1 << k) + 1][k]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0 ;i < n;i++)
    {
        cin>>a[i];
    }
    init(n);
    for(int i  =0; i < m;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l-1,r-1)<<'\n';
    }
}