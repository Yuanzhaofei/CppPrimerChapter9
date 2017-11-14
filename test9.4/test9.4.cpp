#include<vector>
#include<iostream>
#include<array>
#include<list>
using namespace std;
vector<int>::iterator findInt(vector<int>::iterator begin, vector<int>::iterator end, int i) {
	while (begin != end) {
		if (*begin == i)
			return begin;
		++begin;
	}
	cout << "未找到元素。" << endl;
	return end;//没有找到元素则返回尾后迭代器。
}
int main() {

	//test9.11
	vector<int> v1 = { 0,1,2,3,4,5 };//列表初始化
	vector<int> v2(v1);//拷贝初始化1
	vector<int> v3(v1.begin(), v1.end());//拷贝初始化2
	vector<int> v4 = v1;//赋值初始化
	vector<int> v5(4, 1);//构造初始化
	vector<int> v6(4);//构造初始化
	//test9.13
	list<int> l1 = { 1,2,3,4,5,6,7 };
	vector<int> vi1 = { 1,2,3,4,5 };
	vector<double> vd1(l1.begin(), l1.end()), vd2(vi1.begin(), vi1.end());
	auto it1 = v1.begin(), it2 = v5.begin();
	cout << *it1 << ends<<*it2<<endl;
	swap(v1, v5);//交换容器不会导致迭代器失效？
	cout << *it1 << ends << *it2 << endl;
	v1 = v5;
	//cout<<*it2;//it2在复制操作前指向v1的首元素，复制操作后会失效；
	//test9.14
	list<char *> clist = { "a","zhaofei","xiaoting" };
	vector<string> svec;
	svec.assign(clist.begin(), clist.end());

	cout << v1.max_size();
	system("pause");
	return 0;

}