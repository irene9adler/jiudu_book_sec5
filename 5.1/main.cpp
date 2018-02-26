//�Ŷ��� ������ͼ�� ��5.1���鼯 ��ͨ��ͼ
#include <stdio.h>

int tree[1001];//˫�׽ڵ㷨��ʾ�� ������ tree[x]��x��˫��
//����������ʾ �ϲ��������� ��һ���ĸ���Ϊ��һ���ĸ���һ��������һ����������
int findRoot(int x)//�Ҹ��ڵ㣨�ݹ�ʵ�֣� ��ѹ��·��
{
    if(tree[x] == -1) return x;
    else
    {
       int tmp = findRoot(tree[x]);//�ݹ��Ҹ��ڵ�tmp ������tmp
       tree[x] = tmp;//x��˫�ױ�Ϊtmp
       return tmp;
    }
}
int main()
{
    int n,m;//n�ǽڵ��� m�Ǳ���
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == 0) break;
        int i;
        int a,b;//һ���ߵ�������  ����������ͼ
        //��ʼ����������
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
                tree[a] = b;//��a�ļ��ϸ���Ϊb������
            }
        }

        int ans = 0;//��Ҫ���Ӽ�����ͼ����ͨ n����ͨ��ͼ��Ҫ����n-1����
        for(i = 0;i < n; i++)
        {
            if(tree[i] == -1)
                ans ++;//�м�����ͨ��ͼ
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
