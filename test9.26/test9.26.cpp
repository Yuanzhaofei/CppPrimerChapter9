#include<vector>
#include<list>
#include<forward_list>
#include<iostream>
using namespace std;
int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
int main() {
	vector<int> intV(begin(ia), end(ia));
	list<int> intL(begin(ia), end(ia));
	forward_list<int> intFl(begin(ia), end(ia));
	auto it1 = intL.begin();
	//删除IntL中的奇数元素
	while (it1 != intL.end()) {
		if (*it1 % 2)
			it1 = intL.erase(it1);
		else
			++it1;
	}
	for (auto i : intL) {
		cout << i << ends;
	}
	cout << endl;

	auto it2 = intV.begin();
	//删除intV中的偶数元素
	while (it2 != intV.end()) {
		if (!(*it2 % 2))
			it2 = intV.erase(it2);
		else
			++it2;
	}	
	for (auto i : intV) {
		cout << i << ends;
	}
	cout << endl;
	//检验forward_list 的操作
	auto prev = intFl.before_begin();
	auto curr = intFl.begin();
//	cout << *(++prev) << ends;
	intFl.erase_after(prev);
	cout << *(++prev);//删除单向链表中的元素不会使得首前迭代器失效
	system("pause");
	return 0;
}