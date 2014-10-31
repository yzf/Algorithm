#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int n, num, a[8];
map<int, bool> visited;
map<int, char> mark;
map<int, int> cn;
queue<int> que;
stack<char> ans;

void getStr(int num, int arr[])
{
	for (int i = 7; i >= 0; i --)
	{
		arr[i] = num % 10;
		num /= 10;
	}
}

int getNum(int arr[])
{
	int num = 0;
	for (int i = 0; i < 8; i ++)
		num = num * 10 + arr[i];
	return num;
}

void A(int arr[])
{
	swap(arr[0], arr[4]);	swap(arr[1], arr[5]);
	swap(arr[2], arr[6]);	swap(arr[3], arr[7]);
}

void B(int arr[])
{
	int temp = arr[3];	arr[3] = arr[2];	arr[2] = arr[1];	arr[1] = arr[0];	arr[0] = temp;
	temp = arr[7];	arr[7] = arr[6];	arr[6] = arr[5];	arr[5] = arr[4];	arr[4] = temp;
}

void C(int arr[])
{
	int temp = arr[1];	arr[1] = arr[5];	arr[5] = arr[6];	arr[6] = arr[2];	arr[2] = temp;
}

void bfs()
{
	int no, ne;
	que.push(12348765);
	visited[12348765] = true;
	cn[12348765] = 0;
	while (!que.empty())
	{
		no = que.front();
		que.pop();

		getStr(no, a);
		A(a);
		ne = getNum(a);
		if (!visited[ne])
		{
			que.push(ne);
			visited[ne] = true;
			mark[ne] = 'A';
			cn[ne] = cn[no] + 1;
		}
		A(a);

		B(a);
		ne = getNum(a);
		if (!visited[ne])
		{
			que.push(ne);
			visited[ne] = true;
			mark[ne] = 'B';
			cn[ne] = cn[no] + 1;
		}
		B(a);	B(a);	B(a);

		C(a);
		ne = getNum(a);
		if (!visited[ne])
		{
			que.push(ne);
			visited[ne] = true;
			mark[ne] = 'C';
			cn[ne] = cn[no] + 1;
		}
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	bfs();
	while (cin >> n && n != -1)
	{
		for (int i = 0; i < 8; i ++)
			cin >> a[i];
		num = getNum(a);
		if (cn[num] > n)
		{
			cout << -1 << endl;
			continue;
		}
		cout << cn[num] << " ";
		while (num != 12348765)
		{
			ans.push(mark[num]);
			switch(mark[num]) {
			case 'A':
				A(a);	num = getNum(a);	break;
			case 'B':
				B(a);	B(a);	B(a);	num = getNum(a);	break;
			case 'C':
				C(a);	C(a);	C(a);	num = getNum(a);	break;
			}
		}
		while (!ans.empty())
		{
			cout << ans.top();
			ans.pop();
		}
		cout << endl;
	}

	return 0;
}
