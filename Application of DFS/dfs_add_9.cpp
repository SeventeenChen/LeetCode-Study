# include <iostream>

using namespace std;

int n = 9;
int a[9] = { 0 };
int book[9] = { 0 };
int total = 0;

void dfs(int step) {
	int i = 0;
	if (step == n) {

		if (((a[0] + a[3]) * 100 + (a[1] + a[4]) * 10 + a[2] + a[5]) == (a[6] * 100 + a[7] * 10 + a[8]))
		{
			cout << a[0] << a[1] << a[2] << "+" << a[3] << a[4] << a[5] << "=" << a[6] << a[7] << a[8] << endl;
			total++;
		}
		
		return;

	}



	for (i = 0; i < n; i++) {
		if (book[i] == 0) {
			a[step] = i + 1;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}

	}

	return;
}

int main() {
	
	cout << "The Equation is: " << endl;
	dfs(0);
	cout << "\nTotal = " << total/2;
	return 0;
}