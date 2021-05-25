#include <iostream>
using namespace std;

template <typename T>
struct node
{
    T value;
    node<T> *next;
};

template <typename T>
class list
{
private:
    node<T> *head, *tail;
    int length;
public:
    list()
    {
        head = nullptr, tail = nullptr, length = 0;
    }
    void push_back(T value)
    {
        node<T> *temp = new node<T>;
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
        node<T> *temp = new node<T>;
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
                node<T> *pre = head, *cur = head->next;
                node<T> *temp = new node<T>;
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
                node<T> *pre, *cur = head;
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
                node<T> *temp = head->next;
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
                node<T> *pre = head, *cur = head->next;
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

    T front() {
        return head->value;
    }
    T back() {
        return tail->value;
    }
    T at(int pos)
    {
        if (pos < length && pos >= 0)
        {
            node<T> *cur = head;
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
        node<T> *cur = head;
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
};