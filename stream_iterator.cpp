/*
stl有3种迭代器适配器
1、插入
2、流
3、反向
*/
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template<class T>
void print(const std::string& prefix, const T& continer)
{
	cout << prefix << ": ";
	//注意，声明类型时需要指明typename，否则可能被认为是T的一个static变量
	copy(continer.begin(), continer.end(), ostream_iterator<typename T::value_type>(cout, " "));
	cout << endl;
}

int main()
{
	vector<int> v;
	
	//流迭代器适配器的用法
	copy(istream_iterator<int>(cin), 
		istream_iterator<int>(),
		back_inserter(v));
	
	print("v1", v);
	
	vector<int> v2;
	copy(v.begin(), v.end(), back_inserter(v2));
	print("v2", v2);
	return 0;
}
