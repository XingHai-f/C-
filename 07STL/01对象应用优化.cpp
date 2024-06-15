#include <iostream>
using namespace std;

class Test
{
public:
	// Test()  Test(10)  Test(10,10)  
	Test(int a = 5, int b = 5)
		:ma(a), mb(b)
	{
		cout << "Test(int,int)" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
	Test(const Test& src) :ma(src.ma), mb(src.mb)
	{
		cout << "Test(const Test& src)" << endl;
	}
	void operator=(const Test& src)
	{
		ma = src.ma;
		mb = src.mb;
		cout << "operator=" << endl;
	}
private:
	int ma; 
	int mb;
};
Test t1(10, 10); // 1.Test(int,int)
int main()
{
#if 0
	Test t1;
	Test t2(t1);
	Test t3 = t1;
	/*
	Test(20) ��ʾ������ʱ����  �������ڣ��������
	C++���������ڶ�������Ż�������ʱ���������¶����ʱ����ʱ����Ͳ������ˣ�
	ֱ�ӹ����¶���Ϳ�����
	*/
	Test t4 = Test(20); // Test t4(20); û������

	cout << "--------------------" << endl;

	t4 = t2; // ���ø�ֵ��������غ����������¶������
	// t4.operator=(const Test& t)
	// ��ʾ������ʱ����
	t4 = Test(30);
	t4 = (Test)30; // int->Test(int)
	// ��ʽ������ʱ����
	t4 = 30; // Test(30)  int->Test(int)

	cout << "--------------------" << endl;
	// pָ�����һ���Ѿ���������ʱ����
	// Test *p = &Test(40);
	const Test &ref = Test(50);

	cout << "--------------------" << endl;
#endif

	Test t2(20, 20); // 3.Test(int,int);
	Test t3 = t2; // 4.Test(const Test& src)
	// static Test t4(30,30)
	static Test t4 = Test(30, 30); // 5.Test(int,int);
	t2 = Test(40, 40); // 6.Test(int,int);  operator=  ~Test()
	t2 = (Test)(50, 50); // 7.Test(int,int);   operator=  ~Test()
	t2 = 60; // 8.Test(int,int);   operator=  ~Test()
	Test* p1 = new Test(70, 70); // 9.Test(int,int);
	Test* p2 = new Test[2]; // 10.Test(int,int);  Test(int,int);
	Test* p3 = &Test(80, 80); // 11.Test(int,int);  ~Test()
	const Test& p4 = Test(90, 90); // 12.Test(int,int);
	delete p1; // 13.~Test()
	delete p2; // 14.~Test()  ~Test()

	return 0;
}
Test t5(100, 100); // 2.Test(int,int);