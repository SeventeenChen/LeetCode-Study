# include <iostream>
using namespace std;

int n, m, p, q, min = 99999999;
int a[51][51], book[51][51], final[51][51];

void dfs(int x, int y, int step) 
{
	int next[4][2] = { {0, 1},	// right
		{1, 0},					// down
		{0, -1},				// left
		{0, 1} };				// up

	int tx, ty, k;
	if (x == p && y == q)		// arrive 
	{
		if (step < min)
		{
			min = step;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					final[i][j] = 0;
					if (book[i][j])
						final[i][j] = book[i][j];
					//cout << book[i][j];

				}
			}
		}
		return;		// vital
	}

	for (k = 0; k <= 3; k++)	// all 4 kinds 
	{
		tx = x + next[k][0];
		ty = y + next[k][1];

		if (tx < 1 || tx > n || ty < 1 || ty > m)	// out of range?
		{
			continue;
		}

		if (a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}

	return;
}

int main() 
{
	int i, j, StartX, StartY;
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
	cin >> StartX;
	cout << "\nStart Y = ";
	cin >> StartY;
	cout << "\nEnd X = ";
	cin >> p;
	cout << "\nEnd Y = ";
	cin >> q;
	book[StartX][StartY] = 1;
	dfs(StartX, StartY, 0);
	cout << "\n" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (final[i][j])
			{
				cout << "[" << i << "][" << j << "]" << endl;
			}
		
		}
	}

	cout << "\n\nThe minimal step = \40" << min << endl;
	cout << "\n\n\n" << endl;
	return 0;
}


