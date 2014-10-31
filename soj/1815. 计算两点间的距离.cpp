#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a1, b1, a2, b2, n, l;
	cin >> n;
	while (n --)
	{
		cin >> a1 >> b1;
		cin >> a2 >> b2;
		l = sqrt((a2-a1)*(a2-a1)+(b2-b1)*(b2-b1));
		cout.setf(ios::fixed); 
		cout.precision(2); 
		cout<<l<<endl;
	}

	return 0;
} 
