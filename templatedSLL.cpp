#include <iostream>
using namespace std;

template <typename T>
class list
{
private:
    struct node
    {
        T value;
        node *next;
    };
    node *head, *tail;
    int _length;

public:
    list()
    {
        head = nullptr, tail = nullptr, _length = 0;
    }
    void push_back(T value)
    {
        node *temp = new node;
        temp->value = value;
        temp->next = nullptr;
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        _length++;
    }
    void push_front(T value)
    {
        node *temp = new node;
        temp->value = value;
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            temp->next = nullptr;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        _length++;
    }
    void insert(int pos, T value)
    {
        if (_length > 0 && pos < _length && pos >= 0)
        {
            if (pos == 0)
            {
                push_front(value);
                return;
            }
            else if (pos == _length - 1)
            {
                push_back(value);
                return;
            }
            if (_length >= 3)
            {
                node *pre = head, *cur = head->next;
                node *temp = new node;
                temp->value = value;
                for (int i = 1; i < pos; i++)
                {
                    pre = cur;
                    cur = cur->next;
                }
                pre->next = temp;
                temp->next = cur;
            }
            else if (_length == 1)
            {
                push_front(value);
            }
            else if (_length == 2)
            {
                if (pos == 0)
                {
                    push_front(value);
                }
                else if (pos == 1)
                {
                    push_back(value);
                }
            }
            _length++;
        }
    }
    void pop_back()
    {
        if (_length > 0)
        {
            if (_length == 1)
            {
                delete head;
                head = nullptr, tail = nullptr;
            }
            else
            {
                node *pre, *cur = head;
                while (cur != tail)
                {
                    pre = cur;
                    cur = cur->next;
                }
                tail = pre;
                pre->next = nullptr;
                delete cur;
            }
            _length--;
        }
    }
    void pop_front()
    {
        if (_length > 0)
        {
            if (_length == 1)
            {
                delete head;
                head = nullptr, tail = nullptr;
            }
            else
            {
                node *temp = head->next;
                delete head;
                head = temp;
            }
            _length--;
        }
    }
    void remove(int pos)
    {
        if (_length > 0 && pos < _length && pos >= 0)
        {
            if (pos == 0)
            {
                pop_front();
                return;
            }
            else if (pos == _length - 1)
            {
                pop_back();
                return;
            }

            if (_length >= 3)
            {
                node *pre = head, *cur = head->next;
                for (int i = 1; i < pos; i++)
                {
                    pre = cur;
                    cur = cur->next;
                }
                pre->next = cur->next;
                delete cur;
            }
            else if (_length == 1)
            {
                delete head;
                head = nullptr, tail = nullptr;
            }
            else if (_length == 2)
            {
                if (pos == 0)
                {
                    pop_front();
                }
                else if (pos == 1)
                {
                    pop_back();
                }
            }
            _length--;
        }
    }

    T front()
    {
        return head->value;
    }
    T back()
    {
        return tail->value;
    }
    T at(int pos)
    {
        if (pos < _length && pos >= 0)
        {
            node *cur = head;
            for (int i = 1; i <= pos; i++)
            {
                cur = cur->next;
            }
            return cur->value;
        }
        return INT32_MIN;
    }
    int size() { return _length; }
    void displayAll()
    {
        cout << "===========================================" << endl;
        node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->value << "\t";
            cur = cur->next;
        }
        cout << "\nLength: " << _length << ", Head: " << head->value << ", Tail: " << tail->value;
        cout << endl
             << "===========================================\n"
             << endl;
    }
    //check TODO
    class iterator
    {
    public:
        list::iterator operator+(const list::iterator &itr2) {} //TODO for +, -, ++, --, 
    };
};

int main()
{
    list<string> list1;
    list1.push_back("Nour");
    list1.push_back("Ali");
    list1.push_back("Ahmed");
    list1.push_back("Mohammed");
    list1.push_back("Roo");

    list1.displayAll();

    list<int> list2;
    list2.push_back(101);
    list2.push_back(102);
    list2.push_back(103);
    list2.push_back(104);
    list2.push_back(105);

    list2.displayAll();
    return 0;
}

//TODO: add list subclass iterator with operator-overloading for +,-,++,--, and class methods