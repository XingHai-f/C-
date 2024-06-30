#include <iostream>
#include <memory>
using namespace std;

// ����ָ�� ��֤��������Դ���Զ��ͷ�
// ����ջ�ϵĶ�����������Զ���������������������Դ���Զ��ͷŵ�
// CSmartPtr<int> *p = new CSmartPtr<int>(new int); delete p;��ָ��
template<typename T>
class CSmartPtr
{
public:
	CSmartPtr(T *ptr=nullptr
		:mptr(ptr)){}
	~CSmartPtr() 
	{ 
		delete mptr;
		mptr = nullptr;
	}

	T& operator*() { return *mptr; }
	T& operator->() { return mptr; }
private:
	T* mptr;
};
int main() 
{
	/*
	CSmartPtr<int> ptr1(new int);

	// data�� heap�� stack��
	int* p = new int(10);
	*p = 10;
	delete p;
	*/

	/* 
	�������ü���������ָ��
	auto_ptr:C++������
	C++11�±�׼:
	scoped_ptr
	scoped_ptr(const scoped_ptr<T>&) = delete;
	scoped_ptr<T>& operator=(const scoped_ptr<T>&) = delete;

	�Ƽ�ʹ�ã�
	unique_ptr
	unique_ptr(const unique_ptr<T>&) = delete;
	unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;



	��ô���ǳ���������⣡����

	//CSmartPtr<int> p1(new int);
	//CSmartPtr<int> p2(p1);

	auto_ptr<int> ptr1(new int);
	auto_ptr<int> ptr2(ptr1);

	*ptr2 = 20;
	cout << *ptr1 << endl;

	���Ƽ�ʹ��auto_ptr,vector<auto_ptr<int>> vec1;vec2(vec1);

	std::move => C++11 ��ֵ���� std::move�õ���ǰ��������ֵ����
	*/

	unique_ptr<int> p1(new int);
	unique_ptr<int> p2(std::move(p1));

	return 0;
}