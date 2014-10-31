#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 30;
int n, data[MAX], position[MAX];//position[i]��ʾ��i������ԭ�����еĵڼ�������

bool cmp(const int a, const int b)
{
	return data[a] < data[b];
}

int cal()//���ƺ��������������ö��ٲ�,���ڼ�֦ 
{
	int result = 0;
	for (int i = 0; i < n - 1; i ++)
		if (position[i] > position[i+1]+1 || position[i+1] > position[i]+1)
			result ++;
	return result;
}

bool isSorted()//�ж��Ƿ����ҵ���
{
	for (int i = 0; i < n - 1; i ++)
		if (position[i] > position[i+1])
			return false;
	return true;
}

bool ids(int bound)//boundΪʣ�ಽ��
{
	if (bound == 0) {
		if (isSorted())
			return true;
		else
			return false;
	}
	else if (cal() > bound)//��֦
		return false;
	else {
		for (int i = 2; i <= n; i ++) {
			reverse(position, position+i);
			if (ids(bound - 1))
				return true;
			reverse(position, position+i);//��ԭ
		}
		return false;
	}
}

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );

	scanf( "%d", &n );
	for (int i = 0; i < n; i ++) {
		position[i] = i;
		scanf( "%d", &data[i] );
	}
	sort(position, position+n, cmp);
	for (int i = 0; ; i ++) {
		if (ids(i)) {
			printf( "%d\n", i );
			break;
		}
	}

    return 0;
}
