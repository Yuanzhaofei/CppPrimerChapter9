//��ϰ���ָı�string��С�ķ���
#include<string>
#include<iostream>
#include<stack>
using namespace std;
//����������
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
//�������壺ʹ��newVal�滻s�����е�oldVal
string&  replaceStr(string & s, const string & oldVal, const string& newVal) {
	auto itS = s.begin();
	while (itS != s.end()&&static_cast<unsigned int>(s.end()-itS)>=oldVal.size()) {//itSָ��λ��֮���Ԫ����������С��oldVal�Ĵ�С
		string curr(itS, itS + oldVal.size());//����һ����ʱstrig��ʾs��itS��������ʼ��oldVal��С��ͬ��string
		if (curr == oldVal) {//�ҵ�oldVal
			itS = s.erase(itS, itS + oldVal.size());//����ɾ��oldVal,ʹ�õ������汾��erase,��ʱitSָ��ɾԪ��֮���Ԫ��
			itS = s.insert(itS, newVal.begin(), newVal.end()) + newVal.size();//����һ��Ԫ��֮ǰ���newVal(�������汾��insert),
		//����������itSָ����һ��Ԫ��
		}
		else
			++itS;
	}
	return s;
}

//����string��Ϊ�����ǰ׺�ͺ�׺
string& addName(string &name, const string &bef, const string &aft) {
	//name.insert(0, bef);//���ǰ׺
	//return name.append(aft);
	name.insert(0, bef); 
	return name.insert(name.size(), aft);

}