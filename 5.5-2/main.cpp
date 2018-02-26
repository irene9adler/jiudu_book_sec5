//九度书 第五章 图论 例5.5变形 用dijkstra算法（求一个点到图中任意一点间最短距离） 邻接链表
//注意 这两个算法应该是不限制用邻接矩阵还是邻接链表表示图的 这两种写法都要顺
#include <stdio.h>
#include <vector>

using namespace std;

struct E
{
    int next;//边的弧头点
    int c;//以该点为弧尾的边的长度
};//最多100个点

bool mark[101];//mark[i]表示点是否在K集合中
vector <E> edge[101];//每个点的邻接链表 对于无向图。。。
int dis[101];//距离 当mark[i]为true时 dis[i] 表示点1到点i的最短路径 否则？

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == 0 && m == 0) break;
        int i,j;
        for(i = 1;i <= n; i++)
            edge[i].clear();//清空点i的邻接链表
        int a,b,c;//用于收边信息 建立邻接链表
        for(i = 1;i <= m;i++)
        {
           scanf("%d%d%d",&a,&b,&c);
           E tmp;
           tmp.next = b;
           tmp.c = c;
           edge[a].push_back(tmp);
           tmp.next = a;
           edge[b].push_back(tmp);
        }//无向图邻接链表构建的特点

        for(i = 1;i <= n; i++)
        {
            dis[i] = -1;//表示初始时1到i点不可达
            mark[i] = false;
        }//初始状态

        dis[1] = 0;//起点是1 要求的是1到任一点的最短距离
        mark[1] = true;//起点放到集合K

        int newp = 1;//新放入集合K的点

        for(i = 1;i < n;i++)
        {
            for(j = 0;i < edge[newp].size(); j++)//看newp的邻接链表 找以newp为起点的边
            {
                int t = edge[newp][j].next;
                int c = edge[newp][j].c;
                if(mark[t] == true) continue;//已经在集合k了 跳过
                if(dis[t] == -1 || dis[t] > dis[newp] + c)//1到t不可达或。。。
                     dis[t] = dis[newp] + c;//得到起点到t的最短距离  更新dis[t]
                     printf("更新dis[%d]的值为%d\n",t,dis[t]);
            }
            //这里先把newp邻接的点的dis算出来
            //下面找最小的dis 对应的点真正放入集合K

            int min_ = 88888;
            for(j = 1;j <= n;j++)//上面求了可求的dis值 遍历所有节点 找最小dis 对应的点是要新加入集合k的点newp了 将newp放入集合K
            {
                if(mark[j] == true) continue;
                if(dis[j] == -1) continue;
                if(dis[j] < min_)
                {
                    min_ = dis[j];
                    newp = j;
                }
            }
            mark[newp] = true;//新的点放入集合K 再从这个点开始找可以新放入集合K的点
            printf("将点%d放入集合\n",newp);
         }
         printf("%d\n",dis[n]);
    }
    return 0;
}
