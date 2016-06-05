/*
流迭代器适配器测试：
定义流迭代器，注意定义流结尾迭代器的方式
遗留问题：
定义式：istream_iterator<int> myend(); 居然会出现编译错误，提示参数类型不匹配。
查了下原因：c++中，这是规定，定义一个类时，如果要调用默认构造函数，不需要声明时加()。
  istream_iterator<int> myend(); 这种写法实质上是定义了一个返回类型为istream_iterator<int>， 参数为空的函数myend，
  如果将myend作为参数传入copy，必然引起参数不匹配的编译错误，因为myend此时是一个函数指针！
*/
#include <iostream>
#include <vector>
#include <iterator>
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
	//istream_iterator<int> myend();   会导致编译错误，实质是一个函数声明
	copy(mycin, myend, back_inserter(v));
	
	print("v", v);
	return 0;
}
