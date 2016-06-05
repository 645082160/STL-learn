/*
这里测试了下sort和unique_copy
sort对容器进行排序
unique_copy输出时会过滤掉相邻的重复元素，注意是相邻的重复元素，不相邻但是相同的元素不会被过滤。
*/
#include <iostream>
#include <vector>
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
	vector<int> v;
	//声明一个流迭代器连接到标准输入
	istream_iterator<int> mycin(cin);
	//声明一个迭代器指向流的结尾
	istream_iterator<int> myend;
	copy(mycin, myend, back_inserter(v));
	
	print("v", v);
	
	sort(v.begin(), v.end());
	print("sort v", v);
	
	unique_copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	return 0;
}
