#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int qxmove[] = {0, 1, 1, 1, 0, -1, -1, -1},
	qymove[] = {-1, -1, 0, 1, 1, 1, 0, -1},
	kxmove[] = {1, 2, 2, 1, -1, -2, -2, -1},
	kymove[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int row, column, nq, nk, np, r, c, ans;
int queen[100][2], knight[100][2];
char board[1001][1001];

bool check(int x, int y)
{
	if (x < 1 || x > row || y < 1 || y > column)
		return false;
	if (board[x][y] == '2')
		return false;
	return true;
}

void doit(int x, int y, char type)
{
	int tx, ty;
	switch(type) {
	case 'Q':
		for (int i = 0; i < 8; i ++)
		{
			tx = x;		ty = y;
			while (true)
			{
				tx += qxmove[i];
				ty += qymove[i];
				if (check(tx, ty))
				{
					if (board[tx][ty] == '0')
					{
						board[tx][ty] = '1';
						ans --;
					}
				}				
				else
					break;
			}
		}
		break;

	case 'K':
		for (int i = 0; i < 8; i ++)
		{
			tx = x + kxmove[i];
			ty = y + kymove[i];
			if (check(tx, ty) && board[tx][ty] == '0')
			{
				board[tx][ty] = '1';
				ans --;
			}
		}
		break;

	default :
		break;
	}
}

int main()  
{  
	//freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
    
	int cases = 1;
	while (scanf( "%d%d", &row, &column ) && row != 0 && column != 0)
	{
		ans = row * column;
		memset(board, '0', sizeof(board));

		scanf( "%d", &nq );
		for (int i = 0; i < nq; i ++)
		{
			scanf( "%d%d", &queen[i][0], &queen[i][1] );
			board[ queen[i][0] ][ queen[i][1] ] = '2';
		}
		scanf( "%d", &nk );
		for (int i = 0; i < nk; i ++)
		{
			scanf( "%d%d", &knight[i][0], &knight[i][1] );
			board[ knight[i][0] ][ knight[i][1] ] = '2';
		}
		scanf( "%d", &np );
		for (int i = 0; i < np; i ++)
		{
			scanf( "%d%d", &r, &c );
			board[r][c] = '2';
		}
		ans -= (nq + nk + np);

		for (int i = 0; i < nq; i ++)
			doit(queen[i][0], queen[i][1], 'Q');

		for (int i = 0; i < nk; i ++)
			doit(knight[i][0], knight[i][1], 'K');

		printf( "Board %d has %d safe squares.\n", cases ++, ans );
	}

    return 0;  
}  
