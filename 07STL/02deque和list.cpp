/*
deque��˫�˶�������
�ײ����ݽṹ����̬���ٵĶ�ά���飬һά�����2��ʼ����2���ķ�ʽ�������ݣ�
ÿ�����ݺ�ԭ���ڶ�ά�����飬���µĵ�һά������±�oldsize/2��ʼ��ţ�
���¶�Ԥ����ͬ�Ŀ��У�����֧��deque����βԪ�����

deque<int> deq;
���ӣ� 
deq.push_back(20); ��β�����Ԫ�� O(1)
deq.push_front(20); ���ײ����Ԫ�� O(1)   // vec.insert(vec.begin(),20)  O(n)
deq.insert(it,20); itָ���λ�����Ԫ�� O(n)

ɾ����
deq.pop_back(); ��β��ɾ��Ԫ�� O(1)
deq.pop_front(); ���ײ�ɾ��Ԫ�� O(1)
deq.erase(it); ��itָ���λ��ɾ��Ԫ�� O(n)

��ѯ���أ�
iterator(������insert��eraseһ��Ҫ���ǵ�����ʧЧ������)

list����������
�ײ����ݽṹ��˫���ѭ���б�   pre  data  next
list<int> mylist;
���ӣ�
mylist.push_back(20); ��β�����Ԫ�� O(1)
mylist.push_front(20); ���ײ����Ԫ�� O(1)   // vec.insert(vec.begin(),20)  O(n)
mylist.insert(it,20); itָ���λ�����Ԫ�� O(1)
//�����н���insert��ʱ����Ҫ����һ��query��ѯ����������������˵��ѯ��������

ɾ����
mylist.pop_back(); ��β��ɾ��Ԫ�� O(1)
mylist.pop_front(); ���ײ�ɾ��Ԫ�� O(1)
mylist.erase(it); ��itָ���λ��ɾ��Ԫ�� O(1)

��ѯ���أ�
iterator(������insert��eraseһ��Ҫ���ǵ�����ʧЧ������)

deque��list����vector���������������ɾ�������ӿڣ�
push_front��pop_front
*/
