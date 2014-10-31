#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 101100
#define oo 1100000000

struct LINE{
       int y, x, c;
} line[2 * MAXN];
struct YS{
       int id, val;
} ys[2 * MAXN];

struct node{
       // 必需参数 
       int val, l, r; 
       // sum是总和,len是总长度(覆盖度)
       int sum, len;
       // maxn和minn是最大最小值
       int maxn, minn;
       // maxs和mins是最大最小位置(线段前端点)
       int maxs, mins;
};
struct segtree{
       node tree[4 * MAXN];
       int ls(int);         // 坐标离散修正 
       void del(node&);
       void init(int, int, int);
       void updata(node&, node&, node&);
       void mydata(int, int);
       void insert(int, int, int, int);
       node search(int, int, int);
};
int segtree :: ls(int id) {return id; /*return id*/}
void segtree :: del(node &tmp)
{
     tmp.val = tmp.sum = tmp.len = tmp.maxn = tmp.minn = 0;
     tmp.maxs = tmp.mins = tmp.l;
}
void segtree :: init(int id, int l, int r)
{
     tree[id].l = l;
     tree[id].r = r;
     del(tree[id]);
     if (r - l > 1)
     {
        int mid = (l + r) >> 1;
        init((id << 1), l, mid);
        init((id << 1) + 1, mid, r); 
     }
}
void segtree :: updata(node &tmp, node &s1, node &s2)
{
     int len = ls(tmp.r) - ls(tmp.l);
     tmp.sum = s1.sum + s2.sum + tmp.val * len;
     if (tmp.val) tmp.len = len;
             else tmp.len = s1.len + s2.len;
     tmp.maxn = max(s1.maxn, s2.maxn) + tmp.val;
     tmp.minn = min(s1.minn, s2.minn) + tmp.val;
     if (s1.maxn >= s2.maxn) tmp.maxs = s1.maxs; else tmp.maxs = s2.maxs;
     if (s1.minn <= s2.minn) tmp.mins = s1.mins; else tmp.mins = s2.mins;
}
void segtree :: mydata(int id, int val)
{
     int len = ls(tree[id].r) - ls(tree[id].l);
     tree[id].val += val;
     tree[id].sum += len * val;
     if (tree[id].val) tree[id].len = len; else 
     if (tree[id].r - tree[id].l > 1) tree[id].len = tree[(id << 1)].len + tree[(id << 1) + 1].len;
                                 else tree[id].len = 0;
     tree[id].maxn += val;
     tree[id].minn += val;
}
void segtree :: insert(int id, int l, int r, int val)
{
     if (tree[id].r <= l || r <= tree[id].l) return;
     if (l <= tree[id].l && tree[id].r <= r)
     {
           mydata(id, val);
           return;
     }
     int nid1 = (id << 1);
     int nid2 = (id << 1) + 1;
     insert(nid1, l, r, val);
     insert(nid2, l, r, val);
     updata(tree[id], tree[nid1], tree[nid2]);
}
node segtree :: search(int id, int l, int r)
{
     node tmp; del(tmp); 
     tmp.minn = oo;                                       //当使用minn时必需 
     if (tree[id].r <= l || r <= tree[id].l) return tmp;
     if (l <= tree[id].l && tree[id].r <= r)
     {
           return tree[id];
     } 
     tmp.val = tree[id].val;
     tmp.l = max(l, tree[id].l);
     tmp.r = min(tree[id].r, r);
     node s1 = search((id << 1), l, r);
     node s2 = search((id << 1) + 1, l, r);
     updata(tmp, s1, s2);
     return tmp;
}

int m, n;
int num, a, b;
segtree t;
node ret;

int main() {
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
	
	scanf( "%d%d", &m, &n );
	t.init(1, 1, m + 1);
	for (int i = 1; i <= m; i ++) {
		scanf( "%d", &num );
		t.insert(1, i, i + 1, num);
	}
	for (int i = 1; i < n; i ++) {
		scanf( "%d%d", &a, &b);
		ret = t.search(1, a, b + 1);
		printf( "%d ", ret.minn );
	}
	scanf( "%d%d", &a, &b);
	ret = t.search(1, a, b + 1);
	printf( "%d ", ret.minn );
	
    return 0;
}                                 