#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1010;
int n, data[MAX];
int a[MAX], b[MAX];//a[i]��ʾ�Ե�i������β��������г��ȣ�b[i]���ʾ�Ե�i������ʼ��������еĳ���
int ans;

int main() 
{
	//freopen( "input.txt", "r", stdin );  
	//freopen( "output.txt", "w", stdout );
	
	while (scanf( "%d", &n ) != EOF) {
		
		int i, j;
		for (i = 1; i <= n; i ++) {
			scanf( "%d", &data[i] );
		}

		for (i = 1; i <= n; i ++) {
			a[i] = b[i] = 1;
		}
		//����a[]
		for (i = 1; i <= n; i ++) {
			for (j = 1; j < i; j ++) {
				if (data[i] > data[j]) {
					a[i] = max(a[i], a[j] + 1);
				}
			}
		}
		//����b[]
		for (i = n; i > 0; i --) {
			for (j = n; j > i; j --) {
				if (data[i] > data[j]) {
					b[i] = max(b[i], b[j] + 1);
				}
			}
		}

		ans = 0;
		for (i = 1; i <= n; i ++) {
			for (j = i; j <= n; j ++) {
				int temp;
				if (i == j) {//�ظ�����ͬһ��λ���ϵ���
					temp = a[i] + b[j] - 1;
				}
				else {
					temp = a[i] + b[j];
				}
				if (temp > ans) {
					ans = temp;
				}
			}
		}
		ans = n - ans;
		printf( "%d\n", ans );
	}
	
	return 0;
}
