#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template<typename T>
Stack<T>::Stack(){} //automatically calls constructor for base class

template<typename T>
bool Stack<T>::empty() const 
{
    //call std::vector's empty checker
    return std::vector<T>::empty();
}

template<typename T>
size_t Stack<T>::size() const 
{
    //call std::vector's size getter
    return std::vector<T>::size();
}

template<typename T>
void Stack<T>::push(const T& item)
{
    //check if can add to std::vector, otherwise throw error
    if (std::vector<T>::size() == std::vector<T>::max_size())
    {
        throw std::overflow_error("Overflow Error");
    }

    //call std::vector's push_back
    std::vector<T>::push_back(item);
}

template<typename T>
void Stack<T>::pop()// throws std::underflow_error if empty
{
    //check if empty and throw error if so
    if (std::vector<T>::empty())
    {
        throw std::underflow_error("Underflow Error");
    }

    //call std::vector's pop_back which is O(1)
    std::vector<T>::pop_back();
}

template<typename T>
const T& Stack<T>::top() const // throws std::underflow_error if empty
{
    //check if empty and throw error if so
    if (std::vector<T>::empty())
    {
        throw std::underflow_error("Underflow Error");
    }

    //get top, or last inserted value so back since stack is LIFO
    return std::vector<T>::back();
}

template<typename T>
Stack<T>::~Stack(){}

#endif