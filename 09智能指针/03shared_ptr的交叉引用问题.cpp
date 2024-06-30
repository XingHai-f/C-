#include <iostream>
#include <memory>
using namespace std;

/*
shared_ptr:ǿ����ָ�� ���Ըı���Դ�����ü���
weak_ptr:������ָ�� ����ı���Դ�����ü���
operator* operator->
weak_ptr =>(�۲�) shared_ptr =>(�۲�) ��Դ(�ڴ�)

ǿ����ָ��ѭ�����ã��������ã���ʲô���⣿ʲô�������ô�����
���new��������Դ�޷��ͷţ�������Դй¶����
��������ʱ����ǿ����ָ�룻���ö���ĵط���ʹ��������ָ��
*/
class B;
class A
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
	weak_ptr<B> _ptrb;
private:
};
class B
{
public:
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
	weak_ptr<A> _ptra;
};

int main()
{
	shared_ptr<A> pa(new A());
	shared_ptr<B> pb(new B());

	pa->_ptrb = pb;
	pb->_ptra = pa;

	cout << pa.use_count() << endl;
	cout << pb.use_count() << endl;

	return 0;
}


