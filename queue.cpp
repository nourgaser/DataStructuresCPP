#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class queue
{
private:
    node *front, *back; //last in->[back][]...[][front]<-first in 

public:
    int length;
    queue() : front(nullptr), back(nullptr), length(0) {}
    void enqueue(int val)
    {
        node *temp = new node;
        temp->data = val;
        if (back == nullptr)
        {
            front = temp;
            back = temp;
            temp->next = nullptr;
        }
        else
        {
            temp->next = back;
            back = temp;
        }
        length++;
    }
    bool dequeue()
    {
        if (length == 0)
        {
            return 0;
        }
        if (length == 1) {
            delete back;
            back = nullptr, front = nullptr;
        }
        else {
            node *curr = back;
            while (curr->next != front) {
                curr = curr->next;
            }
            delete front;
            curr->next = nullptr;
            front = curr;
        }
        length--;
        return true;
    }
    void printAll()
    {
        cout << "Contents of queue " << this << ": (size = " << length << ")" << endl;
        node *curr = back;
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
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.printAll();

    q.dequeue();
    q.printAll();

    while(q.dequeue()); //dequeue all
    q.printAll();

    return 0;
}