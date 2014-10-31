#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//题目没有给出m进制的m的范围。。。WA N次。。。 
class bigNum {
public :
	bigNum(string , int);
	int getDigit(char );
	char getChar(int );
	string operator / (bigNum &);
	string operator % (bigNum &); 
	string num;
	int n;
	int len;
	int m;
} ;

bigNum::bigNum(string str, int tm)
{
	num = str;
	len = str.length();
	m = tm;
	n = 0;
	int ba = 1;
	for (int i = len-1; i >= 0; i --)
	{
		n += getDigit(num[i]) * ba;
		ba *= m;
	}
}

int bigNum::getDigit(char c)
{
	switch(c) {
	case('A') :		return 10;		case('B') :		return 11;		case('C') :		return 12;
	case('D') :		return 13;		case('E') :		return 14;		case('F') :		return 15;
	case('G') :		return 16;		case('H') :		return 17;		case('I') :		return 18;
	case('J') :		return 19;		case('K') :		return 20;		case('L') :		return 21;
	case('M') :		return 22;		case('N') :		return 23;		case('O') :		return 24;
	case('P') :		return 25;		case('Q') :		return 26;		case('R') :		return 27;
	case('S') :		return 28;		case('T') :		return 29;		case('U') :		return 30;
	case('V') :		return 31;		case('W') :		return 32;		case('X') :		return 33;
	case('Y') :		return 34;		case('Z') :		return 35;
	default :		return c - '0';
	}
}

char bigNum::getChar(int digit)
{
	switch(digit) {
	case(10) :		return 'A';		case(11) :		return 'B';		case(12) :		return 'C';
	case(13) :		return 'D';		case(14) :		return 'E';		case(15) :		return 'F';
	case(16) :		return 'G';		case(17) :		return 'H';		case(18) :		return 'I';
	case(19) :		return 'J';		case(20) :		return 'K';		case(21) :		return 'L';
	case(22) :		return 'M';		case(23) :		return 'N';		case(24) :		return 'O';
	case(25) :		return 'P';		case(26) :		return 'Q';		case(27) :		return 'R';
	case(28) :		return 'S';		case(29) :		return 'T';		case(30) :		return 'U';
	case(31) :		return 'V';		case(32) :		return 'W';		case(33) :		return 'X';
	case(34) :		return 'Y';		case(35) :		return 'Z';
	default :		return digit + '0';
	}
}

string bigNum::operator / (bigNum &rhs)
{
	string ans;
	int temp = n / rhs.n;
	if (temp == 0)
		ans += '0';
	while (temp > 0)
	{
		ans += getChar(temp%m);
		temp /= m;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

string bigNum::operator % (bigNum &rhs)
{
	string ans;
	int temp = n % rhs.n;
	if (temp == 0)
		ans += '0';
	while (temp > 0)
	{
		ans += getChar(temp%m);
		temp /= m;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}


int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	int cases, m;
	string number;
	cin >> cases;
	while (cases --)
	{
		cin >> m >> number;
		bigNum A(number, m);

		cin >> number;
		bigNum B(number, m);

		cout << A/B << endl;
		cout << A%B << endl;
	}

    return 0;
}
