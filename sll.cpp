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
    int _length;

public:
    list() : head(nullptr), tail(nullptr), _length(0) {}
    void pushBack(int val)
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
        _length++;
    }
    void pushFront(int val)
    {
        node *temp = new node;
        temp->next = nullptr, temp->data = val;
        if (head == nullptr)
        {
            head = temp, tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        _length++;
    }
    bool insert(int val, int pos)
    {
        if (pos >= _length)
        {
            return false;
        }

        if (pos == 0)
        {
            pushFront(val);
            return true;
        }
        else if (pos == _length - 1)
        {
            pushBack(val);
            return true;
        }
        else
        {
            node *curr = head, *temp = new node;
            temp->data = val;
            for (int i = 0; i < pos; i++)
            {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
        _length++;
        return true;
    }

    bool popBack()
    {
        if (_length == 0)
            return false;
        if (_length == 1)
        {
            delete tail;
            head = nullptr, tail = nullptr;
            _length--;
            return true;
        }
        node *curr = head;
        while (curr->next != tail)
        {
            curr = curr->next;
        }
        delete tail;
        tail = curr;
        tail->next = nullptr;
        _length--;
        return true;
    }
    bool popFront()
    {
        if (_length == 0)
            return false;
        if (_length == 1)
        {
            delete tail;
            head = nullptr, tail = nullptr;
            _length--;
            return true;
        }
        else
        {
            node *temp = head->next;
            delete head;
            head = temp;
        }
        _length--;
        return true;
    }
    bool deleteAt(int pos)
    {
        if (pos >= _length)
        {
            return false;
        }
        if (pos == 0)
        {
            popFront();
            return true;
        }
        else if (pos == _length - 1)
        {
            popBack();
            return true;
        }
        else
        {
            node *curr = head;
            for (int i = 0; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            node *temp = curr->next->next;
            delete curr->next;
            curr->next = temp;
        }
        _length--;
        return true;
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

        cout << "List " << this << " content: (size = " << _length << ")" << endl;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    int size() { return _length; }
};

int main()
{
    list list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    list.pushFront(-1);
    list.pushBack(99);
    list.printAll();

    while(list.popBack()); //delete all
    list.printAll();

    return 0;
}