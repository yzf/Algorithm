#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 26;
const int SIZE = 15;

struct Node {
    int cnt;
    Node *son[N];
    Node() : cnt(0) {
        for (int i = 0; i < N; ++ i)
            son[i] = NULL;
    }
};

char word[SIZE];
int n, m;

void add(int i, Node *cur)
{
    if (word[i] == '\0')
        return ;
    int id = word[i] - 'a';
    Node *next = cur->son[id];
    if (! next) {
        cur->son[id] = new Node();
        next = cur->son[id];
    }
    ++ next->cnt;
    add(i + 1, next);
}

int query(int i, Node *cur)
{
    if (! cur)
        return 0;
    if (word[i] == '\0')
        return cur->cnt;
    int id = word[i] - 'a';
    return query(i + 1, cur->son[id]);
}

void destroy(Node *cur) {
    for (int i = 0; i < N; ++ i) {
        if (cur->son[i])
            destroy(cur->son[i]);
    }
    delete cur;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    Node *root = new Node();
    scanf("%d", &n);
    while (n --) {
        scanf("%s", word);
        add(0, root);
    }
    scanf("%d", &m);
    while (m --) {
        scanf("%s", word);
        printf("%d\n", query(0, root));
    }
    destroy(root);
    return 0;
}
