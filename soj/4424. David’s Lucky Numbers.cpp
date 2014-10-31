#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct LuckyNumber {
	int num[20];
	int len;
	void init(int n) {/*�������ʼ��Ϊ������ʽ*/
		memset(num, 0, sizeof(num));
		len = 0;
		while (n > 0) {
			num[++ len] = n % 10;
			n /= 10;
		}
		fix();
	}
	bool isSuper() {/*�ж��Ƿ�ΪSuperNumber*/
		int cn4 = 0;
		int cn7 = 0;
		for (int i = 1; i <= len; i ++) {
			if (num[i] == 4)	cn4 ++;
			else if (num[i] == 7)	cn7 ++;
		}
		return cn4 == cn7;
	}
	void increase() {/*��һ��LuckyNumber*/
		num[1] ++;
		fix();
	}
	void fix() {/*��ɲ�С�ڵ�ǰ����LuckyNumber*/
		for (int i = 1; i <= len; i ++) {
			if (num[i] <= 4) {
				if (num[i] < 4)	{
					num[i] = 4;
					for (int j = i - 1; j > 0; j --)
						num[j] = 4;
				}
			}
			else if (num[i] <= 7) {
				if (num[i] < 7)	{
					num[i] = 7;
					for (int j = i - 1; j > 0; j --)
						num[j] = 4;
				}
			}
			else {
				for (int j = i; j > 0; j --)
					num[j] = 4;
				num[i + 1] ++;
				if (i == len)	len ++;
			}
		}
	}
	void print() {
		for (int i = len; i > 0; i --)
			cout << num[i];
		cout << endl;
	}
} ;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	int t, n;
	LuckyNumber ln;
	cin >> t;
	while (t --) {
		cin >> n;
		ln.init(n);
		while (true) {
			if (ln.isSuper()) {
				ln.print();
				break;
			}
			ln.increase();
		}
	}

    return 0;
}
