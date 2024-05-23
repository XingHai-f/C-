#include <iostream>
#include <cstdlib>
using namespace std;

//��ģ��
template <typename T> 
class SeqStack //ģ������ + ���Ͳ����б� = ������ 
{ 
public:
	//��������������������Ͳ����б�(<T>),������Ҫ
	SeqStack(int size = 10)
		:_pstack(new T[size])
		, _top(0)
		, _size(size)
	{}
	~SeqStack()
	{
		delete[]_pstack;
		_pstack = nullptr;

	}
	SeqStack(const SeqStack<T>& stack)
		:_top(stack._top)
		:_size(stack._size)
	{
		_pstack = new T[_size];
		//��Ҫ��memcpy���п���
		for (int i = 0; i < _top; ++i)
		{
			_pstack[i] = stack._pstack[i];
		}
	}
	SeqStack<T>& operator=(const SeqStack<T>& stack)
	{
		if (this == &stack) 
			return *this;
		delete[]_pstack;
		_top = stack._top;
		_size = stack._size;
		_pstack = new T[_size];
		for (int i = 0; i < _top; ++i)
		{
			_pstack[i] = stack._pstack[i];
		}
		return *this;
	}

	void push(const T& val) // ��ջ����
	{
		if (full())
			expand();
		_pstack[_top++] = val;
	}

	void pop() // ��ջ����
	{
		if (empty())
			return;
		--_top;
	}

	T top()const // ����ջ��Ԫ��
	{
		if (empty())
			throw"stack is empty."; //���쳣Ҳ�������߼�����
		return _pstack[_top - 1];
	}
	bool full()const { return _top == _size; } // ջ��
	bool empty()const { return _top == 0; } // ջ��
private:
	T* _pstack;
	int _top;
	int _size;

	//˳��ջ�ײ����鰴2���ķ�ʽ����
	void expand()
	{
		T* ptmp = new T[_size * 2];
		for (int i = 0; i < _top; ++i)
		{
			ptmp[i] = _pstack[i];
		}
		delete[] _pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};
template <typename T>
void SeqStack<T> ::push(const T& val) // ��ջ����
{
	if (full())
		expand();
	_pstack[_top++] = val;
}

int main()
{
	SeqStack<int> s1;
	s1.push(20);
	s1.push(80);
	s1.push(78);
	s1.pop();
	cout << s1.top() << endl;
	return 0;
}

