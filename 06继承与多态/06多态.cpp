/*
�������̬
��̬������ʱ�ڣ��Ķ�̬���������ء�ģ�壨����ģ�����ģ�壩
bool compare(int,int){}
bool compare(double,double){}

compare(10,20); call compare_int_int �ڱ���׶ξ�ȷ���õ��ú����İ汾
compare(10.5,20.5); call compare_double_double �ڱ���׶ξ�ȷ���õ��ú����İ汾

template<typename T>
bool compare(T a,T b){}

compare(10,20); => int ʵ����һ�� compare<int>
compare(10.5,20.5); => double ʵ����һ�� compare<double>

��̬������ʱ�ڣ��Ķ�̬��  Base Derive
�ڼ̳нṹ�У�����ָ�루���ã�ָ�����������ͨ����ָ�루���ã�����ͬ�����Ƿ������麯������
����ָ��ָ���ĸ���������󣬾ͻ�����ĸ�����������ͬ�����Ƿ�������Ϊ��̬
pbase->bark();
��̬�ײ���ͨ����̬����ʵ�ֵģ�pbase-> ����˭�� vfptr-> ��������˭��vftable
                                     ->���õľ��Ƕ�Ӧ�����������ķ���

�̳еĺô���ʲô��
1.����������ĸ���
2.�ڻ������ṩͳһ���麯���ӿڣ�����������д��Ȼ��Ϳ���ʹ�ö�̬��
*/

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    Animal(string name):_name(name){}
    virtual void bark(){}
protected:
    string _name;
};

class Cat :public Animal {
public:
    Cat(string name):Animal(name){}
    void bark() { cout <<_name << "bark:miao miao!" << endl; }
};

class Dog :public Animal {
public:
    Dog(string name):Animal(name){}
    void bark() { cout <<_name << "bark:wang wang!" << endl; }
};

class Pig :public Animal {
public:
    Pig(string name) :Animal(name) {}
    void bark() { cout << _name << "bark:heng heng!" << endl; }
};

/*
�����һ��bark API�ӿ��޷���������漰��"��-��"ԭ��
������������ԭ��  ����-�ա�ԭ��   ���޸Ĺرգ�����չ����

void bark(Cat& cat) {
    cat.bark();
}

void bark(Dog& dog) {
    dog.bark();
}

void bark(Pig& pig) {
    pig.bark();
}
*/

void bark(Animal* p) {
    p->bark(); // Animal::bark�麯������̬����
    /*
    p->cat Cat vftable  &Cat::bark()
    p->dog Dog vftable  &Dog::bark()
    p->pig Pig vftable  &Pig::bark()
    */
}

int main() {
    Cat cat("è��");
    Dog dog("����");
    Pig pig("����");

    bark(&cat);
    bark(&dog);
    bark(&pig);

    return 0;
}