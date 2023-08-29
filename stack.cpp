#include <iostream>
using namespace std;
//making a class for our satck
const int MAX_SIZE = 100;
template <class t>
class stack
{//array-based implementation of the ADT stack
private:
    int top;
    t item[MAX_SIZE];
public:

    stack(){top = -1;};//intializing stack top 

    void push(t element)//function to push elements into the stack
    {
        if (top >= MAX_SIZE-1)//making sure our stack isn't full.
        {
            cout << "Stack Overflow";
        }
        else
        {
            top++;
            item[top]=element;
        }
    }
    bool Empty()//function to see that the stack is empty or not
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void pop()//popping without keeping a copy of the popped element
    {
        if (Empty())
        {
            cout<<"stack already empty\n";
        }
        else
        {
            top--;
        }
    }
    void pop(t&element)//popping and keeping a copy of the popped element
    {
        if (Empty())
        {
            cout<<"stack already empty\n";
        }
        else
        {
            element = item[top];
            top--;
        }
    }
    t Top()//function to get the element in top of the stack
    {
        if (Empty())
        {
            cout<<"stack already empty\n";
        }
        else
        {
            t stacktop = item[top];
            return stacktop;
        }
    }
    void print()//function to print our stack using the LIFO principle
    {
        cout<<"[";
        for (int i = top; i >= 0; i--)//LIFO
        {
            cout<<item[i]<<" ";
        }
        cout<<"]\n";
    }
    void clear()
    {
        while (!this->Empty())
        {
            this->pop();
        }
    }
    ~stack(){};
};

template <typename T>
//function to reverse the items in our stack using recursion only.
void reverseStack(stack<T>& stack) {
    if (stack.Empty())
        return;

    T temp = stack.Top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, temp);
}

template <typename T>
//function to insert items at the bottom of our stack
void insertAtBottom(stack<T>& stack, const T& value) {
    if (stack.Empty()) {
        stack.push(value);
        return;
    }

    T temp = stack.Top();
    stack.pop();
    insertAtBottom(stack, value);
    stack.push(temp);
}

template <typename T>
//function to delete the element in the middle of our stack
void deleteMiddle(stack<T>& stack, int current = 0) {
    if (stack.Empty()|| (stack.Top() - current) == (stack.Top() / 2)) {
        stack.pop();
        return;
    }

    T temp = stack.Top();
    stack.pop();
    deleteMiddle(stack, current + 1);
    stack.push(temp);
}

int main() {
    stack<int> s;//intializing our stack of integers
    //pushing items to our stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    //printing our stack following the LIFO rule
    cout << "Original Stack: ";
    s.print();
    //emptying our stack
    s.clear();
    //pushing items to our stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    //reversing our stack
    reverseStack(s);
    //printing our stack following the LIFO rule
    cout << "Reversed Stack: ";
    s.print();
    //emptying our stack
    s.clear();
    //pushing items to our stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<"stack before deleting middle element: ";
    s.print();
    //printing our stack after deleting the middle element
    deleteMiddle(s);
    cout << "Stack after deleting middle element: ";
    s.print();
    return 0;
}