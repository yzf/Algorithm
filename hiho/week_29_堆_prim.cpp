#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Road {
    int to;
    int distance;
    Road(int t, int d) : to(t), distance(d) {}
};

bool operator < (const Road &lhs, const Road &rhs)
{
    return lhs.distance > rhs.distance;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector< vector<Road> > roads(n + 1);
    while (m --) {
        int city_a, city_b, distance;
        cin >> city_a >> city_b >> distance;
        roads[city_a].push_back(Road(city_b, distance));
        roads[city_b].push_back(Road(city_a, distance));
    }
    int city_new = 1;
    int city_count = 1;
    int answer = 0;
    vector<Road> heap;
    map<int, bool> flag;    
    flag[city_new] = true;
    while (city_count < n) {
        for (size_t i = 0; i < roads[city_new].size(); ++ i) {
            heap.push_back(roads[city_new][i]); 
            push_heap(heap.begin(), heap.end());
        }
        while (true) {
            city_new = heap.front().to; 
            if (! flag[city_new]) {
                flag[city_new] = true;
                ++ city_count;
                answer += heap.front().distance;
                pop_heap(heap.begin(), heap.end());
                heap.pop_back();
                break;
            }
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
    }
    cout << answer << endl;
    return 0;
}
