#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int test, n, num;
int success;//记录当前已经完成的人数

class Deck {
public :
	queue<int> cards;//拥有的牌
	int counter;//报的数
	int last;//完成时的最后一张牌
	void clear();//还原
	void count(int cn, Deck &next);//报数操作
	bool empty();//判断是否有牌
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
		if (counter + 1 == card)//报数与抽取的牌数相同时
		{
			next.cards.push(card);
			if (empty() && success == cn)//判断是否已经完成
			{
				last = card;//记录完成时的最后一张牌
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
		//开始游戏，若5000轮后没有结束，则看作游戏不可赢
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
