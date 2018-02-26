//�Ŷ��� ������ͼ�� ��5.4 ������С������kruskal ΢����
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;
int tree [101];
int findRoot(int x)
{
    if(tree[x] == -1) return x;
    else
    {
       int tmp;
       tmp = findRoot(tree[x]);
       tree[x] = tmp;
       return tmp;
    }
}

struct edge
{
    int a,b;
    double cost;
    bool operator < (const edge &A)const{return cost < A.cost;}//����<
}edge[6000];

struct point
{
    double x,y;//������
    double distance(point A)//�����������뺯��  ��˵ struct�ﻹ����д����
    {
        double res;
        res = (x - A.x) * (x - A.x) + (y - A.y) * (y - A.y);
        return sqrt(res);
    }
}point[101];

int main()
{
    int n;//����
    while(scanf("%d",&n) != EOF)
    {
        int i,j;
        for(i = 0;i < n;i++)
        {
            scanf("%lf%lf",&point[i].x,&point[i].y);//0 1 2
        }
        for(i = 0;i < n; i++)
            tree[i] = -1;
        int m = n * (n - 1) / 2;//����
        int loc = 0;
        double ans = 0;//Ҫ��Ļ�����С��������Ȩֵ
        int a,b;
        for(i = 0; i < n; i++)//0 1 2
        {
            for(j = i + 1; j < n; j++)//0->1 0->2 1->2
            {
                edge[loc].a = i;//0
                edge[loc].b = j;//1
                edge[loc].cost = point[i].distance(point[j]);//1.414
                printf("%d -> %d cost = %lf\n",i,j,edge[loc].cost);
                loc ++;
            }
        }//������ȫ��ͨͼ�͸㶨�� ���濪ʼ��kruskal����С������Ȩֵ

        sort(edge,edge + loc);
        for(i = 0; i < loc; i++)
        {
            a = findRoot(edge[i].a);
            b = findRoot(edge[i].b);
                if(a != b)
                {
                    tree[a] = b;
                    printf("this egde cost = %lf\n",edge[i].cost);
                    ans = ans + edge[i].cost;
                    printf("now ans = %lf\n",ans);
                }
        }
       printf("%0.2lf\n",ans);
    }
    return 0;
}
