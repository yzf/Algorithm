#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

string preProcessing(const string &str)
{
    int len = str.length();
    if (len == 0) {
        return "^$";
    }
    string ret = "^";
    for (int i = 0; i < len; ++ i) {
        ret.append(1, '#');
        ret.append(1, str[i]);
    }
    return ret + "#$";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string str;
    cin >> n;
    while (n --) {
        cin >> str;
        string curStr = preProcessing(str);
        vector<int> p(curStr.length(), 0);
        int right = 0;
        int center = 0;
        int ans = 0;
        for (int i = 1; i < curStr.length() - 1; ++ i) {
            if (right > i)
                p[i] = min(p[2 * center - i], right - i);
            else
                p[i] = 1;
            while (curStr[i + p[i]] == curStr[i - p[i]])
                ++ p[i];
            if (i + p[i] > right) {
                right = i + p[i];
                center = i;
            }
            ans = max(ans, p[i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
