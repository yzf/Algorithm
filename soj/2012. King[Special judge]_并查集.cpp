#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int n, father[1010];
char str[1010];
//²¢²é¼¯ 
void make_set(int &n)
{
	for (int i = 1; i <= n; i ++)
		father[i] = i;
}
int find_set(int &x)
{
	if (x != father[x])
		father[x] = find_set(father[x]);
	return father[x];
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
	while (scanf( "%d", &n ) != EOF)
	{
		set<int> ans;
		make_set(n);
		for (int i = 1; i <= n; i ++)
		{
			scanf( "%s", str );
			int len = strlen(str);
			for (int j = 0; j < len; j ++)
			{
				if (str[j] == '1')
				{
					int temp = find_set(i);
					father[j+1] = temp;
				}
			}
		}
		for (int i = 1; i <= n; i ++)
			ans.insert(find_set(i));

		if (ans.size() > 1)
			printf( "-1\n" );
		else
			printf( "%d\n", *ans.begin() );
	}
    
    return 0;
}
