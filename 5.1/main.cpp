//九度书 第五章图论 例5.1并查集 连通子图
#include <stdio.h>

int tree[1001];//双亲节点法表示树 用数组 tree[x]是x的双亲
//集合用树表示 合并两个集合 把一个的根作为另一个的根（一个树变另一个的子树）
int findRoot(int x)//找根节点（递归实现） 并压缩路径
{
    if(tree[x] == -1) return x;
    else
    {
       int tmp = findRoot(tree[x]);//递归找根节点tmp 并返回tmp
       tree[x] = tmp;//x的双亲变为tmp
       return tmp;
    }
}
int main()
{
    int n,m;//n是节点数 m是边数
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == 0) break;
        int i;
        int a,b;//一条边的两个点  这题是无向图
        //初始化树的数组
        for(i = 0;i < n; i++)
        {
            tree[i] = -1;
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d%d",&a,&b);
            a = findRoot(a);
            b = findRoot(b);
            if(a != b)
            {
                tree[a] = b;//把a的集合根变为b的子树
            }
        }

        int ans = 0;//需要增加几条边图才联通 n个联通子图需要增加n-1条边
        for(i = 0;i < n; i++)
        {
            if(tree[i] == -1)
                ans ++;//有几个联通子图
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
