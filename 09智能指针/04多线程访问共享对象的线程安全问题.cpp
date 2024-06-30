#include <iostream>
#include <memory>
#include <thread>
using namespace std;

/*
C++��Դ�����muduo��
���̷߳��ʹ��������̰߳�ȫ����
*/

class A
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
	void testA() { cout << "�ǳ����õķ�����" << endl; }
};
// ���߳�
void handler01(weak_ptr<A> pw)
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	 // q����A�����ʱ����Ҫ�������A�����Ƿ���
	shared_ptr<A> sp = pw.lock();
	if (sp != nullptr)
	{
		sp->testA();
	}
	else
	{
		cout << "A�����Ѿ������������ٷ��ʣ�" << endl;
	}
}
// main�߳�
int main()
{
	{
		shared_ptr<A> p(new A());
		thread t1(handler01, weak_ptr<A>(p));
		t1.detach();
	}
	std::this_thread::sleep_for(std::chrono::seconds(20));

	return 0;
}