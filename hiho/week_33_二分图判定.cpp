#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool check(const int& first_people, const vector< vector<int> >& adjacency,
        map<int, bool>* color) {
    queue<int> que;
    que.push(first_people);
    color->insert(make_pair(first_people, false));
    while (! que.empty()) {
        const int cur_people = que.front();
        que.pop();
        for (size_t i = 0; i < adjacency[cur_people].size(); ++ i) {
            const bool& cur_color = color->find(cur_people)->second;
            const int& next_people = adjacency[cur_people][i];
            map<int, bool>::const_iterator it = color->find(next_people);
            if (it != color->end()) {
                if (it->second == cur_color) {
                    return false;
                }
            }
            else {
                que.push(next_people);
                color->insert(make_pair(next_people, ! cur_color));
            }
        }
    }
    return true;
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case --) {
        int number_people;
        int number_pair;
        cin >> number_people >> number_pair;
        vector< vector<int> > adjacency(number_people);
        int first_people, second_people;
        while (number_pair --) {
            cin >> first_people >> second_people;
            -- first_people;
            -- second_people;
            adjacency[first_people].push_back(second_people);
            adjacency[second_people].push_back(first_people);
        }
        int flag = true;
        map<int, bool> color;
        for (int i = 0; i < number_people; ++ i) {
            if (! check(i, adjacency, &color)) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Correct" << endl;
        else
            cout << "Wrong" << endl;
    }
    return 0;
}
