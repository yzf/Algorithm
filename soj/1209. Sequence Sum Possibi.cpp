#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
    /*
	be + (be+1) + ... + (be+i) = number
	(2*be + i)(i+1) = 2*number
	2*be + i = 2*number / (i+1)
	...
	��֤be���ڶ���Ϊ���������� 
	ö��
	*/
	int n, problemNumber, number, answer, limit;
	cin >> n;
	while (n --)
	{
		cin >> problemNumber >> number;

		answer = 0;
		limit = sqrt((2.0*number));
		for (int i = 1; i <= limit; i ++)//i+1 Ϊ�������ָ��� 
		{
			if ((2*number)%(i+1) == 0 && (2*number/(i+1)-i)%2 == 0 && (2*number/(i+1)-i) >= 2) 
				answer ++;
		}
		cout << problemNumber << " " << answer << endl;
	}

    return 0;
}
