//�Ŷ��� ������ ͼ�� ��5.2 Ҳ�ǲ��鼯 ��ͨ��ͼ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
//int tree[100001];//10000001����ֱ�ӱ�ջ forѭ��10000000���ᱬջ
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
    int m;//���� �������̶�10000000
    while(scanf("%d",&m) != EOF)
    {
        int i;
        int a,b;
        //int sum[10000001];//sum[i]��ʾ��iΪ���ڵ����ͨ��ͼ�е�ĸ��� tree[i] = -1ʱ��Ч
        int * sum = (int *)malloc(10000001 * sizeof(int));
        for(i = 0; i < 10000000; i++)
        {
            tree[i] = -1;
            sum[i] = 1;//��ʼ״̬ ÿ�����Ƕ�����
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
            if(tree[i] == -1 && res < sum[i])//�Ǹ� ����ͨ��ͼ������
                res = sum[i];
        }
        printf("%d\n",res);
    }

    return 0;
}
