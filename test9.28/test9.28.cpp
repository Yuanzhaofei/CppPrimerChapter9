#include<forward_list>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

//��������,����һ��forward_list<string>������string�����ҵ�һ�������ڶ������뵽��һ�����棬���û���ҵ������ڶ����嵽����ĩβ
forward_list<string>::iterator insertString(forward_list<string> & strFl, const string& s1, const string &s2);

int main() {
	forward_list<string> strFl = { "a","b","c","d" };
	string s1 = "a", s2 = "e";
	cout << *(insertString(strFl, "b", s2)) << endl;
	for (auto s : strFl) {
		cout << s << ends;
	}

	//test9.34

	//test9.41��һ��vector<char>��ʼ��string
	vector<char> cV = { 'a','b','c' };
	//string s(cV, cV.begin());��char��vector�������Ϊstring�����ṩ��ʼλ�ã���������
	//string s(&cV, 3);//��char��vector�������Ϊ�ַ����飬���ṩ�ַ�����Ҳ���У�
	string s(cV.begin(), cV.end());//Ӧ ��string����˳�����������õ�299ҳ�ĵ�������Χ��ʼ��
	string s(100,' '),s0;
	cout << s.capacity() << ends << s0.capacity() << endl;
	s0.reserve(100);
	cout << s.capacity() << ends << s0.capacity();
	system("pause");
	return 0;
}
//��������
forward_list<string>::iterator insertString(forward_list<string> & strFl, const string& s1, const string &s2) {
	//�ȴ���strFlΪ�յ�����
	//strFl.insert_after(strFl.before_begin(), s2);
	auto itPrev = strFl.before_begin();
	auto itCurr = strFl.begin();
	while (itCurr != strFl.end()) {
		if (*itCurr == s1) {
			//�ҵ�s1
			strFl.insert_after(itCurr, s2);
			return ++itCurr;//���صĵ�����ָ�����ĵڶ���string
		}
		else{
			//it1��ָ���һ��string
			++itCurr;
			++itPrev;
		}

		
	}
	//ִ�е���˵��û���ҵ���һ��string
	strFl.insert_after(itPrev, s2);//��ʱitPrevָ��β��֮ǰ��Ԫ�أ���ǰ����βԪ�أ���
	return ++itPrev;

}