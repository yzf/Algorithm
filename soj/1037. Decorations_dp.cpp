#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 610;
int n, l, m, len, ans, dp[MAX][MAX];
bool canLink[MAX][MAX];
string str[MAX];
//�ж�s2�ܷ����s1����
bool check(string s1, string s2)
{
	for (int i = 1; i < len; i ++) {
		if (s1[i] != s2[i-1]) {
			return false;
		}
	}
	return true;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	while (cin >> n >> l >> m && n && l && m) {
		memset(dp, 0, sizeof(dp));
		memset(canLink, false, sizeof(canLink));

		for (int i = 0; i < m; i ++) {
			cin >> str[i];
		}
		//�����ַ�����Ĺ�ϵ
		len = str[0].length();
		for (int i = 0; i < m; i ++) {
			for (int j = 0; j < m; j ++) {
				if (len == 1) {
					canLink[i][j] = true;
				}
				else if (check(str[i], str[j])) {
					canLink[i][j] = true;
				}
			}
		}
		//DP
		int num = l - len + 1;
		for (int k = 1; k <= num; k ++) {
			for (int i = 0; i < m; i ++) {
				if (k == 1) {
					dp[k][i] = 1;
				}
				else {
					for (int j = 0; j < m; j ++) {
						if (canLink[j][i]) {
							dp[k][i] += dp[k - 1][j];
						}
					}
				}
			}
		}

		ans = 0;
		for (int i = 0; i < m; i ++) {
			ans += dp[num][i];
		}
		cout << ans << endl;
	}

    return 0;
}
/*
�ȱ�����������ӵ��ִ���Ȼ����ж�̬�滮��⡣
״̬ת�Ʒ��̣�
�� f [ k ][ i ] ��ʾ���ִ� i Ϊ��β�������� k ���ַ��������������ܷ�����
�������е� canLink[ j ][ i ] ��0 <= j < m������ canLink[ j ][ i ] Ϊ�棬����
f [ k ][ i ] = f [ k ][ i ] + f [ k - 1 ][ j ]
*/
