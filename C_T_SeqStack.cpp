#include <iostream>
#include <cstdlib>
using namespace std;

//类模板
template <typename T>
class SeqStack //模板名称 + 类型参数列表 = 类名称 
{
public:
    //构造和析构函数不用类型参数列表(<T>),其它需要
    SeqStack(int size = 10)
        :_pstack(new T[size])
        , _top(0)
        , _size(size)
    {}
    ~SeqStack()
    {
        delete[] _pstack;
        _pstack = nullptr;  // 错误: nullptr 拼写错误
    }
    SeqStack(const SeqStack<T>& stack)
        :_top(stack._top)
        , _size(stack._size)
    {
        _pstack = new T[_size];
        //不要用memcpy进行拷贝
        for (int i = 0; i < _top; ++i)
        {
            _pstack[i] = stack._pstack[i];
        }
    }
    SeqStack<T>& operator=(const SeqStack<T>& stack)
    {
        if (this == &stack)
            return *this;
        delete[] _pstack;
        _top = stack._top;  // 错误: _top 被写成 _stack
        _size = stack._size;
        _pstack = new T[_size];
        for (int i = 0; i < _top; ++i)
        {
            _pstack[i] = stack._pstack[i];
        }
        return *this;
    }

    void push(const T& val) // 入栈操作
    {
        if (full())
            expand();
        _pstack[_top++] = val;
    }

    void pop() // 出栈操作
    {
        if (empty())
            return;
        --_top;
    }

    T top()const // 返回栈顶元素
    {
        if (empty())
            throw "stack is empty."; //抛异常也代表函数逻辑结束
        return _pstack[_top - 1];
    }
    bool full()const { return _top == _size; } // 栈满
    bool empty()const { return _top == 0; } // 栈空
private:
    T* _pstack;
    int _top;
    int _size;

    //顺序栈底层数组按2倍的方式扩容
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

