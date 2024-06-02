#include <iostream>
using namespace std;

class String {
public:
	// ���캯��
	String(const char* p = nullptr) {
		if (p != nullptr) {
			_pstr = new char[strlen(p) + 1];
			strcpy(_pstr, p);
		}
		else {
			_pstr = new char[1];
			*_pstr = '\0';
		}
	}
	// ��������
	~String() {
		delete[]_pstr;
		_pstr = nullptr;
	}
	// �������캯��
	String(const String& str) {
		_pstr = new char[strlen(str._pstr) + 1];
		strcpy(_pstr, str._pstr);
	}
	// ��ֵ���������
	String& operator=(const String& str) {
		if (this == &str)
			return *this;
		delete[]_pstr;

		_pstr = new char[strlen(str._pstr) + 1];
		strcpy(_pstr, str._pstr);
		return *this;
	}
	// �������������
	bool operator>(const String& str)const {
		return strcmp(_pstr, str._pstr) > 0;
	}
	// С�����������
	bool operator<(const String& str)const {
		return strcmp(_pstr, str._pstr) < 0;
	}
	// �������������
	bool operator==(const String& str)const {
		return strcmp(_pstr, str._pstr) == 0;
	}
	// �����ַ�������
	int lengh()const { return strlen(_pstr); }
	// ����C�ַ���
	const char* c_str()const { return _pstr; }

	// �±����������
	//char ch = str6[6]; str6[6] = '7'
	char& operator[](int index) { return _pstr[index]; }
	//char ch = str6[6]; �������޸ģ�str6[6] = '7'
	const char& operator[](int index)const { return _pstr[index]; }
private:
	char* _pstr;

	friend String operator+(const String& lhs, const String& rhs);
	friend ostream& operator<<(ostream& out, const String& str);
};
// �ӷ����������
String operator+(const String& lhs, const String& rhs) {
	char* ptmp = new char[strlen(lhs._pstr) + strlen(rhs._pstr) + 1];
	strcpy(ptmp, lhs._pstr);
	strcat(ptmp, rhs._pstr);
	String result(ptmp);
	delete[] ptmp; // �ͷ���ʱ������ڴ�
	return String(ptmp);
}
// ��������������
ostream& operator<<(ostream& out, const String& str) {
	out << str._pstr;
	return out;
}