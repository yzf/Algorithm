#include <iostream>
#include <queue>

using namespace std;

char cmd;
int num;
queue<int> que;

int main()
{
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
	
	while (cin >> cmd)
	{
        switch (cmd) {
        case 'O' :
             if (que.empty())   cout << "None\n" ;
             else
             {
                 cout << que.front() << endl;
                 que.pop();
             }
             break;
        case 'I' :
             cin >> num;
             que.push(num);
        }
    }
    
	return 0;
}
