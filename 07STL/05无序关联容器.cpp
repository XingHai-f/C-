/*
����������� => ��ʽ��ϣ�� ��ɾ��O(1)
set:���� key  map��ӳ��� [key,value]
unordered_set ���ؼ���
unordered_multiset ���ؼ���
unordered_map ����ӳ���
unordered_multimap ����ӳ���
*/


#include <iostream>
// ʹ�������������������ͷ�ļ�
#include <set> // set multiset
#include <map> // map multimap
// ʹ�������������������ͷ�ļ�
#include <unordered_set>
#include <unordered_map>

#include <string>
using namespace std;
/*
����������
1.���������ײ�����ݽṹ  O(1)  O(log2n)
2.������ɾ�鷽��
���ӣ�insert(val)
������iterator�Լ�����������find��Ա����
ɾ����erase(key) erase(it)
*/

int main()
{
	// ���������ݲ��ظ���ȥ�ظ���ʱ��

	/*
	map�д�Ķ���һ��һ����pair����
	[key,value]
	struct pair
	{
		first; => key
		second; => value
	}

	map��operator[]
	1.��ѯ
	2.���key�����ڣ��������һ������[key,string()]
	V& operator[](const K &key)
	{
		insert({key,V()});
	}
	*/
	unordered_map<int, string> map1;
	// ��ѡ�Ĳ��뷽ʽ
	map1.insert(make_pair(1000, "����"));
	map1.insert({ 1010,"����" }); // map������Ԫ��
	map1.insert({ 1020,"����" });
	map1.insert({ 1030,"����" });

	auto it1 = map1.find(1030);
	if (it1 != map1.end())
	{
		// it1 -> pair����
		cout << "key:" << it1->first << " value:" << it1->second << endl;
	}

	/*
	map1.erase(1020); // {1020,"����"}ɾ����
	// map1[2000]; key:2000 vaule:""
	map1[2000] = "��˶"; //�൱��map1.insert({2000,"��˶"})��
	map1[1000] = "����2";
	cout << map1.size() << endl;
	// map operator[](key) => value  ��ѯ
	cout << map1[1000] << endl;
	*/
#if 0
	unordered_set<int> set1; // ����洢keyֵ�ظ���Ԫ��
	// unordered_multiset<int> set1; ���ؼ��������ظ���Ԫ��
	for (int i = 0; i < 50; ++i)
	{
		set1.insert(rand() % 20 + 1); // �ɹ�ϣ��ĺ����������뺯��λ��
		// vector/deque/list(���Ա�Ҫָ��λ�ã���Ҫ������)  insert(it(������),val(ֵ)) 
	}

	// cout << set1.size() << endl;
	// cout << set1.count(15) << endl;

	auto it1 = set1.begin();
	for (; it1 != set1.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	set1.erase(20); // ��keyֵɾ��Ԫ��
	for (it1 = set1.begin(); it1 != set1.end(); )
	{
		if (*it1 == 30)
		{
			it1 = set1.erase(it1); // ����erase��it1��������ʧЧ��
		}
		else
		{
			++it1;
		}
	}
	it1 = set1.find(20);
	if (it1 != set1.end())
	{
		set1.erase(it1);
	}

	for (int v : set1)
	{
		cout << v << " ";
	}
	cout << endl;
#endif

	return 0;
}