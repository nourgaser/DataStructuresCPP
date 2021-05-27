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
    int length;

public:
    list()
    {
        head = nullptr, tail = nullptr, length = 0;
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
        length++;
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
        length++;
    }
    void insert(int pos, T value)
    {
        if (length > 0 && pos < length && pos >= 0)
        {
            if (pos == 0)
            {
                push_front(value);
                return;
            }
            else if (pos == length - 1)
            {
                push_back(value);
                return;
            }
            if (length >= 3)
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
            else if (length == 1)
            {
                push_front(value);
            }
            else if (length == 2)
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
            length++;
        }
    }
    void pop_back()
    {
        if (length > 0)
        {
            if (length == 1)
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
            length--;
        }
    }
    void pop_front()
    {
        if (length > 0)
        {
            if (length == 1)
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
            length--;
        }
    }
    void remove(int pos)
    {
        if (length > 0 && pos < length && pos >= 0)
        {
            if (pos == 0)
            {
                pop_front();
                return;
            }
            else if (pos == length - 1)
            {
                pop_back();
                return;
            }

            if (length >= 3)
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
            else if (length == 1)
            {
                delete head;
                head = nullptr, tail = nullptr;
            }
            else if (length == 2)
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
            length--;
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
        if (pos < length && pos >= 0)
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
    void displayAll()
    {
        cout << "===========================================" << endl;
        node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->value << "\t";
            cur = cur->next;
        }
        cout << "\nLength: " << length << ", Head: " << head->value << ", Tail: " << tail->value;
        cout << endl
             << "===========================================\n"
             << endl;
    }

    //check TODO
    class iterator
    {
    };
};

int main()
{
    list<string> list;
    list.push_back("Nour");
    list.push_back("Ali");
    list.push_back("Ahmed");
    list.push_back("Mohammed");
    list.push_back("Roo");

    list.displayAll();
    return 0;
}

//TODO: add list subclass iterator with operator-overloading for +,-,++,--, and class methods