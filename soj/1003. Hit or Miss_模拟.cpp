#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int test, n, num;
int success;//��¼��ǰ�Ѿ���ɵ�����

class Deck {
public :
	queue<int> cards;//ӵ�е���
	int counter;//������
	int last;//���ʱ�����һ����
	void clear();//��ԭ
	void count(int cn, Deck &next);//��������
	bool empty();//�ж��Ƿ�����
} deck[12];

void Deck::clear()
{
	counter = -1;
	last = -1;
	while (!cards.empty())
		cards.pop();
}

void Deck::count(int cn, Deck &next)
{
	if (!empty())
	{
		counter = (counter + 1) % 13;
		int card = cards.front();
		cards.pop();
		if (counter + 1 == card)//�������ȡ��������ͬʱ
		{
			next.cards.push(card);
			if (empty() && success == cn)//�ж��Ƿ��Ѿ����
			{
				last = card;//��¼���ʱ�����һ����
				success ++;
			}
		}
		else 
			cards.push(card);
	}
}

bool Deck::empty()
{
	return cards.empty();
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	cin >> test;
	for (int i = 1; i <= test; i ++)
	{
		cin >> n;
		success = 0;
		for (int j = 0; j <= n; j ++)
			deck[j].clear();
		for (int j = 0; j < 52; j ++)
		{
			cin >> num;
			deck[1].cards.push(num);
		}
		//��ʼ��Ϸ����5000�ֺ�û�н�����������Ϸ����Ӯ
		for (int j = 0; j < 5000; j ++)
		{
			if (success == n)
				break;
			for (int k = 1; k <= n; k ++)
				deck[k].count(k - 1, deck[k + 1]);
		}
		cout << "Case " << i << ":";
		if (success == n)
		{
			for (int j = 1; j <= n; j ++)
				cout << " " << deck[j].last;
			cout << endl;
		}
		else 
			cout << " unwinnable\n";
	}

    return 0;
}
