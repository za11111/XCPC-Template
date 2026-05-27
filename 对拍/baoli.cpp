#include <bits/stdc++.h>

using namespace std;

int main ()
{
    freopen("in.in", "r", stdin);      //读入数据生成器造出来的数据
    freopen("baoli.txt", "w", stdout);
    int a,b;
    cin>>a>>b;
    if(a + b >= 8)
        cout<<0;
    else
        cout<<a+b;
}