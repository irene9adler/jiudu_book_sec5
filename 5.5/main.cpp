//�Ŷ��� ������ ͼ�� ��5.5���·���� �ⷨһ floyd�㷨��������ͼ�������������̾��룩 ԭ���ڽӾ���i->j �м��k ���¸�С�ľ���
#include <stdio.h>
int ans[101][101];//ans[i][j]�����ʾֱ������������ �����㷨���ʾ��������i��j����̾���

int main()
{
    int n,m;//n���� m����
    while(scanf("%d%d",&n,&m)!= EOF)
    {
        if(n == 0 && m == 0) break;
        int i,j,k;
        for(i = 0; i < n;i++)
        {
            for(j = 0;j < n; j++)
            {
                ans[i][j] = -1;//��ֵ ��ʾ��i��j����ͨ
            }
            ans[i][i] = 0;//�Լ����Լ��ľ���Ϊ0
        }

        int a,b,c;
        for(i = 0; i < m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);//a b�ǵ������
            ans[a][b] = ans[b][a] = c;//����ͼ �ڽӾ����ǶԳƾ��� ����ͼ�������
        }

        for(k = 0; k < n; k++)//�м��k
        {
            for(i = 0;i < n; i++)
            {
                for(j = 0; j < n; j++)
                {
                    if(ans[i][k] == -1 || ans[k][j] == -1) continue;//k��i j�κ�һ����ͨ �������м��
                    if(ans[i][j] == -1 || ans[i][j] > ans[i][k] + ans[k][j])//i��j����k������� ��i��j��ֱͨ ��Ҫ����
                        ans[i][j] = ans[i][k] + ans[k][j];//����
                }
            }
        }
        printf("%d\n",ans[1][n]);//��1����n����̾���
    }
    return 0;
}
