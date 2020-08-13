# include <iostream>
using namespace std;

class Note
{
public:
	int x;
	int y;
	int f;
	int step;
};

int main()
{
	class Note que[2501];
	int a[51][51] = { 0 }, book[51][51] = { 0 };
	int next[4][2] = { {0, 1},	// right
		{1, 0},					// down
		{0, -1},				// left
		{0, 1} };				// up
	int head, tail;
	int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;
	cout << "\nThe maze's ROW = ";
	cin >> n;
	cout << "\nThe maze's COLUMN = ";
	cin >> m;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cout << "\nPlease input ROAD(0) or STONE(1) a [" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
	cout << "\nStart X = ";
	cin >> startx;
	cout << "\nStart Y = ";
	cin >> starty;
	cout << "\nEnd X = ";
	cin >> p;
	cout << "\nEnd Y = ";
	cin >> q;

	// Queue initialization 
	head = 1;
	tail = 1;
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].step = 0;
	tail++;
	book[startx][starty] = 1;
	flag = 0;	// arrive?
	while (head < tail)
	{
		for (k = 0; k <= 3; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			if (tx < 1 || tx > n || ty < 1 || ty > m)	// out of range?
			{
				continue;
			}
			if (a[tx][ty] == 0 && book[tx][ty] == 0)	// stone or road?
			{
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].step = que[head].step + 1;
				tail++;
			}

			if (tx == p && ty == q)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			break;

		}
		head++;
	}

	cout <<"\n\nFinal Step = \40"<< que[tail - 1].step << endl;
	return 0;

}