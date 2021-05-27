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
    list()
    {
        head = nullptr, tail = nullptr, length = 0;
    }
    void createNode(int val)
    {
        node *temp = new node;
        temp->next = nullptr, temp->data = val;
        if (head == nullptr)
        {
            head = temp, tail = temp;
        }
        else if (head == tail)
        {
            if (val > head->data)
            {
                head->next = temp;
                tail = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
            }
        }
        else if (val < head->data)
        {
            temp->next = head;
            head = temp;
        }
        else if (val > tail->data)
        {
            tail->next = temp;
            tail = temp;
        }
        else
        {
            node *curr = head;
            while (val > curr->next->data)
            {
                curr = curr->next;
                if (curr == tail)
                {
                    tail->next = temp;
                    tail = temp;
                    length++;
                    return;
                }
            }
            temp->next = curr->next;
            curr->next = temp;
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
    list list;
    list.createNode(3);
    list.createNode(1);
    list.createNode(-5);
    list.createNode(10);
    list.createNode(15);
    list.createNode(12);
    list.createNode(-10);
    list.createNode(0);
    list.createNode(1000);
    list.printAll();
    return 0;
}