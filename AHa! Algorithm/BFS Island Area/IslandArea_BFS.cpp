# include <iostream>
using namespace std;

class note 
{
public:
	int x;		
	int y;
};

void import(int m, int n, int arr[51][51])
{
	for(int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}

int main()
{
	class note que[2501];
	int head, tail;
	int a[51][51] = { 0 };
	int book[51][51] = { 0 };
	int i, j, k, sum, max = 0, mx, my, n, m, StartX, StartY, tx, ty;

	// define a direction array
	int next[4][2] = { {0, 1},		// right
		{0, -1},					// left
		{1, 0},						// up
		{-1, 0} };					// down

	cout << "Row = \40";
	cin >> m;
	cout << "Column = \40";
	cin >> n;
	cout << "Start X = \40";
	cin >> StartX;
	cout << "Start Y = \40";
	cin >> StartY;
	cout << "\n\nRow = \40" << m << ",\40Column = \40" << n << endl;
	cout << "\nStart X = \40" << StartX << ",\40Start Y = \40" << StartY << endl;

	// input map
	cout << "Please input map(2-dimensional array):" << endl;
	import(m, n, a);

	// queue initilization
	head = 1;
	tail = 1;
	// insert start into queue
	que[tail].x = StartX;
	que[tail].y = StartY;
	tail++;
	book[StartX][StartY] = 1;
	sum = 1;

	// queue not empty 
	while (head < tail)
	{
		// four directions
		for (k = 0; k < 4; k++)
		{
			// the next
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			// out of region?
			if (tx <1 || tx > m || ty <1 || ty > n) {
				continue;
			}

			// land ? book = 0?
			if (a[tx][ty] > 0 && book[tx][ty] == 0)
			{
				sum++;
				book[tx][ty] = 1;

				// add new point to queue
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
			
		}
		head++;		//!!!don't forget 
		// when one point find out, head++ --> start with the next point

	}

	cout << "The area of the island is : \40\40" << sum << endl;

	system("pause");
	cout << "\n\n\n" << endl;
	return 0;
}