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
//数学题。从最后一位开始，逐位的计算每一个数字。计算的方法是从1到9验证。。
//看当前的数的立方%(10^n)方是不是等于所给的后n个数。要注意要求的数是10位数的时候，
//结果可能超过long long所能表示的范围，所以要进行特别处理。由于只需要最后10位相同就可以，
//所以在算10位数的立方的时候，只需要考虑每次计算对最后10位的贡献就可以，不用算出完整的结果。
//具体的操作方法是，比如要算十位数ABCDEFGHIJ^3的后10位，
//只需要算BCDEFGHIJ^3的后10位 + 3*A000000000*（BCDEFGHIJ^2）。当然中间要不停的进行取模处理。
