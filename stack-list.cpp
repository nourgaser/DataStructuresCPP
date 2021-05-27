#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
class stack
{
private:
    node *top;
public:
    stack()
    {
        top = nullptr;
    }
    void push(int val)
    {
        node *temp = new node;
        temp->data = val;
        if (top == nullptr)
        {
            top = temp;
            temp->next = nullptr;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
    }
    bool pop()
    {
        if (top != nullptr)
        {
            node *temp = top;
            top = top->next;
            delete temp;
            return true;
        }
        else
        {
            return false;
        }
    }
    void printAll()
    {
        cout << "Stack " << this << " contents: " << endl;
        node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    stack s;
    for (int i = 1; i < 6; i++)
        s.push(i);
    s.printAll();
    while (s.pop()); //pop all.
    s.printAll();
    return 0;
}