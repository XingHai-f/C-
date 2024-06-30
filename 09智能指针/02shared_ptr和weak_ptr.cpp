#include <iostream>
#include <memory>
using namespace std;

// ����Դ�������ü�������
template<typename T>
class RefCnt
{
public:
	RefCnt(T* ptr = nullptr)
		:mptr(ptr)
	{
		if (mptr != nullptr)
			mcount = 1;
	}
	void addRef() { mcount++; } // ������Դ�����ü���
	int delRef() { return --mcount; }
private:
	T* mptr;
	int mcount;
};

template<typename T>
class CSmartPtr
{
public:
	CSmartPtr(T* ptr = nullptr)
		:mptr(ptr) 
	{
		mpRefCnt = new RefCnt<T>(mptr);
	}
	~CSmartPtr()
	{
		if (0 == mpRefCnt->delRef())
		{
			delete mptr;
			mptr = nullptr;
		}
	}

	T& operator*() { return *mptr; }
	T* operator->() { return mptr; }

	CSmartPtr(const CSmartPtr<T>& src)
		:mptr(src.mptr),mpRefCnt(src.mpRefCnt)
	{
		if (mptr != nullptr)
			mpRefCnt->addRef();
	}
	CSmartPtr<T>& operator=(const CSmartPtr<T>& src)
	{
		if (this == &src)
			return *this;
		if (0 == mpRefCnt->delRef())
			delete mptr;
		mptr = src.mptr;
		mpRefCnt = src.mpRefCnt;
		mpRefCnt->addRef();
		return *this;
	}
private:
	T* mptr; // ָ�����Դ��ָ��
	RefCnt<T>* mpRefCnt; // ָ�����Դ���ü��������ָ��
};
int main()
{
	/*
	�����ü���������ָ��shared_ptr��weak_ptr
	�����ü������������ָ����Թ���ͬһ����Դ
	�����ü�������ÿһ��������Դ��ƥ��һ�����ü�����
	����ָ�� =��ʹ����Դ��ʱ�� =�����ü���+1
	����ָ�� =����ʹ����Դ��ʱ�� =�����ü���-1 =��!=0 0��Դ�ͷ���
	*/
	CSmartPtr<int> ptr1(new int);
	CSmartPtr<int> ptr2(ptr1);

	CSmartPtr<int> ptr3;
	ptr3 = ptr2;
	*ptr1 = 20;
	cout << *ptr2 << " " << *ptr3 << endl;
	return 0;
}