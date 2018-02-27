//九度书 第五章 图论 例5.3 求最小生成树 Kruskal算法 先把边按权值从小到大排序 然后每个边的两个点如果不在同一集合则合并
//再把该边的权值累加到该连通图中

//书上编码就用了这个算法 学离散时有手算的prime算法
#include <stdio.h>
#include <algorithm>

using namespace std;
int tree[101];
int findRoot(int x)
{
    if(tree[x] == -1)
        return x;
    else
    {
        int tmp = findRoot(tree[x]);
        tree[x] = tmp;
        return tmp;
    }
}

struct edge//无向边 带权
{
    int a,b;
    int cost;
    //重载< 写法!
    bool operator < (const edge &A) const
    {
        if(cost < A.cost) return true;
        else return false;
    }
}edge[6000];//最多4950条边

int main()
{
    int n;//点数
    while(scanf("%d",&n)!= EOF)
    {
        int m = n * (n - 1) / 2;//边数 完全连通图
        int i;
        for(i = 0;i < n; i++)
        {
            tree[i] = -1;
        }
        int a,b;
        for(i = 0;i < m; i++)
        {
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        sort(edge,edge + m);

        int ans = 0;//最小生成树里的边的权值累加
        for(i = 0;i < m; i++)
        {
            a = findRoot(edge[i].a);
            b = findRoot(edge[i].b);
            if (a != b)
            {
                tree[a] = b;
                ans = ans + edge[i].cost;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
