# include <iostream>
using namespace std;

class note {
public:
	int x;
	int y;
};

char a[21][21];

int getnum(int i, int j)
{
	int sum, x, y;

	x = i;
	y = j;
	sum = 0;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		x--;	// up 
	}

	x = i;
	y = j;		// back to original location
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		x++;	// down 
	}
	x = i;
	y = j;		// back to original location
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		y++;	// right 
	}
	x = i;
	y = j;		// back to original location
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		y--;	// left 
	}

	return sum;
}

int main()
{
	class note que[401];		// 20 * 20 
	int head, tail;
	int book[21][21] = { 0 };	// mark the location visit or not
	int i, j, k, sum, max = 0, mx, my, n, m, startx, starty, tx, ty;

	int next[4][2] = { {0, 1},	// right
		{0, -1},				// left
		{1, 0},					// up
		{-1, 0} };				// down

	cout << "Row = \40";
	cin >> m;
	cout << "Column = \40";
	cin >> n;
	cout << "Start X = \40";
	cin >> startx;
	cout << "Start Y = \40";
	cin >> starty;
	cout << "\n\nRow = \40" << m << ",\40Column = \40" << n <<  endl;
	cout << "\nStart X = \40" << startx << ",\40Start Y = \40" << starty << endl;

	for (i = 0; i < m; i++)
	{
		cout << "\nPlease input Row \40" << i + 1 << ":\40\40";
		cin >> a[i];
	}

	// queue initilization
	head = 1;
	tail = 1;

	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	max = getnum(startx, starty);
	mx = startx;
	my = starty;
	while (head < tail)		// queue not empty
	{
		for (k = 0; k < 4; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			if (tx < 0 || tx > m - 1 || ty < 0 || ty > n - 1)
				continue;

			if (a[tx][ty] == '.' && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;

				sum = getnum(tx, ty);

				if (sum > max)
				{
					max = sum;
					mx = tx;
					my = ty;
				}
			}
		}
		head++;		// one point extensition over, head + 1 -> next point
	}

	cout << "\n\n\n Max enemy = " << max << endl;
	cout << "The location of the BOMB is: " << mx << "\40" << my << endl;
	cout << "\n\n\n" << endl;

	return 0;
}