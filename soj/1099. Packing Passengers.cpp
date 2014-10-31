#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

long long n, costA, passengersA, costB, passengersB, aAmount, bAmount, gcd;

long long Gcd(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long r = Gcd(b, a%b, x, y);
	long long temp = x;
	x = y;
	y = temp - a/b*y;
	return r;
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	int cases = 1;
	while (scanf( "%lld", &n ) && n != 0)
	{
		scanf( "%lld%lld%lld%lld", &costA, &passengersA, &costB, &passengersB );

		gcd = Gcd(passengersA, passengersB, aAmount, bAmount);
		if (n%gcd != 0)
			printf( "Data set %d: cannot be flown\n", cases ++);
		else
		{
			aAmount = aAmount * n / gcd;
			bAmount = bAmount * n / gcd;

			long long tmin = (int)ceil((double)(-aAmount)*gcd/passengersB);
			long long tmax = (int)floor((double)(bAmount)*gcd/passengersA);

			long long delta = costA * passengersB - costB * passengersA;

			long long t;
			if (delta <= 0)
				t = tmax;
			else
				t = tmin;

			aAmount = aAmount + passengersB / gcd * t;
			bAmount = bAmount - passengersA / gcd * t;

			printf( "Data set %d: %lld aircraft A, %lld aircraft B\n", cases ++, aAmount, bAmount );
		}
	}

    return 0 ;
}
