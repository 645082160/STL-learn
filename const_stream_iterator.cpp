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
  //这里注意：如果写成
  //	vector<int> v(istream_iterator<int>(cin), istream_iterator<int>()); 会出现编译错误，暂时没搞懂原因？
	vector<int> v((istream_iterator<int>(cin)), (istream_iterator<int>()));
	
	print("v", v);
	
	sort(v.begin(), v.end());
	print("sort v", v);
	
	unique_copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	return 0;
}
