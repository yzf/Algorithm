#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int countA, countB, maxA, maxB;
int maxMergeA, maxMergeB, minMergeA, minMergeB;
int ans;

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d%d%d%d", &countA, &countB, &maxA, &maxB ) != EOF) {

		if (maxA == 0) {
			printf( "%d\n", min(countB, maxB) );
			continue;
		}
		if (maxB == 0) {
			printf( "%d\n", min(countA, maxA) );
			continue; 
		}
		maxMergeA = countA;
		minMergeA = ceil((double)countA/(double)maxA);
		maxMergeB = countB;
		minMergeB = ceil((double)countB/(double)maxB);

		if (minMergeA > minMergeB) {
			int temp = minMergeA;
			while (temp > maxMergeB) {
				temp --;
			}
			if (temp + 1 == minMergeA || temp == minMergeA) {
				ans = countA + countB;
			}
			else {
				ans = (temp + 1) * maxA + countB; 
			}
		}
		else {
			int temp = minMergeB;
			while (temp > maxMergeA) {
				temp --;
			}
			if (temp + 1 == minMergeB || temp == minMergeB) {
				ans = countB + countA;
			}
			else {
				ans = (temp + 1) * maxB + countA; 
			}
		}
		printf( "%d\n", ans );
	}
	
	return 0;
}
