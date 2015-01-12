#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int n, w;
  char c;
  priority_queue<int> que;
  cin >> n;
  while (n --) {
    cin >> c;
    if (c == 'A') {
      cin >> w;
      que.push(w);
    }
    else {
      cout << que.top() << endl;
      que.pop();
    }
  }
  return 0;
}
