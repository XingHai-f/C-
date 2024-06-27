#include <iostream>
using namespace std;

class Test
{
public:
	Test(int data = 10) :ma(data)
	{
		cout << "Test(int)" << endl;
	}
	~Test() { cout << "~Test()" << endl; }
	Test(const Test& t) :ma(t.ma)
	{
		cout << "Test(const Test& t) " << endl;
	}
	void operator=(const Test& t)
	{
		cout << "operator=" << endl;
		ma = t.ma;
	}
	int getData()const { return ma; }
private:
	int ma;
};

/*
1.�����������ݹ����У��������Ȱ����ô��ݣ���Ҫ��ֵ����
2.�������ض����ʱ��Ӧ�����ȷ���һ����ʱ���󣬶���Ҫ����һ��������Ķ���
3.���շ���ֵ�Ƕ���ĺ������õ�ʱ�����Ȱ���ʼ���ķ�ʽ���գ���Ҫ����ֵ�ķ�ʽ����
*/
Test GetObject(Test &t)
{
	int val = t.getData();
	/*Test tmp(val);
	return tmp;*/
	//������ʱ����
	return Test(val); //3.ֱ�ӹ���t2
}

int main()
{
	Test t1;
	Test t2 = GetObject(t1);
	//t2 = GetObject(t1);

	return 0;
}

