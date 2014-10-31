#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int n, m, biggest;
string str, ans;
struct pp {
	int times;////出现的次数
	int num;//第一次出现是第几个
} ;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	while (scanf( "%d", &n ) && n != 0)
	{
		int k = 0; 
		biggest = 0;//最大的次数 
		map<string, pp> nameMap;
		map<string, bool> flag;//标记该名字是否已出现 

		while (n --)
		{
			cin >> str;
			scanf( "%d", &m );
			while (m --)
			{
				cin >> str;
				if (!flag[str])
				{
					nameMap[str].num = k ++;
					flag[str] = true;
				}
				nameMap[str].times ++;	
				if (nameMap[str].times > biggest)
					biggest = nameMap[str].times;
			}
		}

		int ii = 1000000;//开一个较大的数 
		for (map<string, pp>::iterator it = nameMap.begin(); 
			it != nameMap.end(); it ++)
		{
			if (it->second.times == biggest && it->second.num < ii)
			{
				ans = it->first;
				ii = it->second.num;
			}
		}
		cout << ans << endl;
	}

    return 0;
}
