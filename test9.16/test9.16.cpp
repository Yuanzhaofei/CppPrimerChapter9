#include<list>
#include<vector>
#include<iostream>
using namespace std;
//�Ƚ�list<int>��vector<int>�Ƿ���ȣ�
list<int> intL = { 1,2,3,4,4,6 };
vector<int> intV = { 1,2,3,4,5,6 };
bool isEqual(list<int> &, vector<int> &);
int main() {
	cout << isEqual(intL, intV);
	//��ϰ����Ԫ��
	intV.insert(intV.end(), 4);

	for (auto it1 = intL.begin(); it1 != intL.end(); ++it1) {
	}
	//��ϰɾ�������е�Ԫ��
	cout<<*(intV.erase(intV.end(), intV.end())-1);
	system("pause");
	return 0;
}


bool isEqual(list<int> & intL, vector<int> & intV) {
	//�ж�Ԫ�������Ƿ���ͬ
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