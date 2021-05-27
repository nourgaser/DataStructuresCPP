#include <iostream>
using namespace std;

class list
{
private:
    struct node
    {
        int data;
        node *next, *prev;
    };
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
    bool insert(int pos, int val)
    {
        if (pos == 0)
        {
            pushFront(val);
            return true;
        }
        else if (pos == length - 1)
        {
            pushBack(val);
            return true;
        }
        else if (pos >= length)
        {
            return false;
        }
        else
        {
            node *temp = new node, *curr = head;
            temp->data = val;
            for (int i = 0; i < pos; i++)
            {
                curr = curr->next;
            }
            temp->next = curr->next;
            temp->prev = curr;
            curr->next->prev = temp;
            curr->next = temp;
        }
        length++;
        return true;
    }
    bool popBack()
    {
        if (length == 0)
            return false;
        if (length == 1)
        {
            delete tail;
            head = nullptr, tail = nullptr;
        }
        else
        {
            node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        length--;
        return true;
    }
    bool popFront()
    {
        if (length == 0)
            return false;
        if (length == 1)
        {
            delete tail;
            head = nullptr, tail = nullptr;
        }
        else
        {
            node *temp = head->next;
            delete head;
            head = temp;
            head->prev = nullptr;
        }
        length--;
        return true;
    }
    bool deleteAt(int pos)
    {
        if (length == 0)
            return false;
        if (pos >= length)
            return false;

        if (pos == 0)
        {
            popFront();
            return true;
        }
        else if (pos == length - 1)
        {
            popBack();
            return true;
        }
        else if (length == 1)
        {
            delete tail;
            head = nullptr, tail = nullptr;
        }
        else
        {
            node *curr = head;
            for (int i = 0; i < pos; i++)
            {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            delete curr;
        }
        length--;
        return true;
    }
    void printAll()
    {
        cout << "List " << this << " contents: "
             << "(size = " << length << ")" << endl;
        node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    int size() { return length; }
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

    while (list.popBack())
        ;
    list.printAll();

    return 0;
}