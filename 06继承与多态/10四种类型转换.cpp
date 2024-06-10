#include <iostream>
using namespace std;

/*
C++�ṩ����������ת����ʽ
int a =(double) b;
const_cast��ȥ����ָ��������ã��������Ե�һ������ת��
staic_cast:���ṩ��������Ϊ��ȫ������ת����û���κ���ϵ������֮���ת���ͱ��񶨣�
reinterpret_cast������C����ǿ������ת��
dynamic_cast����Ҫ���ڼ̳нṹ�У�����֧��RTTI����ʶ������ת��
*/

class Base {
public:
	virtual void func() = 0;
};
class Derive1 :public Base {
public:
	void func() { cout << "call Derive1::func()" << endl; }
};
class Derive2 :public Base {
public:
	void func() { cout << "call Derive2::func()" << endl; }
	// Derive2ʵ���¹��ܵ�API�ӿں���
	void derive02func() { 
		cout << "call Derive2::derive02func()" << endl; 
	}

};
/*
typeid(*p).name() == "Derive"
*/
void showfunc(Base* p) {
	/*
	dynamic_cast����pָ���Ƿ�ָ��һ��Derive2���͵Ķ���
	p->vfptr->vftable RTTI��Ϣ������ǣ�dynamic_castת�����ͳɹ���
	����Derive2����ĵ�ַ����pd2�����򷵻�nullptr��
	*/
	Derive2* pd2 = dynamic_cast<Derive2*>(p);
	if (pd2 != nullptr) {
		pd2->derive02func();
	}
	else {
		p->func(); // ��̬�� *p������ Derive2 derive02func
	}
}

int main() {

	Derive1 d1;
	Derive2 d2;
	showfunc(&d1);
	showfunc(&d2);

	//const int a = 10;
	//double* p1 = (double*)&a;
	//int* p2 = const_cast<int*>(&a);  C++ת��Ҫ��a��������һ��
	//const_cast<�����������ָ�롢�������ͻ���ָ��������ͳ�Ա��ָ�� int* int&>
	//int b = const_cast<int(��)>(a);
	
	//static_cast  ���� ��=�� ������  ת��������static_cast
	int a = 10;
	char b = static_cast<int>(a);
	
	/*
	����ת��
	int* p = nullptr;
	short* p = static_cast<short*>(p);
	*/

	return 0;
}