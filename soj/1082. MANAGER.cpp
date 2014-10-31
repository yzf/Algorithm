#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int MAX = 10002;
int maxCost;
int len;
int num;
int arr[MAX];
int curMin, curMax;
int cn;
bool flag;
string cmd;

int remove()
{
	if (cn == 0)
		return -1;
	int rm = -1;
	cn --;
	if (flag)
	{
		rm = curMin;
		if (-- arr[curMin] == 0)
			for (int i = curMin + 1; i < MAX; i ++)
				if (arr[i] > 0)
				{
					curMin = i;
					break;
				}
	}
	else 
	{
		rm = curMax;
		if (-- arr[curMax] == 0)
			for (int i = curMax - 1; i > 0; i --)
				if (arr[i] > 0)
				{
					curMax = i;
					break;
				}
	}
	return rm;
}

int main()
{
	//freopen ( "input.txt", "r", stdin );
	//freopen ( "output.txt", "w", stdout );

	int test = 0;
	while (cin >> maxCost)
	{
		memset (arr, 0, (maxCost + 1) * sizeof(int));
		arr[maxCost + 1] = arr[0] = 1;
		vector<int> rmList;
		vector<int> output;
		output.push_back(-1);
		curMax = 0;
		curMin = MAX;
		cn = 0;
		flag = true;

		if (test ++ > 0)
			cout << endl;
		cin >> len;
		while (len --)
		{
			cin >> num;
			rmList.push_back(num);
		}

		while (true)
		{
			cin >> cmd;
			if (cmd == "a")
			{
				cin >> num;
				arr[num] ++;
				cn ++;
				if (cn == 1)
					curMax = curMin = num;
				if (num > curMax)
					curMax = num;
				else if (num < curMin)
					curMin = num;
			}
			else if (cmd == "r")
				output.push_back(remove());
			else if (cmd == "p")
			{
				cin >> num;
				if (num == 1)
					flag = true;
				else 
					flag = false;
			}
			else 
				break;
		}

		for (int i = 0; i < rmList.size(); i ++)
			cout << output[ rmList[i] ] << endl;
	}

    return 0;
}
