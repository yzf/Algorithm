#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 101;
int n, m;
string picture[MAX];
string character;//记录特征
char flag;//用于标记当前的搜索方向

inline bool isValid(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	return true;
}

void dfs(int x, int y)
{
	picture[x][y] = '0';
	if (isValid(x + 1, y) && picture[x + 1][y] == '1') {
		if (flag != '1') {
			flag = '1';
			character += '1';
		}
		dfs(x + 1, y);
		flag = '0';
	}
	if (isValid(x, y + 1) && picture[x][y + 1] == '1') {
		if (flag != '2') {
			flag = '2';
			character += '2';
		}
		dfs(x, y + 1);
		flag = '0';
	}
	if (isValid(x - 1, y) && picture[x - 1][y] == '1') {
		if (flag != '3') {
			flag = '3';
			character += '3';
		}
		dfs(x - 1, y);
		flag = '0';
	}
	if (isValid(x, y - 1) && picture[x][y - 1] == '1') {
		if (flag != '4') {
			flag = '4';
			character += '4';
		}
		dfs(x, y - 1);
		flag = '0';
	}
}

void print(string &str) //1、2、3、4分别表示下右上左
{
	if (str == "1234") {
		cout << 0 ;
	}
	else if (str == "1"){
		cout << 1 ;
	}
	else if (str == "21412"){
		cout << 2 ;
	}
	else if (str == "2144"){
		cout << 3 ;
	}
	else if (str == "1213"){
		cout << 4 ;
	}
	else if (str == "12142"){
		cout << 5 ;
	}
	else if (str == "12342"){
		cout << 6 ;
	}
	else if (str == "21"){
		cout << 7 ;
	}
	else if (str == "12344"){
		cout << 8 ;
	}
	else {
		cout << 9 ;
	}
}

int main()  
{  
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
    
	while (cin >> n >> m && n) {

		for (int i = 0; i < n; i ++) {
			cin >> picture[i];
		}

		for (int j = 0; j < m; j ++) {
			for (int i = 0; i < n; i ++) {
				if (picture[i][j] == '1') {
					character = "";
					flag = '0';
					dfs(i, j);
					print(character);
				}
			}
		}
		cout << endl;
	}

    return 0;  
} 
