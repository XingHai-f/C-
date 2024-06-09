/*
�麯���Ͷ�̬��
���⣺�ǲ����麯���ĵ���һ���Ƕ�̬�󶨣� �϶�����
����Ĺ��캯�����У������麯����Ҳ�Ǿ�̬�󶨣����캯���е��������������飩�����ᷢ����̬�󶨣�
*/

#include <iostream>
using namespace std;

class Base {
public:
	Base(int data = 0) :mb(data) { cout << "Base()" << endl; }
	~Base() { cout << "~Base()" << endl; }
	virtual void show() { cout << "Base::show()" << endl; }
protected:
	int mb;
};

class Derive:public Base {
public:
	Derive(int data = 0) :Base(data), md(data) { cout << "Derive()" << endl; }
	~Derive() { cout << "~Derive()" << endl; }
	void show() { cout << "Derive::show()" << endl; }
private:
	int md;
};

int main() {
	Base b;
	Derive d;

	// ��̬�󶨣��ö���������麯�����Ǿ�̬��
	b.show(); // �麯��  call Base::show()
	d.show(); // �麯��  call Base::show()

	// ��̬�󶨣�������ָ������麯���� 
	Base* pb1 = &b;
	pb1->show();
	Base* pb2 = &d;
	pb2->show();

	Base& rb1 = b;
	rb1.show();
	Base& rb2 = d;
	rb2.show();
	return 0;
}