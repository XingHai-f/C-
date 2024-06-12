#include <iostream>
#include <queue>
#include <stack> // stack
#include <deque> // queue��priority_queue
using namespace std;

/*
��׼����--���������� => ��һ�����ģʽ����������ģʽ
��ô�����������
1.�������ײ�û���Լ������ݽṹ����������һ�������ķ�װ�����ķ���ȫ���ɵײ���������������ʵ�ֵ�
2.û��ʵ���Լ��ĵ�����

template<typename T,typename Container=deque<T>>
class Stack {
public:
	void push(const T& val) { con.push_back(val); }
	void pop() { con.pop_back(); }
	T top()const { return con.back(); }
private:
	Container con;
};

stack��push��ջ  pop��ջ  top�鿴ջ��Ԫ��  empty�ж�ջ��  size����Ԫ�ظ���
queue��push���  pop����  front�鿴��ͷԪ��  back�鿴��βԪ��  empty�ж϶ӿ�  size����Ԫ�ظ���
stack => deque Ϊʲô������vector�أ�
queue => deque Ϊʲô������vector�أ�
1.vector���ڴ�ʹ��Ч��̫���ˣ�û��deque��
2.����queue��Ҫ֧��β�����룬ͷ��ɾ����O(1) ���queue����vector�������Ч�ʺܵ�
3.vector��Ҫ��Ƭ�������ڴ棬��dequeֻ��Ҫ�ֶε��ڴ棬���洢��������ʱ��deque�����ڴ������ʸ���

priority_queue��push���  pop����  top�鿴�Ӷ�Ԫ��  empty�ж϶ӿ�  size����Ԫ�ظ���  Ĭ�ϣ������
priority_queue  => vector Ϊʲô����vector�أ�
�ײ�Ĭ�ϰ��������һ������ѽṹ  ��һ���ڴ������������Ϲ���һ������ѻ���С����
*/

int main() {
	stack<int> s1;
	for (int i = 0; i < 20; ++i) {
		s1.push(rand() % 100 + 1);
	}
	cout << s1.size() << endl;
	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
	
	cout << endl;
	cout << "------------------------------------------" << endl;

	queue<int> que;
	for (int i = 0; i < 20; ++i) {
		que.push(rand() % 100 + 1);
	}
	cout << que.size() << endl;
	while (!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	
	cout << endl;
	cout << "------------------------------------------" << endl;


	priority_queue<int> pque;
	for (int i = 0; i < 20; ++i) {
		pque.push(rand() % 100 + 1);
	}
	cout << pque.size() << endl;
	while (!pque.empty()) {
		cout << pque.top() << " ";
		pque.pop();
	}

	return 0;
}


