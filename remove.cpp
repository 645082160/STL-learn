/*
remove算法会通过移动来覆盖需要删除的元素，但是并不会缩减容器的容量，其返回新的终点位置，但原有的元素位置仍然有效
该程序同时展示了distance的用法
*/
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;
template<class T>
void print(const std::string& prefix, const T& continer)
{
	cout << prefix << ": ";
	copy(continer.begin(), continer.end(), ostream_iterator<typename T::value_type>(cout, " "));
	cout << endl;
}

int main()
{
	list<int> col;
	for(int i = 0; i < 6; ++i)
	{
		col.push_back(i);
		col.push_front(i);
	}
	
	print("pre list:", col);
	
	//remove算法返回一个新的终点
	list<int>::iterator newend = remove(col.begin(), col.end(), 3);
	
	print("after remove:", col);
	
	cout << "rigth cout: " << endl;
	copy(col.begin(), newend, ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "list size:" << 
		distance(col.begin(), newend) << endl;
	return 0;
}
输出：注意最后的4、5 2个元素
pre list:: 5 4 3 2 1 0 0 1 2 3 4 5 
after remove:: 5 4 2 1 0 0 1 2 4 5 4 5 
rigth cout: 
5 4 2 1 0 0 1 2 4 5 
list size:10
