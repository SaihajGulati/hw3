#include "stack.h"
#include <iostream>

using namespace std;

template<typename T>
void printStack(Stack<T> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

}

int main(int argc, char* argv[])
{
    Stack<int> s;
    printStack(s);

    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl; 
    cout << endl;

    s.push(4);
    printStack(s);
    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl; 

    s.push(10);
    printStack(s);
    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl; 

    s.pop();
    printStack(s);
    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;

    s.pop();
    printStack(s);
    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;
}