//������ ͼ�� ��5.8 ��������
//�ڽ�����
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

//���100���� 100���ߣ�
queue <int> Q;//������Ϊ0�ĵ�
vector<int> edge[101];//���������ʾ�� edge[a]������aΪ���ıߵ��ص�b c d...����ʾ�����
int rudu[101] = {0};//ͳ��ͼ��ÿ�������� ��ֵΪ0
int main()
{
    int n,m;//n�Ǳ�ͼ���� m�Ǳ���
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n == 0 && m == 0) break;
        //�����
        //������
        int i,j;
        while(Q.empty() == false) Q.pop();//��ն���
        for(i = 0; i < n; i++)
        {
            rudu[i] = 0;//ÿ�ζ�Ҫ��ȳ�ֵ��Ϊ0 �����ϴεĻ���������
            edge[i].clear();//�������
        }


        //��ʼ��ͼ����Ϣ
        int a,b;//��ʾһ����a���b�յ�
        for(i = 0; i < m; i++)
        {
            scanf("%d%d",&a,&b);
            printf("һ����%d->%d\n",a,b);
            edge[a].push_back(b);//��b��������a������
            rudu[b]++;//b�����+1
            printf("%d������Ϊ%d\n",b,rudu[b]);
        }

        for( i = 0; i < n; i++)
        {
            if(rudu[i] == 0)
                {
                    Q.push(i);
                    printf("��%d���Ϊ0�������\n",i);
                }
        }

        int cnt = 0;//ͳ���Ѿ���������ĵ��� ÿ�γ���һ�����Ϊ1�ĵ������ɹ�һ��
        while(Q.empty() == false)
        {
            //ȡ����ͷ��һ�����Ϊ0�ĵ�
            int now = Q.front();
            printf("��%d������\n",now);
            Q.pop();//����
            cnt ++;
            //ɾ���������Ϊ�������б� �Ѷ�Ӧ���յ����-1
            for(j = 0; j < edge[now].size(); j++)//ע����к�����ͬ��ѭ����ʽ
            {
                //ɾ�������� û�в���
                rudu[edge[now][j]] --;//a->b��now->j
                if(rudu[edge[now][j]] == 0)
                    Q.push(edge[now][j]);
            }

        }
        printf("cnt = %d\n",cnt);
        if(cnt == n) printf("��������ɹ� �޻�\n");
        else printf("�л�\n");

    }
    return 0;
}
