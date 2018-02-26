//九度书 第五章 图论 例5.5最短路问题 解法一 floyd算法（可以求图中任意两点间最短距离） 原理：邻接矩阵i->j 中间点k 更新更小的距离
#include <stdio.h>
int ans[101][101];//ans[i][j]最初表示直连的两点间距离 运行算法后表示任意两点i到j间最短距离

int main()
{
    int n,m;//n个点 m条边
    while(scanf("%d%d",&n,&m)!= EOF)
    {
        if(n == 0 && m == 0) break;
        int i,j,k;
        for(i = 0; i < n;i++)
        {
            for(j = 0;j < n; j++)
            {
                ans[i][j] = -1;//初值 表示点i到j不连通
            }
            ans[i][i] = 0;//自己到自己的距离为0
        }

        int a,b,c;
        for(i = 0; i < m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);//a b是点的名字
            ans[a][b] = ans[b][a] = c;//无向图 邻接矩阵是对称矩阵 现在图构造好了
        }

        for(k = 0; k < n; k++)//中间点k
        {
            for(i = 0;i < n; i++)
            {
                for(j = 0; j < n; j++)
                {
                    if(ans[i][k] == -1 || ans[k][j] == -1) continue;//k与i j任何一个不通 不用做中间点
                    if(ans[i][j] == -1 || ans[i][j] > ans[i][k] + ans[k][j])//i到j经过k距离更短 或i到j不直通 需要更新
                        ans[i][j] = ans[i][k] + ans[k][j];//更新
                }
            }
        }
        printf("%d\n",ans[1][n]);//点1到点n的最短距离
    }
    return 0;
}
