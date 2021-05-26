#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class list
{
private:
    node *head, *tail;

public:
    list()
    {
        head = nullptr, tail = nullptr;
    }
    void createNode(int val)
    {
        node *temp = new node;
        temp->next = nullptr, temp->data = val;
        if (head == nullptr)
        {
            head = temp, tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void reverse()
    {
        node *curr = head, *prev = nullptr, *temp;
        while (curr != nullptr)
        {
            temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }
        head = prev;
    }
    void printAll()
    {
        node *curr = head;

        cout << "List " << this << " content:" << endl;
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
    list list;
    list.createNode(1);
    list.createNode(2);
    list.createNode(3);
    list.createNode(4);
    list.createNode(5);

    list.printAll();
    list.reverse();
    list.printAll();
    list.reverse();
    list.printAll();
    return 0;
}

/*
Singly linked list:
createNode: insert at the end;
revese: revese the list;
printAll(): display list content and address
TODO: delete, insert start, insert at position
*/