#include <bits/stdc++.h>

using namespace std;
int main()
{
    while (1) //一直循环，直到找到不一样的数据
    {
        system("data.exe");
        system("baoli.exe");
        system("std.exe");
        if (system("fc std.txt baoli.txt")) //当 fc 返回1时，说明这时数据不一样
            break;                          //不一样就跳出循环
    }
    return 0;
}