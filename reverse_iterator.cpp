/*
test reverse iterator
注意：每个容器都有reverse_iterator类型，单独定义时需要指明是哪种容器，这里与其他2种类型的迭代器适配器的区别！
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
	vector<int> v((istream_iterator<int>(cin)), (istream_iterator<int>()));
	
	print("v", v);
	
	cout << "reverse order:" << endl;
	copy(v.rbegin(), v.rend(), ostream_iterator<int>(cout, " "));
	
	vector<int>::reverse_iterator begin = v.rbegin();
	vector<int>::reverse_iterator end = v.rend();
	copy(begin, end, ostream_iterator<int>(cout, " "));
	return 0;
}
