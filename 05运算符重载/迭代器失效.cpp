#include <iostream>
#include <vector>
using namespace std;

/*
������ʧЧ����
1.������Ϊʲô��ʧЧ��
a������������rease�����󣬵�ǰλ�õ�����ĩβԪ�ص����еĵ�����ȫ��ʧЧ��
b������������insert�����󣬵�ǰλ�õ�����ĩβԪ�ص����еĵ�����ȫ��ʧЧ��
     ��������Ȼ��Ч         ������ȫ��ʧЧ
��Ԫ��    ->    �����/ɾ����     ->    ĩβԪ��

c��insert��˵��������������ڴ�����
       ԭ�����������еĵ�������ȫ��ʧЧ��
��Ԫ��    ->   �����/ɾ����   ->  ĩβԪ��

d����ͬ�����ĵ������ǲ��ܽ��бȽ������

2.������ʧЧ�Ժ��������ô�����
�Բ���/ɾ����ĵ��������и��²���
*/
int main() {
	vector<int> vec; // ����
	for (int i = 0; i < 20; ++i) {
		vec.push_back(rand() % 100 + 1); // push_back() ��Vector������һ��Ԫ��
	}

	for (int v : vec) {
		cout << v << " ";
	}
	cout << endl;
#if 0

	//��vec�������е�ż��ǰ�����һ��ż��ֵС��1������
	auto it = vec.begin();
	for (; it != vec.end(); ++it) {
		if (*it % 2 == 0) {
			vec.insert(it, *it - 1);
			break;
		}
	}
#endif

#if 0
	//�޸ĺ�Ĵ���
	//��vec�������е�ż��ǰ�����һ��ż��ֵС��1������
	auto it = vec.begin();
	for (; it != vec.end(); ++it) {
		if (*it % 2 == 0) {
			it = vec.insert(it, *it - 1);
			++it;
			//break;
		}
}
#endif

#if 0
	//��vec���������е�ż��ȫ��ɾ��
	auto it = vec.begin();
	for (; it != vec.end(); ++it) {
		if (*it % 2 == 0) {
			//������ʧЧ�����⣬��һ�ε���erase�Ժ󣬵�����it��ʧЧ��
			vec.erase(it); // insert(it, val)  erase(it)
			//break;
		}
	}
#endif

#if 0
	//�޸ĺ�Ĵ���
	//��vec���������е�ż��ȫ��ɾ��
	auto it = vec.begin();
	while ( it != vec.end()) {
		if (*it % 2 == 0) 
		{
			it = vec.erase(it); // insert(it, val)  erase(it)
			//break;
		}
		else {
			++it;
		}
	}
	for (int v : vec) {
		cout << v << " ";
	}
	cout << endl;
#endif
	for (int v : vec) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}