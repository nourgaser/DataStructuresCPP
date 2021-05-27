#include <iostream>
using namespace std;

class list
{
private:
    struct node
    {
        int data;
        node *next;
    };
    node *head, *tail;
    int length;

public:
    list() : head(nullptr), tail(nullptr), length(0) {}
    void pushBack(int val)
    {
        node *newNode = new node;
        newNode->next = nullptr, newNode->data = val;
        if (head == nullptr)
        {
            head = newNode, tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    void printAll()
    {
        node *curr = head;

        cout << "List " << this << " content: (size = " << length << ")" << endl;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    list list1;

    return 0;
}