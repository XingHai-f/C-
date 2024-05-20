#include <iostream>
using namespace std;

class Queue {
public:
	Queue(int size = 20) {
		_pQue = new int[size];
		_front = _rear = 0;
		_size = size;
	}

	~Queue() {
		delete[] _pQue;
		_pQue = nullptr;
	}

	//��Ӳ���
	void push(int val) {
		if (full())
			resize();
		_pQue[_rear] = val;
		_rear = (_rear + 1) % _size;
	}

	//���Ӳ���
	void pop() {
		if (empty())
			return;
		_front = (_front + 1) % _size;
	}

	//��ȡ��ͷԪ��
	int top() {
		return _pQue[_front];
	}

	bool full() { return (_rear + 1) % _size == _front; }
	bool empty() { return _front == _rear; }

private:
	int* _pQue; //������е�����ռ�
	int _front; //ָʾ��ͷ��λ��
	int _rear;  //ָʾ��β��λ��
	int _size;  //�������ݵ��ܴ�С

	void resize() {
		int* ptmp = new int[2 * _size];
		int index = 0;
		for (int i = _front; i != _rear; i = (i + 1) % _size) {
			ptmp[index++] = _pQue[i];
		}
		delete[]_pQue;
		_pQue = ptmp;
		_front = 0;
		_rear = index;
		_size *= 2;
	}
};

int main() {
	Queue queue;
	for (int i = 0; i < 20; ++i) {
		queue.push(rand() % 100);
	}

	while (!queue.empty()) {
		cout << queue.top() << " ";
		queue.pop();
	}
	cout << endl;

	return 0;
}
