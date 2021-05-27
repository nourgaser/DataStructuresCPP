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
    node *front, *back; //first in->[front][]...[][back]<-last in 
    int length;
public:
    queue() : front(nullptr), back(nullptr), length(0) {}
    void enqueue(int val)
    {
        node *temp = new node;
        temp->data = val;
        if (length == 0)
        {
            front = temp;
            back = temp;
            temp->next = nullptr;
        }
        else
        {
            back->next = temp;
            back = temp;
        }
        length++;
    }
    bool dequeue()
    {
        if (length == 0)
        {
            return false;
        }
        if (length == 1) {
            delete back;
            back = nullptr, front = nullptr;
        }
        else {
            node *temp = front->next;
            delete front;
            front = temp;
        }
        length--;
        return true;
    }
    void printAll()
    {
        cout << "Contents of queue " << this << ": (size = " << length << ")" << endl;
        node *curr = front;
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