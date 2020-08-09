# include <iostream>
using namespace std;

// 常量： 程序中不可更改的数据
#define Day 7 // 宏常量 #define 常量名 常量值

//const 修饰
//const 数据类型 常量名 = 常量值

int main()
{
	const int month = 12;
	cout << "A week = " << Day << "\40day" << endl;
	cout << "A year = " << month << "\40month" << endl;
	system("pause");

	return 0;
}
