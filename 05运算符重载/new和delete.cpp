/*
new��delete
1.malloc��new������
a.malloc���ֽڿ����ڴ�ģ�new�����ڴ�ʱ��Ҫָ������ new int[10]
	����malloc�����ڴ淵�صĶ���void*    operator new -> int*
b.mallocֻ���𿪱ٿռ䣬new��������malloc�Ĺ��ܣ����Խ������ݵĳ�ʼ��
	new int(20);     new int[20]();      int()
c.malloc�����ڴ�ʧ�ܷ���nullptrָ�룻new�׳�����bad_alloc���͵��쳣

2.free��delete������
delete (int*) p:����������������free(p)


new��delete�ܻ�����C++Ϊʲô���ֵ���Ԫ�غ�������ڴ������ͷ��أ�
new delete
new[] delete[]
������ͨ�ı������������� new/delete[]   new[]/delete

�Զ���������ͣ�������������Ϊ�˵�����ȷ��������������ô���ٶ��������ʱ��
��࿪��4���ֽڣ���¼����ĸ���
*/

// �ȵ���operator new�����ڴ�ռ䣬Ȼ����ö���Ĺ��캯������ʼ����
void* operator new(size_t size)
{
	void* p = malloc(size);
	if (p == nullptr)
		throw bad_alloc();
	return p;
}

// delete p; ����pָ�����������������ٵ���operator deleteʩ���ڴ�ռ�
void operator delete(void* ptr)
{
	free(ptr);
}