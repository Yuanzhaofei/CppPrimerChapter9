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
	cout << "δ�ҵ�Ԫ�ء�" << endl;
	return end;//û���ҵ�Ԫ���򷵻�β���������
}
int main() {

	//test9.11
	vector<int> v1 = { 0,1,2,3,4,5 };//�б��ʼ��
	vector<int> v2(v1);//������ʼ��1
	vector<int> v3(v1.begin(), v1.end());//������ʼ��2
	vector<int> v4 = v1;//��ֵ��ʼ��
	vector<int> v5(4, 1);//�����ʼ��
	vector<int> v6(4);//�����ʼ��
	//test9.13
	list<int> l1 = { 1,2,3,4,5,6,7 };
	vector<int> vi1 = { 1,2,3,4,5 };
	vector<double> vd1(l1.begin(), l1.end()), vd2(vi1.begin(), vi1.end());
	auto it1 = v1.begin(), it2 = v5.begin();
	cout << *it1 << ends<<*it2<<endl;
	swap(v1, v5);//�����������ᵼ�µ�����ʧЧ��
	cout << *it1 << ends << *it2 << endl;
	v1 = v5;
	//cout<<*it2;//it2�ڸ��Ʋ���ǰָ��v1����Ԫ�أ����Ʋ������ʧЧ��
	//test9.14
	list<char *> clist = { "a","zhaofei","xiaoting" };
	vector<string> svec;
	svec.assign(clist.begin(), clist.end());

	cout << v1.max_size();
	system("pause");
	return 0;

}