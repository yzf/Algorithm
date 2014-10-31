#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int i, j;
double sum;
string line;

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	while (cin >> line && line[0] != '#') {
		sum = 0.0;

		for (i = 0; i < line.length(); i ++) {
			if (line[i] == '.')	sum += 1.0;

			if (line[i] == '/') {
				for (j = i-1; ; j --) {
					if (j == -1 || line[j] == '.') {
						sum += 1.0;
						break;
					}
					if (line[j] == '|' || line[j] == '\\')	break;
				}
				continue;
			}

			if (line[i] == '\\') {
				for (j = i+1; ; j ++) {
					if (j == line.length() || line[j] == '.') {
						sum += 1.0;
						break;
					}
					if (line[j] == '|' || line[j] == '/')	break;
				}
				continue;
			}

			if (line[i] == '|') {
				for (j = i-1; ; j --) {
					if (j == -1 || line[j] == '.') {
						sum += 0.5;
						break;
					}
					if (line[j] == '|' || line[j] == '\\')	break;
				}

				for (j = i+1; ; j ++) {
					if (j == line.length() || line[j] == '.') {
						sum += 0.5;
						break;
					}
					if (line[j] == '|' || line[j] == '/')	break;
				}
			}
		}

		printf( "%d\n", (int)(sum / line.length() * 100) );
	}

    return 0;
}
