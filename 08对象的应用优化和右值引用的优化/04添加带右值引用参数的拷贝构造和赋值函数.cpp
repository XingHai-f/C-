#include <iostream>
using namespace std;
#if 0
int main() {
	// ��ֵ����
	int a = 10;
	int& b = a; // ��ֵ�����ڴ桢������  ��ֵ�����������֡���ʱ������û���֣���ʱ������û�ڴ�
	// int &&c = a; // �޷�����ֵ�󶨵���ֵ����
	/*
	int tmp = 20;
	const int &c = tmp;
	*/
	const int& c = 20; // ��������ֵ���ð�һ����ֵ
	/*
	int tmp = 20;
	 int &&d = tmp;
	*/
	int&& d = 20; // ���԰�һ����ֵ�󶨵�һ����ֵ������
	// CMyString&& e = CMyString("aaa");

	int& f = d; // һ����ֵ���ñ�����������һ����ֵ
	return 0;
}
#endif