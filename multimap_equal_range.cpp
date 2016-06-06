/*
以下显示了multimap中查找重复元素的方法，使用equal_range函数
也可以调用lower_bound upper_bound 实现
*/
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[])
{
	multimap<int, int> intmap;
	
	intmap.insert(make_pair(1, 2));
	intmap.insert(make_pair(1, 3));
	intmap.insert(make_pair(1, 4));
	intmap.insert(make_pair(1, 25));
	intmap.insert(make_pair(2, 2));
	
	typedef multimap<int, int>::iterator iterator;
	pair<iterator, iterator> ret;
	ret = intmap.equal_range(1);
	iterator it = ret.first;
	iterator end = ret.second;
	
	while(it != end)
	{
		cout << "(" << it->first << ", " << it->second << ")" << endl;
		++it;
	}
	
	return 0;
}
