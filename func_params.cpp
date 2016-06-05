/*
以函数作为算法参数的例子举例
for_each(begin_iterator, end_iterator, func)
func接受1个参数，并对该参数进行处理
*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void print(int elem)
{
	cout << elem << endl;
}

int main(int argc, char* argv[])
{
	list<int> col;
	
	
	for(int i = 0; i < 5; ++i)
	{
		col.push_front(i);
	}
	
	for_each(col.begin(), col.end(), print);
	
	return 0;
	
}
