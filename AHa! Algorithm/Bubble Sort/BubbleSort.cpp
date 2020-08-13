# include <iostream>

using namespace std;

int main()
{
	int n, i, j, temp;
	int a[100] = { 0 };
	cout << "How many numbers(<100) you want to sort? \40" ;
	cin >> n;

	for (i = 0; i < n; i++) 
	{
		cout << "Please input the " << i + 1 << "\40number: ";
		cin >> a[i];
	}

	cout << "There're the numbers you want to sort " << endl;
	for (i = 0; i < n; i++)
	{
		
		cout << a[i]<<"\t";

	}


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	cout << "\n\nThere're the sorted numbers: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}

	cout << "\n" << endl;
}

