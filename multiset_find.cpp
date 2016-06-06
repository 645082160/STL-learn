/*
以下演示了multiset的find，以及遍历已找到元素的方法。
find+count
*/
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[])
{
	multiset<int> mset;
	
	mset.insert(1);
	mset.insert(1);
	mset.insert(2);
	mset.insert(1);
	mset.insert(1);
	
	copy(mset.begin(), mset.end(), ostream_iterator<int>(cout, "\n"));
	
	multiset<int>::iterator it = mset.find(1);
	if(it != mset.end())
	{
		cout << "elem found:" << endl;
		unsigned count = mset.count(1);
		for(int i = 0; i < count; ++i)
		{
			cout << *it << endl;
			++it;
		}
		
	}
	else
	{
		cout << "no elem found" << endl;
	}
	
	return 0;
}
