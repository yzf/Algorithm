#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1010;
//�ȶ���������
struct People {
	bool state;
	int opp, tag;
	int priority[MAX];
} man[MAX], woman[MAX];

struct R {
	int opp, own;
} request[MAX];

int n, num;

void stableMatching()
{
	while (true) {
		int i, id = 0;
		for (i = 0; i < n; i ++)
			if (man[i].state == false) {
				request[id].opp = man[i].priority[ man[i].tag ];
				request[id].own = i;
				man[i].tag ++;
				id ++;
			}//��¼����

		if (id == 0)	break;//û���κ�������Ҫ����
		for (i = 0; i < id; i ++) {
			if (woman[ request[i].opp ].state == false) {//���֮ǰ��Ů��û�յ�������
				woman[ request[i].opp ].opp = request[i].own;
				woman[ request[i].opp ].state = true;
				man[ request[i].own ].opp = request[i].opp;
				man[ request[i].own ].state = true;
			} 
			else {
				if (woman[ request[i].opp ].priority[ woman[ request[i].opp ].opp ] > 
					woman[ request[i].opp ].priority[ request[i].own ] ) {//��ǰ��������������ȸ�Ů��֮ǰ��������������ȼ��ߣ�ԽСԽ�ߣ��������
						man[ woman[ request[i].opp ].opp ].state = false;
						woman[ request[i].opp ].opp = request[i].own;
						man[ request[i].own ].opp = request[i].opp;
						man[ request[i].own ].state = true;
				}
			}
		}
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &n );
	for (int i = 0; i < n; i ++) {
		man[i].state = false;
		man[i].tag = 0;
		for (int j = 0; j < n; j ++) {
			scanf( "%d", &num );
			man[i].priority[j] = num - 1;
		}
	}
    //��Ҫע����ǣ�������Ů�����ȼ����д洢��ʽ��ͬ�����������ȼ����У�Ů����á������ŵڼ��� 
	for (int i = 0; i < n; i ++) {
		woman[i].state = false;
		for (int j = 0; j < n; j ++) {
			scanf( "%d", &num );
			woman[i].priority[num - 1] = j;
		}
	}

	stableMatching();

	for (int i = 0; i < n; i ++)
		printf( "%d\n", man[i].opp+1);

	return 0;
}
