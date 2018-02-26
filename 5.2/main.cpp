//九度书 第五章 图论 例5.2 也是并查集 联通子图
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
//int tree[100001];//10000001运行直接爆栈 for循环10000000不会爆栈
int * tree = (int *)malloc(10000001 * sizeof(int));
//memset(tree, 0, sizeof(tree));
int findRoot(int x)
{
    if(tree[x] == -1) return x;
    else
    {
      int tmp = findRoot(tree[x]);
      tree[x] = tmp;
      return tmp;
    }
}

int main()
{
    int m;//边数 总人数固定10000000
    while(scanf("%d",&m) != EOF)
    {
        int i;
        int a,b;
        //int sum[10000001];//sum[i]表示以i为根节点的连通子图中点的个数 tree[i] = -1时有效
        int * sum = (int *)malloc(10000001 * sizeof(int));
        for(i = 0; i < 10000000; i++)
        {
            tree[i] = -1;
            sum[i] = 1;//初始状态 每个点是独立的
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d%d",&a,&b);
            a = findRoot(a);
            b = findRoot(b);
            if(a != b)
            {
                tree[a] = b;
                sum[b] = sum[b] + sum[a];
            }
        }

        int res = 1;
        for(i = 0; i < 10000000; i++)
        {
            if(tree[i] == -1 && res < sum[i])//是根 找连通子图最多点数
                res = sum[i];
        }
        printf("%d\n",res);
    }

    return 0;
}
