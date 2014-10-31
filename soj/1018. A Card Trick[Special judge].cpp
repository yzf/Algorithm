#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int n;
string card[5];
//获取牌的数字
int getInt(string str)
{
	int result = 0;
	if (str[0] == 'A')
		result = 1;
	else if (str[0] == '1')
		result = 10;
	else if (str[0] == 'J')
		result = 11;
	else if (str[0] == 'Q')
		result = 12;
	else if (str[0] == 'K')
		result = 13;
	else 
		result = str[0] - '0';
	return result;
}
//获取牌的花
char getSuit(string str)
{
	return str[str.length() - 1];
}
//数字转成字符串
string IntToString(int num)
{
	string result;
	if (num == 1)
		result = "A";
	else if (num == 10)
		result = "10";
	else if (num == 11)
		result = "J";
	else if (num == 12)
		result = "Q";
	else if (num == 13)
		result = "K";
	else 
		result += (num + '0');
	return result;
}
//比较牌的大小
bool cmp(string a, string b)
{
	if (getInt (a) < getInt(b))
		return true;
	else if (getInt (a) == getInt (b))
		return getSuit (a) < getSuit (b);
	else 
		return false;
}
//模拟过程，检测当前序列是否可行
bool check ()
{
	int minID = 2;
	for (int i = 3; i < 5; i ++)
	{
		int a = getInt (card[minID]);
		int b = getInt (card[i]);
		if (cmp (card[i], card[minID]))
			minID = i;
	}
	int num = getInt (card[1]) + minID - 1;
	num --;
	if (minID == 2)
	{
		if (!cmp (card[3], card[4]))
			num = (num + 3) % 13;
	}
	else if (minID == 3)
	{
		if (!cmp (card[2], card[4]))
			num = (num + 3) % 13;
	}
	else 
	{
		if (!cmp (card[2], card[3]))
			num = (num + 3) % 13;
	}
	num ++;
	string result = IntToString (num) + getSuit (card[1]);
	if (result == card[0])
		return true;
	return false;
}

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	cin >> n;
	for (int test = 1; test <= n; test ++)
	{
		for (int i = 0; i < 5; i ++)
			cin >> card[i];
		sort (card, card + 5);
		do {//直接爆力所有组合
			if (check ())
			{
				cout << "Problem " << test << ": " << card[0] << " " << card[1] << " " << card[2] << " " << card[3] << " " << card[4] << endl;
				break;
			}
		} while (next_permutation(card, card + 5));
	}
	
	return 0;
}
