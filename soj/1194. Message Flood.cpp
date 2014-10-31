#include <iostream>
#include <cstdio>

using namespace std;

struct tree {
    int mark;
    tree *node[26];
    tree() : mark(0)
    {
        for (int i = 0; i < 26; i ++)
            node[i] = NULL;
    }
} *root;

void updata(char *s);
void visit(tree *p, char *s, int mark);
void release(tree *root);

int ans, n, m;
char str[11];

int main()
{
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    
    while(scanf( "%d%d", &n, &m ), n)
    {

        root = new tree; 
        ans = 0;
        
        for (int i = 0; i < n; i ++)
        {
            scanf( "%s", str );
            updata(str);
            visit(root, str, 1);
        }
        
        for (int i = 0; i < m; i ++)
        {
            scanf( "%s", str );
            updata(str);
            visit(root, str, 0);
        }
        
        printf( "%d\n", ans );
        release(root);
    }
    
    return 0;
}

void updata(char *s)                           
{
     for(int i = 0; s[i]; i++)
         if(s[i] >= 'A' && s[i] <= 'Z')         
              s[i] = s[i] - 'A' + 'a';           
}

void visit(tree *p, char *s, int mark)
{
    int index = (*s) - 'a';
    
    if (p->node[index])
        p = p->node[index];
    else
    {
        if (!mark)
            return ;
        p->node[index] = new tree;
        p = p->node[index];
    }
    
    if (s[1])
        visit(p, s+1, mark);
    else
    {
        if (p->mark != mark)
        {
            ans += (mark ? 1 : -1);
            p->mark = mark;
        }
    }
}

void release(tree *root)
{
    for (int i = 0; i < 26; i ++)
        if (root->node[i])
            release(root->node[i]);
    delete root;     
}
