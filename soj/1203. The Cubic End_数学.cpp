#include <iostream>
#include <string>

using namespace std;

const long long NINE = 1000000000;
string str;
int cases;
long long num, result, mod, len, add, tempMod, numMod;

long long cube(long long number)
{
	long long cubeNum = 0;
	if (number > 999999999) {
		long long low = number % NINE, up = number / NINE * NINE;
		cubeNum = (low * low % mod) * low % mod;
		cubeNum += 3 * (up * (low * low % NINE) % mod) % mod; 
	}
	else {
		cubeNum = (number * number % mod) * number % mod;
	}
	return cubeNum;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	cin >> cases;
	while (cases --) {
		cin >> str;
		num = 0;	mod = 1;	len = str.length();
		for (int i = 0; i < len; i ++) {
			num = num * 10 + (str[i] - '0');
			mod *= 10;
		}

		tempMod = 10;
		add = 1;
		result = 0;
		for (int i = 0; i < len; i ++) {
			numMod = num % tempMod;
			while (cube(result) % tempMod != numMod) {
				result += add;
			}
			tempMod *= 10;
			add *= 10;
		}

		cout << result << endl;
	}

    return 0;
}
//��ѧ�⡣�����һλ��ʼ����λ�ļ���ÿһ�����֡�����ķ����Ǵ�1��9��֤����
//����ǰ����������%(10^n)���ǲ��ǵ��������ĺ�n������Ҫע��Ҫ�������10λ����ʱ��
//������ܳ���long long���ܱ�ʾ�ķ�Χ������Ҫ�����ر�������ֻ��Ҫ���10λ��ͬ�Ϳ��ԣ�
//��������10λ����������ʱ��ֻ��Ҫ����ÿ�μ�������10λ�Ĺ��׾Ϳ��ԣ�������������Ľ����
//����Ĳ��������ǣ�����Ҫ��ʮλ��ABCDEFGHIJ^3�ĺ�10λ��
//ֻ��Ҫ��BCDEFGHIJ^3�ĺ�10λ + 3*A000000000*��BCDEFGHIJ^2������Ȼ�м�Ҫ��ͣ�Ľ���ȡģ����
