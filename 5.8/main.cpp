//第五章 图论 例5.8 拓扑排序
//邻接链表
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

//最多100个点 100条边？
queue <int> Q;//存放入度为0的点
vector<int> edge[101];//链表数组表示边 edge[a]里存放以a为起点的边的重点b c d...来表示有向边
int rudu[101] = {0};//统计图中每个点的入度 初值为0
int main()
{
    int n,m;//n是本图点数 m是边数
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == 0 && m == 0) break;
        //清队列
        //清链表
        int i,j;
        while(Q.empty() == false) Q.pop();//清空队列
        for(i = 0; i < n; i++)
        {
            rudu[i] = 0;//每次都要入度初值置为0 否则上次的还存在里面
            edge[i].clear();//清空链表
        }


        //开始存图的信息
        int a,b;//表示一条边a起点b终点
        for(i = 0; i < m; i++)
        {
            scanf("%d%d",&a,&b);
            printf("一条边%d->%d\n",a,b);
            edge[a].push_back(b);//把b放入链表a的链中
            rudu[b]++;//b的入度+1
            printf("%d点的入度为%d\n",b,rudu[b]);
        }

        for( i = 0; i < n; i++)
        {
            if(rudu[i] == 0)
                {
                    Q.push(i);
                    printf("点%d入度为0，入队列\n",i);
                }
        }

        int cnt = 0;//统计已经拓扑排序的点数 每次出来一个入度为1的点就排序成功一个
        while(Q.empty() == false)
        {
            //取出队头的一个入度为0的点
            int now = Q.front();
            printf("点%d出队列\n",now);
            Q.pop();//弹出
            cnt ++;
            //删除以这个点为起点的所有边 把对应的终点入度-1
            for(j = 0; j < edge[now].size(); j++)//注意队列和链表不同的循环方式
            {
                //删除这条边 没有操作
                rudu[edge[now][j]] --;//a->b是now->j
                if(rudu[edge[now][j]] == 0)
                    Q.push(edge[now][j]);
            }

        }
        printf("cnt = %d\n",cnt);
        if(cnt == n) printf("拓扑排序成功 无环\n");
        else printf("有环\n");

    }
    return 0;
}
