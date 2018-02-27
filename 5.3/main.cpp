//�Ŷ��� ������ ͼ�� ��5.3 ����С������ Kruskal�㷨 �Ȱѱ߰�Ȩֵ��С�������� Ȼ��ÿ���ߵ��������������ͬһ������ϲ�
//�ٰѸñߵ�Ȩֵ�ۼӵ�����ͨͼ��

//���ϱ������������㷨 ѧ��ɢʱ�������prime�㷨
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

struct edge//����� ��Ȩ
{
    int a,b;
    int cost;
    //����< д��!
    bool operator < (const edge &A) const
    {
        if(cost < A.cost) return true;
        else return false;
    }
}edge[6000];//���4950����

int main()
{
    int n;//����
    while(scanf("%d",&n)!= EOF)
    {
        int m = n * (n - 1) / 2;//���� ��ȫ��ͨͼ
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

        int ans = 0;//��С��������ıߵ�Ȩֵ�ۼ�
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
