#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 1500;
string str, temp;
int en, cn, a[MAX+1];
int sum[MAX+1], add[MAX+1];

void print()
{
	for (int i = 0; i < MAX; i ++)
	{
		sum[i+1] += sum[i] / 10;
		sum[i] = sum[i] % 10;
	}
    bool flag = false;
    for (int i = MAX; i >= 0; i --)
    {
        if (sum[i] > 0)
            flag = true;
        if (!flag)
            continue;
        cout << sum[i] ;
    }
    cout << endl;
}

int main()
{
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    
    memset(sum, 0, sizeof(sum));
    
    cin >> str;
    cn = 0;
    for (int i = 0; i < str.length(); i ++)
        if (str[i] == '+')
            a[cn ++] = i;

    int index = 0;
    for (int i = 0; i < cn; i ++)
    {
        memset(add, 0, sizeof(add));
        temp = str.substr(index, a[i]-index);
        for (int j = temp.length()-1, k = 0; j >= 0; j --, k ++)
            add[k] = temp[j] - '0';
        for (int j = 0; j <= MAX; j ++)
            sum[j] += add[j];
        index = a[i]+1;
    }
    memset(add, 0, sizeof(add));
    temp = str.substr(index, str.length()-index);
    for (int j = temp.length()-1, k = 0; j >= 0; j --, k ++)
        add[k] = temp[j] - '0';
    for (int j = 0; j <= MAX; j ++)
        sum[j] += add[j];
            
    print();
   
    return 0;
}
