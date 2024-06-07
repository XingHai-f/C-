/*
�麯������̬�󶨺;�̬��

�ܽ�һ
һ�������涨�����麯������ô����׶Σ�����������������Ͳ���һ��Ψһ��vftable�麯����
�麯��������Ҫ�洢�����ݾ���RTTIָ����麯���ĵ�ַ������������ʱ��ÿһ���麯�������
�ص��ڴ��.rodata��

�ܽ��
һ�������涨�����麯������ô����ඨ��Ķ���������ʱ���ڴ��п�ʼ���֣���洢һ��
vfptr�麯��ָ�룬ָ����Ӧ���͵��麯����vftable��һ�����Ͷ����n������ָ��Ķ���
ͬһ���麯����

�ܽ���
һ���������麯���ĸ�������Ӱ������ڴ��С��vfptr����Ӱ������麯����Ĵ�С
*/
#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
	Base(int data = 10) :ma(data) {}
	// �麯��
	virtual void show() { cout << "Base::show()" << endl; }
	// �麯��
	virtual void show(int) { cout << "Base::show(int)" << endl; }
protected:
	int ma;
};
class Derive :public Base {
public:
	Derive(int data=20):Base(data),mb(data){}
	/*
	�ܽ���
	����������еķ������ͻ���̳�����ĳ������������ֵ���������������б���ͬ��
	���һ���ķ�����virtual�麯������ô�����������������Զ�������麯��
	��д�� = ������
 	*/
	void show() { cout << "Derive::show()" << endl; }
private:
	int mb;
};

int main() {
	Derive d(50);
	Base* pb = &d;

	/*
	pb->Base Base::show() �������show����ͨ�������ͽ��о�̬��
												call Base::show
	pb->Base Base::show() �������show���麯�����ͽ��ж�̬����
	mov eax, dword ptr[pb]
	mov ecx, dword ptr[eax]
	call ecx ���麯���ĵ�ַ�� ��̬������ʱ�ڣ��İ󶨣������ĵ��ã�
	*/
	pb->show(); // ��̬������ʱ�ڣ��İ󶨣������ĵ��ã�
	
	/*
	Base::show(int) ��һ���麯������ʱ�͵ö�̬����
	mov eax, dword ptr[pb]
	mov ecx, dword ptr[eax]
	call ecx ���麯���ĵ�ַ�� ��̬������ʱ�ڣ��İ󶨣������ĵ��ã�
	*/
	pb->show(10); // 

	cout << sizeof(Base) << endl;
	cout << sizeof(Derive) << endl;

	cout << typeid(pb).name() << endl;
	/*
	pb�����ͣ�Base -> ��û���麯��
	���Baseû���麯����*pbʶ��ľ��Ǳ���ʱ�ڵ����� *pb <=> Base����
	���Base���麯����*pbʶ��ľ�������ʱ�ڵ����� RTTI����
	pb->d��vfptr��->Derive vftable  class Derive
	*/
	cout << typeid(*pb).name() << endl;
	/*
	Base::show()
	Base::show(int)
	4
	8
	class Base * 
	class Base
	*/
}