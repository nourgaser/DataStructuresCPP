#include <iostream>
using namespace std;

class queue
{
private:
    //capacity = max number of elements, size = number of current occupied elements
    int rear, front, _size, *arr, _capacity;

public:
    queue(int capacity) : rear(-1), front(-1), _size(0), arr(new int[capacity]), _capacity(capacity) {}
    bool enqueue(int n)
    {
        if (_size == _capacity)
        {
            return false;
        }
        else if (_size == 0)
        {
            arr[0] = n;
            rear = 0, front = 0;
        }
        else
        {
            rear++;
            arr[rear] = n;
        }
        _size++;
        return true;
    }
    bool dequeue()
    {
        if (_size == 0)
        {
            return false;
        }
        else if (_size == 1)
        {
            rear = -2, front = -1;
        }
        else
        {
            front++;
        }
        _size--;
        return true;
    }
    void displayAll()
    {
        cout << "Contents of queue " << this << ": (size = " << _size << ")" << endl;
        int curr = front;
        while (curr <= rear)
        {
            cout << arr[curr] << " ";
            curr++;
        }
        cout << endl;
    }
    int size() { return this->_size; }
    int capacity() { return this->_capacity; }
};

int main()
{
    queue q(5);
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // q.enqueue(4);
    // q.enqueue(5);
    // q.displayAll();

    // q.dequeue();
    // q.displayAll();

    // while(q.dequeue()){} //dequeue all.
    // q.displayAll();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.displayAll();

    q.dequeue();
    q.dequeue();
    q.displayAll();
    q.dequeue();
    //q.dequeue();
    q.displayAll();
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);
    q.displayAll();

    while (q.dequeue());
    q.displayAll();

    cout << "Capacity: " << q.capacity() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}