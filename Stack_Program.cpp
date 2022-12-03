#include <iostream>

class Stack
{
public: 
    int size = 2;     // initial size the stack
    int count = 0;
    int* stack = new int[size];    // dinamic allocation memory for 
    int NewSize = size + 10;    // stack size when we want more size to push the elements
    int* DinamicStack = new int[NewSize];

    //function to determine stack is empty or not
    bool isEmpty();
    
    //function to pop elements to stack
    void Push(int value);
   
    //function to pop elements from stack
    void Pop();
   
    //function to print the elements of stack
    void Print();
    
    //function to delete the stack
    void Delete();
 
    ~Stack();
   
}; 
//function to determine stack is empty or not
bool Stack::isEmpty()
{
    return count == 0;
}
//function to pop elements to stack
void Stack::Push(int value)
{
    if (count >= size)
    {
        DinamicStack[count] = stack[count];
        DinamicStack[count] = value;    
    }
    else
    {
        this->stack[count] = value;
        DinamicStack[count] = value;
    }
    count++;
   
}
//function to pop elements from stack
void Stack::Pop()
{
    count--;
    std::cout << DinamicStack[count] << " ";
}
//function to print the elements of stack
void Stack::Print()
{
    for (int i = 0; i < count; i++)
    {
        std::cout << DinamicStack[i] << " ";
    }
}
//function to delete the stack
void Stack::Delete()
{
    delete[] stack;
    delete[] DinamicStack;
}
//dectructor call
Stack::~Stack()
{
    Delete();
}


int main()
{
    Stack s;
    if (s.isEmpty())
    {
        std::cout << "Stack is empty and you can push the elements" << std::endl;
    }
    else
    {
        std::cout << "Stack is full" << std::endl;
    }
    std::cout << "   " << std::endl;

    s.Push(5);
    s.Push(10);
    s.Push(7);
    s.Push(9);
    
    s.Print();

    std::cout << "   " << std::endl;

    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    
    return 0;
}

