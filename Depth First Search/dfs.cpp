#include <iostream>
using namespace std;

int book[10] = { 0 };
int a[10] = { 0 };
int n;
int t = 0;		// 排列的总数

void dfs(int step) {
	int i;
	
	if (step == n + 1) {
		for (i = 1; i <= n; i++) {
			cout << a[i];
		}
		t++;
		cout << "\n";

		return;
	}

	for (i = 1; i <= n; i++)
	{
		// 判断i是否还在手上
		if (book[i] == 0) {
			a[step] = i;	//i放入step中
			book[i] = 1;	//标签置为1
			dfs(step + 1);	//下一个盒子（step+1）
			book[i] = 0;	//一次搜索结束，标签置为0，以便开始下一次搜索
		}
		
	}

	return;
}

int main() {
	cout << "Please input the number[1,10) of the balls:";
	cin >> n;
	dfs(1);
	cout << "\n\n Total number = \40" << t << endl;
	return 0;
}
