#include<list>
#include<vector>
#include<iostream>
using namespace std;
//比较list<int>和vector<int>是否相等？
list<int> intL = { 1,2,3,4,4,6 };
vector<int> intV = { 1,2,3,4,5,6 };
bool isEqual(list<int> &, vector<int> &);
int main() {
	cout << isEqual(intL, intV);
	//练习插入元素
	intV.insert(intV.end(), 4);

	for (auto it1 = intL.begin(); it1 != intL.end(); ++it1) {
	}
	//练习删除容器中的元素
	cout<<*(intV.erase(intV.end(), intV.end())-1);
	system("pause");
	return 0;
}


bool isEqual(list<int> & intL, vector<int> & intV) {
	//判断元素数量是否相同
	if (intL.size() != intV.size())
		return false;
	auto beginL = intL.begin();
	auto beginV = intV.begin();
	while (beginL != intL.end()) {
		if (*beginL != *beginV)
			return false;
		++beginL;
		++beginV;
	}
	return true;
}