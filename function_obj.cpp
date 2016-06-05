/*
以下举例function obj，这里需要注意函数指针与函数对象使用的区别
*
/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
class Print
{
public:
  //必须重载()函数调用运算符
	void operator()(int elem) const
	{
		cout << elem << endl;
	}
};

int main(int argc, char* argv[])
{
	list<int> col;
	
	
	for(int i = 0; i < 5; ++i)
	{
		col.push_front(i);
	}
	//注意调用方式，Print()
	for_each(col.begin(), col.end(), Print());
	
	return 0;
	
}
