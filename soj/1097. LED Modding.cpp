#include <iostream>  
#include <algorithm>  
#include <map>  
#include <vector>  
#include <string>  

using namespace std;  

int v, led_v, led_i, n, res;
string rname;

int main()  
{  
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
      
    while(cin >> v >> led_v >> led_i >> n)  
    {  
		int i;
		vector<int> r;
		map<int, string> m;
		for (i = 0; i < n; i ++)
		{
			cin >> rname >> res;
			r.push_back(res);
			m[res] = rname;
		}

		sort(r.begin(), r.end());

		if (v <= led_v)
		{
			cout << "---\n" ;
			continue;
		}
		double led_r = (double)led_v / (double)led_i * 1000;
		double optimum = v*led_r/(double)led_v - led_r;
		for (i = 0; i < n; i ++)
			if (r[i] >= optimum)
				break;
		
		if (i == n || v <= 0)
			cout << "IMPOSSIBLE\n" ;
		else
		{
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << optimum << " " << m[r[i]] << endl;
		}

    }  
    return 0;  
} 
