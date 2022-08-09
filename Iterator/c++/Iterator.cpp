#include <iostream>

class DataStack
{
    private:
        int items[10];
        int length;

    public:
        friend class StackIterator;
        DataStack() : length(-1) {}
        void push(int value);
        int pop();
};

class StackIterator
{
    private:
        const DataStack& stack;
        int index;
        
    public:
        StackIterator(const DataStack& st) : stack(st), index(0) {}
        void operator++();
        int operator*();
        bool operator()();
};

bool operator==(const DataStack& s1, const DataStack& s2)
{
    StackIterator it1(s1), it2(s2);

    for(; it1(); ++it1, ++it2)
    {
        if (*it1 != *it2) break;
    }
    return !it1() && !it2();
}

int main()
{
    DataStack stack1;
    for (int i = 0; i < 5; i++)
        stack1.push(i);

    DataStack stack2(stack1);

    std::cout << std::boolalpha << (stack1 == stack2) << std::endl;

    stack2.push(10);

    std::cout << std::boolalpha << (stack1 == stack2) << std::endl;
    return 0;
}

void DataStack::push(int value)
{
    items[++length] = value;
}

int DataStack::pop()
{
    return items[length--];
}

void StackIterator::operator++()
{
    index++;
}

int StackIterator::operator*()
{
    return stack.items[index];
}

bool StackIterator::operator()()
{
    return index != stack.length + 1;
}