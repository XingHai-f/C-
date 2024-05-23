// ʹ����ģ��ʵ��C++ STL�����һ��˳������ vector ��������
#include <iostream>
using namespace std;

template<typename T>
class vector
{
public:
	vector(int size = 10)
	{
		_first = new T[size];
		_last = _first;
		_end = _first + size;
	}
	~vector()
	{
		delete[]_first;
		_first = _last = _end = nullptr;
	}
	vector(const vector<T>& rhs)
	{
		int size = rhs._end - rhs._first;
		_first = new T[size];
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; ++i)
		{
			_first[i] = rhs._first[i];
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator=(const vector<T>& rhs)
	{
		if (this == &rhs)
			return *this;
		delete[]_first;
		int size = rhs._end - rhs._first;
		_first = new T[size];
		int len = rhs._last - rhs._first;
		for (int i = 0; i < len; ++i)
		{
			_first[i] = rhs._first[i];
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}
	void push_back(const T& val) // ������ĩβ���Ԫ��
	{
		if (full())
			expand();
		*_last++ = val;
	}
	void pop_back() // ������ĩβɾ��Ԫ��
	{
		if (empty())
			return;
		--_last;
	}
	T back()const // ��������ĩβ��Ԫ�ص�ֵ
	{
		return *(_last - 1);
	}
	bool full()const { return _last == _end; }
	bool empty()const {	return _first == _last;	}
	int size()const {return _last - _first;	}

private:
	T* _first;  //ָ��������ʼ��λ�� 
	T* _last; //ָ��������ЧԪ�صĺ��λ��
	T* _end;  //ָ������ռ�ĺ��λ��

	void expand()
	{
		int size = _end - _first;
		int newSize = size * 2;
		T* newFirst = new T[newSize];
		for (int i = 0; i < size; ++i)
		{
			newFirst[i] = _first[i];
		}
		delete[] _first;
		_first = newFirst;
		_last = _first + size;
		_end = _first + newSize;
	}
};

int main()
{
	vector<int> vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100);
	}
	vec.pop_back();
	while (!vec.empty())
	{
		cout << vec.back() << " ";
		vec.pop_back();
	}
	cout << endl;
	return 0;
}