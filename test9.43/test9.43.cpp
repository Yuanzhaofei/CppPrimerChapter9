//练习多种改变string大小的方法
#include<string>
#include<iostream>
#include<stack>
using namespace std;
//函数声明：
string & replaceStr(string &, const string &, const string&);
string& addName(string &, const string &, const string &);
int main() {
	string s("thu a thu b thu c ");
	replaceStr(s, "thu", "tsinghua");
	cout << s << endl;
	string name("yuan");
	cout << addName(name, "Mr. ", " III") << endl;
	cout<<stoi("2");
	system("pause");
	return 0;
}
//函数定义：使用newVal替换s中所有的oldVal
string&  replaceStr(string & s, const string & oldVal, const string& newVal) {
	auto itS = s.begin();
	while (itS != s.end()&&static_cast<unsigned int>(s.end()-itS)>=oldVal.size()) {//itS指向位置之后的元素数量不能小于oldVal的大小
		string curr(itS, itS + oldVal.size());//声明一个临时strig表示s中itS迭代器开始与oldVal大小相同的string
		if (curr == oldVal) {//找到oldVal
			itS = s.erase(itS, itS + oldVal.size());//首先删除oldVal,使用迭代器版本的erase,此时itS指向被删元素之后的元素
			itS = s.insert(itS, newVal.begin(), newVal.end()) + newVal.size();//在下一个元素之前添加newVal(迭代器版本的insert),
		//上述操作后，itS指向下一个元素
		}
		else
			++itS;
	}
	return s;
}

//接受string，为其添加前缀和后缀
string& addName(string &name, const string &bef, const string &aft) {
	//name.insert(0, bef);//添加前缀
	//return name.append(aft);
	name.insert(0, bef); 
	return name.insert(name.size(), aft);

}