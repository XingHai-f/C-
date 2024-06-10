#include <iostream>
using namespace std;

/*
���ؼ̳У�����ĸ���    һ���������ж������
class C:public A,public B
{
};

�����ࣨ�д��麯�����ࣩ /  �����  ����̳е����Ϊ����� vbptr��vbtable
virtual:
1.���γ�Ա�������麯��
2.�������μ̳з�ʽ������̳С�����̳е��࣬��Ϊ�����
*/
class A {
public:
	virtual void func() { std::cout << "call A::func()" << endl; }
	void operator delete(void* ptr) {
		cout << "operator delete p:" << ptr << endl;
		free(ptr);
	}
private:
	int ma;
};
class B :virtual public A {
public:
	void func() { std::cout << "call B::func()" << endl; }
	void* operator new(size_t size) {
		void* p = malloc(size);
		cout << "operator new p:" << p << endl;
		return p;
	}
private:
	int mb;
};
/*
A a:4���ֽ�
B b��ma,mb  8���ֽ� + 4(vbptr) = 12       vfptr/vftable     vbptr/vbtable
*/

int main() {
	// ����ָ��ָ�������������Զָ�������������ಿ�����ݵ���ʼ��ַ
	A* p = new B(); // B::vftable
	cout << "main p:" << p << endl;
	p->func();
	delete p;

	return 0;
}