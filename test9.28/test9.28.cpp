#include<forward_list>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

//函数声明,接收一个forward_list<string>和两个string，查找第一个，将第二个插入到第一个后面，如果没有找到，将第二个插到链表末尾
forward_list<string>::iterator insertString(forward_list<string> & strFl, const string& s1, const string &s2);

int main() {
	forward_list<string> strFl = { "a","b","c","d" };
	string s1 = "a", s2 = "e";
	cout << *(insertString(strFl, "b", s2)) << endl;
	for (auto s : strFl) {
		cout << s << ends;
	}

	//test9.34

	//test9.41从一个vector<char>初始化string
	vector<char> cV = { 'a','b','c' };
	//string s(cV, cV.begin());将char的vector容器理解为string，再提供开始位置，这样不行
	//string s(&cV, 3);//将char的vector容器理解为字符数组，再提供字符数，也不行；
	string s(cV.begin(), cV.end());//应 将string看作顺序容器，利用第299页的迭代器范围初始化
	string s(100,' '),s0;
	cout << s.capacity() << ends << s0.capacity() << endl;
	s0.reserve(100);
	cout << s.capacity() << ends << s0.capacity();
	system("pause");
	return 0;
}
//函数定义
forward_list<string>::iterator insertString(forward_list<string> & strFl, const string& s1, const string &s2) {
	//先处理strFl为空的情形
	//strFl.insert_after(strFl.before_begin(), s2);
	auto itPrev = strFl.before_begin();
	auto itCurr = strFl.begin();
	while (itCurr != strFl.end()) {
		if (*itCurr == s1) {
			//找到s1
			strFl.insert_after(itCurr, s2);
			return ++itCurr;//返回的迭代器指向插入的第二个string
		}
		else{
			//it1不指向第一个string
			++itCurr;
			++itPrev;
		}

		
	}
	//执行到此说明没有找到第一个string
	strFl.insert_after(itPrev, s2);//此时itPrev指向尾后之前的元素（首前，或尾元素），
	return ++itPrev;

}