#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int str4ToNum(string str) {
    int num = 0;
    int base = 1000;
    for (int i = 0; i < 4; ++ i) {
        num += (str[i] - '0') * base;
        base /= 10;
    }
    return num;
}

string numToStr8(int num) {
    string str = "00000000";
    int i = 7;
    while (num > 0) {
        str[i] = (num % 10) + '0';
        num /= 10;
        -- i;
    }
    return str;
}

string getNextNum(string str) {
    int num = str4ToNum(str);
    string ne = numToStr8(num * num);
    return ne.substr(2, 4);
}



int main() {
    //freopen("input", "r", stdin);

    string str;
    while (cin >> str) {
        if (str == "0") {
            break;
        }
        map<string, bool> flag;
        while (! flag[str]) {
            flag[str] = true;
            str = getNextNum(str);
        }
        cout << flag.size() << endl;
    }
    

    return 0;
}
