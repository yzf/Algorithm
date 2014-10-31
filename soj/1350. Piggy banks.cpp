#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 1000001;
int n, ans, color;//��ͬһ����Ⱦ����ͬ��ɫ 
int flag[MAX], ne[MAX];//ne[i]��ʾԿ�� i �� ne[i]�� 
//����ת��Ϊ��������ͼ�Ļ��ĸ���
int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) != EOF)
	{
		for (int i = 1; i <= n; i ++)//����n����ԶС��MAX������ֱ����ѭ����ʼ�������
			flag[i] = -1;
		ans = 0;
		color = 1;

		for (int i = 1; i <= n; i ++)
		{
			scanf( "%d", &ne[i] );
			if (ne[i] == i)
			{
				flag[i] = color ++;
				ans ++;
			}
		}

		for (int i = 1; i <= n; i ++)
		{
			if (flag[i] > 0)
				continue;
				
			color ++;
			int index = i;
			while (flag[index] == -1)
			{
				flag[index] = color;
				index = ne[index];
				if (flag[index] == color)
					ans ++;
			}
		}
		
		printf( "%d\n", ans );
	}

    return 0;
}
