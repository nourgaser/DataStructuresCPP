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

    //insert into the list
    void pushBack(int val)
    {
        node *temp = new node;
        temp->data = val;
        if (length == 0)
        {
            head = temp, tail = temp;
            temp->next = head;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
        length++;
    }
    void pushFront(int val)
    {
        node *temp = new node;
        temp->data = val;
        if (length == 0)
        {
            head = temp, tail = temp;
            temp->next = head;
        }
        else
        {
            temp->next = head;
            head = temp;
            tail->next = head;
        }
        length++;
    }
    bool insert(int val, int pos)
    {
        if (pos >= length)
        {
            return false;
        }
        else if (pos == 0)
        {
            pushFront(val);
            return true;
        }
        else if (pos == length - 1)
        {
            pushBack(val);
            return true;
        }
        else
        {
            node *temp = new node;
            node *curr = head;
            temp->data = val;
            for (int i = 0; i < pos; i++)
            {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
        length++;
        return true;
    }

    //remove from the list
    bool popBack()
    {
        if (length == 0)
        {
            return false;
        }
        else
        {
            node *curr = head, *prev;
            while (curr->next != head)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = head;
            tail = prev;
            delete curr;
        }
        length--;
        return true;
    }
    bool popFront()
    {
        if (length == 0)
        {
            return false;
        }
        else
        {
            node *temp = head;
            tail->next = head->next;
            head = head->next;
            delete temp;
        }
        length--;
        return true;
    }
    bool remove(int pos)
    {
        if (pos >= length)
        {
            return false;
        }
        else if (pos == 0)
        {
            popFront();
            return true;
        }
        else if (pos == length - 1)
        {
            popBack();
            return true;
        }
        else
        {
            node *curr = head, *prev;
            for (int i = 0; i < pos; i++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }
        length--;
        return true;
    }

    //retreive from the list
    int size() { return length; }
    int front() { return head->data; }
    int back() { return tail->data; }
    int at(int pos)
    {
        if (pos == 0)
        {
            return front();
        }
        else if (pos == length - 1)
        {
            return back();
        }
        else if (pos >= length)
        {
            return INT32_MIN; //invalid position
        }
        else
        {
            node *curr = head;
            for (int i = 0; i < pos; i++)
            {
                curr = curr->next;
            }
            return curr->data;
        }
    }
    void displayElements(int n) //print n number of elements (can cycle through list if n >= length)
    {
        cout << "Content of list " << this << ": (size = " << length << ")" << endl;
        node *curr = head;
        for (int i = 0; i < n; i++)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    list l;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushBack(4);
    l.pushBack(5);
    l.displayElements(l.size());

    l.insert(99, 4);
    l.displayElements(l.size());

    l.remove(4);
    l.displayElements(l.size());

    cout << "Front: " << l.front() << endl;
    cout << "Back: " << l.back() << endl;
    cout << "At 0: " << l.at(0) << endl;
    cout << "At 1: " << l.at(1) << endl;
    cout << "At 2: " << l.at(2) << endl;
    cout << "At 3: " << l.at(3) << endl;
    cout << "At 4: " << l.at(4) << endl;
    cout << "At 5: " << l.at(5) << endl;

    return 0;
}