#include <iostream>
#include <iomanip>

using namespace std;

const double p = 3.1415927;

double dia, rev, times;
double dist, mph;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );

	int cases = 1;
	while (true)
	{
		cin >> dia >> rev >> times;
		if (rev == 0)	break;

		dist = p * dia * rev / 63360;
		mph = dist / times * 3600;

		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Trip #" << cases++ << ": " << dist << " " << mph << endl;
	}

	return 0;
}
