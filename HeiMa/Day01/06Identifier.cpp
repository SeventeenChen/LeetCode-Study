# include <iostream>
using namespace std;

// 标识符
// 不能是关键字
// 只能用字母、数字、下划线
// 第一个字符必须为字母或者下划线
// 字母区分大小写
// “见名知意”

int main()
{
	// 1、不能是关键字
	// int int = 10 ---> ERROR

	// 2、只能用字母、数字、下划线
	int abc = 10;
	int _abc = 20;
	int _123abc = 30;
	// 3、第一个字符必须为字母或者下划线
	// int 123abd = 40;

	// 4、字母区分大小写
	int aaa = 100;
	// cout << AAA << endl;

	// “见名知意”

	int num1 = 10;
	int num2 = 20;
	int sum;
	sum = num1 + num2;
	cout << sum << endl;

	
	system("pause");

	return 0;
}