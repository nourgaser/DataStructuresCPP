#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next, *prev;
};

class list
{
private:
    node *head, *tail;
    int length;

public:
    list() : head(nullptr), tail(nullptr), length(0)
    {
    }
    void pushBack(int val)
    {
        node *temp = new node;
        temp->data = val;
        temp->next = nullptr;
        if (head == nullptr)
        {
            head = temp, tail = temp;
            temp->prev = nullptr;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        length++;
    }
    void pushFront(int val)
    {
        node *temp = new node;
        temp->data = val;
        temp->prev = nullptr;
        if (head == nullptr)
        {
            head = temp, tail = temp;
            temp->next = nullptr;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        length++;
    }
    void insert(int pos, int val)
    {
        if (pos == 0)
        {
            pushFront(val);
            return;
        }
        else if (pos == length - 1)
        {
            pushBack(val);
            return;
        }
        else
        {
            node *temp = new node, *curr = head;
            temp->data = val;
            for (int i = 0; i < pos; i++)
            {
                curr = curr->next;
                if (curr == nullptr)
                    return;
            }
            temp->next = curr->next;
            temp->prev = curr;
            curr->next->prev = temp;
            curr->next = temp;
        }
        length++;
    }
    void popBack()
    {
        node *temp = tail->prev;
        delete tail;
        tail = temp;
        tail->next = nullptr;
        length--;
    }
    void popFront()
    {
        node *temp = head->next;
        delete head;
        head = temp;
        head->prev = nullptr;
        length--;
    }
    void deleteAt(int pos)
    {
        if (pos == 0)
        {
            popFront();
            return;
        }
        else if (pos == length - 1) {
            popBack();
            return;
        }
        else
        {
            node *curr = head;
            for (int i = 0; i < pos; i++)
            {
                curr = curr->next;
                if (curr == nullptr)
                    return;
            }
            curr->prev->next = curr->next;
            delete curr;
        }
        length--;
    }
    void printAll()
    {
        cout << "List " << this << " contents: " << "(size = " << length << ")" << endl;
        node *curr = head;
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
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    list.printAll();

    list.popBack();
    list.printAll();

    return 0;
}