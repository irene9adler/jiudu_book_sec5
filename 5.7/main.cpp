//九度书 第五章 图论 例5.7 dijkstra求最短路径+最小花费
#include <stdio.h>
#include <vector>

using namespace std;

struct E
{
    int next;
    int c;
    int cost;
};
vector <E> edge[1001];
bool mark[1001];
int dis[1001];
int cost[1001];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == 0 && m == 0);
        int i,j;
        for(i = 1;i <= n;i++)
            edge[i].clear();
        for(i = 1;i <= n; i++)
        {
            dis[i] = -1;
            //cost[i] = 0;//?;
            mark[i] = false;
        }

        int a,b,c,d;
        for(i = 0;i < m; i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            E tmp;
            tmp.c = c;
            tmp.cost = d;
            tmp.next = b;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);
        }
        int S,T;
        scanf("%d%d",&S,&T);

        dis[S] = 0;
        mark[S] = true;

        int newp = S;
        for(i = 1; i <= n; i++)
        {
            for(j = 0;j < edge[newp].size();j++)
            {
                int t = edge[newp][j].next;
                int juli = edge[newp][j].c;
                int huafei = edge[newp][j].cost;
                if(mark[t] == true) continue;
                if(dis[t] == -1 || dis[t] > dis[newp] + juli || ((dis[t] == dis[newp] + juli) && (cost[t] > cost[newp] + huafei)))
                {
                    dis[t] = dis[newp] + juli;
                    cost[t] = cost[newp] + huafei;
                }
            }

            int min_ = 88888;
            for(j = 1;j <= n; j++)
            {
                if(mark[j] == true) continue;
                if(dis[j] == -1) continue;
                if(dis[j] < min_)
                {
                    min_ = dis[j];
                    newp = j;
                }
            }
            mark[newp] = true;
        }
        printf("%d  %d\n",dis[T],cost[T]);


    }
    return 0;
}
