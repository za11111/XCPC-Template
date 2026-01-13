const int N = 200003;
int f[N]; //集
int rnk[N];//秩(树高度)
int sz[N];//集合元素个数
void init_set(int n)
{
    for(int i = 1;i <= n;i++)
    {
        f[i] = i;
        rnk[i] = 1;
        sz[i] = 1;
    }
}
int find_set(int x)
{
    if(x != f[x])
    {
        f[x] = find_set(f[x]);
    }
    return f[x];
}

void merge_set(int x,int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x != y)
    {
        if(rnk[x] < rnk[y])
            swap(x, y);
        f[y] = x; //矮的根合并到高的根上
        if(rnk[x] == rnk[y])
            rnk[x]++;
        sz[x] += sz[y];
    }
}

bool same_set(int x,int y)
{
    return find_set(x) == find_set(y);
}
