#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n;
bool flag, visit[31];//flag����Ƿ�������� 
int nextPosition[8][2] = {2,1,2,-1,-2,1,-2,-1,1,2,1,-2,-1,2,-1,-2}; //���8���߷� 
int answer[31];
vector<int> dot[31];//�洢��������ڽӵ�

inline void output()//����߷� 
{
    int be, i;
    for (be = 0; be < 30; be ++)
        if (answer[be] == n)
            break;
    printf( "%d", answer[be] );
    i = be + 1;
    do {
        if (i == 30)
            i = 0;
        printf( " %d", answer[i ++] ); 
    } while (i != be);
    printf( "\n" );
} 

inline bool init(vector<int> &a, int point)//�жϵ�point�Ƿ���ĳ����ڽӵ��� 
{
	vector<int>::iterator it = a.begin();
	for (; it != a.end(); it ++)
		if ((*it) == point)
			break;
	if (it == a.end())
		return false;
	return true;
}

void dfs(int point, int number)//����·�� 
{
	int ne;
	visit[point] = true;
	answer[number] = point;

    if (flag)
		return ;
	if (number == 29 && init(dot[point], 2))
	{
		flag = true;
		return ;
	}
	
	for (int i = 0; i < dot[point].size(); i ++)
	{
		if (flag)
			return ;
		int ne = dot[point][i]; 
		if (!visit[ne])
			dfs(ne, number+1);
	}
	visit[point] = false;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
	for (int i = 1; i <= 30; i ++)//��ʼ��������ڽӵ� 
	{
		int x = (i-1) / 6;
		int y = (i-1) % 6;
		for (int j = 0; j < 8; j ++)
		{
			int xTemp = x + nextPosition[j][0], 
				yTemp = y + nextPosition[j][1];
			if (xTemp < 0 || xTemp > 4 || yTemp < 0 || yTemp > 5)
				continue;
			dot[i].push_back(xTemp*6 + yTemp + 1);
		}
	}

    for (scanf("%d",&n); n != -1; scanf("%d",&n))
    {
        flag = false;
        memset(visit, false, sizeof(visit));
        
		dfs(2, 0);//����һ�����Իص�ԭ���·��

        output();
    }
    
    return 0;
}
