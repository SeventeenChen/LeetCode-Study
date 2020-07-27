# include <iostream>

using namespace std;

int main()
{
	int a[11], i, j, n, score;
	i = 0;
	j = 0;
	n = 0;
	score = 0;
	// initialization
	for (i = 0; i < 11; i++)
	{
		a[i] = 0;
		// cout << a[i] << endl;
	}

	cout << "Please input students' number:" << endl;
	cin >> n;
	cout << "There're " << n << "\tstudents." << endl;

	for (j = 0; j < n; j++)
	{
		cout << "The score of " << j + 1 << "student:" << endl;
		cin >> score;
		a[score] ++;
	}

	for (i = 0; i < 11; i++)
	{
		for (j = 0; j < a[i]; j++)
		{
			cout << i << endl;
		}
	}
	return 0;
}
