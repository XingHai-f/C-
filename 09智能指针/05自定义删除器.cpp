#include <iostream>
#include <memory>
#include <thread>
#include <functional>
using namespace std;

/*
����ָ���ɾ���� deletor
����ָ�룺�ܹ���֤��Դ���Ե��ͷ� delete ptr;
*/
// unique_ptr shard_ptr
/*
~unique_ptr(){ ��һ����������ĵ��� deletor(ptr);}
template<typename T>
class default_delete
{
public:
	void operator()(T *ptr)
	{
		delete ptr;
	}
};
*/

template<typename T>
class MyDeletor
{
public:
	void operator()(T* ptr)const
	{
		cout << "call MyDeletor.operator()" << endl;
		delete[]ptr;
	}
};

template<typename T>
class MyFileDeletor
{
public:
	void operator()(T* ptr)const
	{
		cout << "call MyFileDeletor.operator()" << endl;
		fclose(ptr);
	}
};
int main()
{
	// unique_ptr<int, MyDeletor<int>> ptr1(new int[100]); // delete []ptr; 
	// unique_ptr<FILE,MyFileDeletor<FILE>> ptr2(fopen("data.txt", "w"));

	//lambda���ʽ =���������� function
	unique_ptr<int, function<void(int*)>>ptr1(new int[100],
		[](int* p)->void {
			cout << "call lambda release new int[100]" << endl;
			delete[]p;
		});
	unique_ptr<FILE, function<void(FILE*)>>ptr2(fopen("data.txt","w"),
		[](FILE* p)->void {
			cout << "call lambda release new fopen" << endl;
			fclose(p);
		});

	return 0;
}