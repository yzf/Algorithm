#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 60;
int n, ans;
bool flag[MAX][MAX];
string key, hotel;

bool isMatch()
{
	memset(flag, false, sizeof(flag));
	int len1 = key.length(), len2 = hotel.length();
	flag[0][0] = true;
	for (int i = 0; i < len1; i ++) {
		for (int j = 0; j < len2; j ++) {
			if (flag[i][j] && (key[i] == hotel[j] || key[i] == '?')) {
				flag[i + 1][j + 1] = true;
			}
			else if (flag[i][j] && key[i] == '*') {
				for (int k = j; k <= len2; k ++) {
					flag[i + 1][k] = true;
				}
			}
		}
	}
	return flag[len1][len2];
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	while (cin >> key) {
		cin >> n;
		ans = 0;
		while (n --) {
			cin >> hotel;
			if (isMatch()) {
				ans ++;
			}
		}
		cout << ans << endl;
	}

    return 0;
}
/*
��̬�滮��
ʵ��ģ�����ҵĹ��ܣ���΢�޸�����������е�״̬ת�Ʒ��̼���ʵ�ִ˹��ܡ�
�� f [ i ][ j ] ��ʾ��һ���ַ����ĵ� i ���ַ�ǰ�Լ��ڶ����ַ����ĵ� j ���ַ�ǰ������Ԫ���Ƿ�ƥ��
״̬ת�Ʒ��̣�
1) ��(key[i - 1] == word[j - 1] || key[i - 1] == '?') && f[i - 1][j - 1]
      f [ i ][ j ] = true
2) ��key[i - 1] == '*' && f[i - 1][j - 1]
     f [ i ][ k ] = true  ( j - 1 <= k <= m, m���ַ���word�ĳ��� )
*/

