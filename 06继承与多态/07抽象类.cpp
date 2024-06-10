/*
���������ͨ����ʲô����
һ���ʲô����Ƴɳ����ࣿ ����
*/

#include <iostream>
#include <string>
using namespace std;

// �������   ��ָ   ��->����һ��ʵ�������
/*
����Animal�ĳ��ԣ���������Animal����ĳ��ʵ�������
1.string _name; �����еĶ���ʵ����ͨ���̳�Animalֱ�Ӹ��ø�����
2.�����е������ౣ��ͳһ�ĸ���/��д�ӿ�

ӵ�д��麯�����࣬���������࣡��Animal��
Animal A�� NO!
�����಻����ʵ���������ˣ����ǿ��Զ���ָ������ñ���
*/
class Animal {
public:
    Animal(string name) :_name(name) {}
    // ���麯��
    virtual void bark() = 0;
protected:
    string _name;
};

// ����ʵ����
class Cat :public Animal {
public:
    Cat(string name) :Animal(name) {}
    void bark() { cout << _name << "bark:miao miao!" << endl; }
};

class Dog :public Animal {
public:
    Dog(string name) :Animal(name) {}
    void bark() { cout << _name << "bark:wang wang!" << endl; }
};

class Pig :public Animal {
public:
    Pig(string name) :Animal(name) {}
    void bark() { cout << _name << "bark:heng heng!" << endl; }
};

void bark(Animal* p) {
    p->bark(); // Animal::bark�麯������̬����
    /*
    p->cat Cat vftable  &Cat::bark()
    p->dog Dog vftable  &Dog::bark()
    p->pig Pig vftable  &Pig::bark()
    */
}

//�����Ļ���
class Car {

};


int main() {
    Cat cat("è��");
    Dog dog("����");
    Pig pig("����");

    bark(&cat);
    bark(&dog);
    bark(&pig);

    return 0;
}