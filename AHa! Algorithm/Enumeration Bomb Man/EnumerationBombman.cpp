// 枚举法 --- 炸弹人

# include <iostream>
using namespace std;

int main()
{
	char a[21][21];
	int i, j, sum, map = 0, p, q, x, y, n, m;

	cout << "Row = \40";
	cin >> m;
	cout << "Column = \40";
	cin >> n;
	cout << "\n\nRow = \40" << m << ",\40Column = \40" << n << endl;

	cout << "Wall = '#'\40Enemy = 'G'\40Space = '.' " << endl;

	for (i = 0; i < m; i++)
	{
		cout << "Please input the string in  " << i + 1 << "\40row:\40\40" ;
		cin >> a[i];
	}

	cout << "\nThe map is: " << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j]; 
		}
		cout << "\n";
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == '.')
			{
				sum = 0;	// sum the enemy number
				x = i;
				y = j;
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

				if (sum > map)	// the max enemy number before
				{
					map = sum;
					p = i;
					q = j;		// mark the exact location
				}
			}
		}
	}

	cout << "Max enemy = " << map << endl;
	cout << "The location of the BOMB is: " << p << "\40" << q << endl;
	return 0;
}
