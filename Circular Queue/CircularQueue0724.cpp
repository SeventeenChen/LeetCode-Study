# include <iostream>
# include <vector>

using namespace std;

class MyCircularQueue {
    private:
        vector<int> data;
        int p_start, p_end, size;

    public:
        /** Initialize your data structure here. Set the size of the queue to be k. */
        MyCircularQueue(int k) {
            data.resize(k);
            p_start = -1;   // 起始时刻头元素索引指向
            p_end = -1;     // 起始时刻尾元素索引指向
            size = k;       // 队列大小

        }

        /** Insert an element into the circular queue. Return true if the operation is successful. */
        bool enQueue(int value) {
            if (isFull())
            {
                return false;
            }
            if (isEmpty())
            {
                p_start = 0;
            }
            p_end = (p_end + 1) % size; // 循环队列，增加元素可以跳转至另一端空位置
            data[p_end] = value;
            return true;
        }

        /** Delete an element from the circular queue. Return true if the operation is successful. */
        bool deQueue() {
            if (isEmpty())
            {
                return false;
            }
            if (p_start == p_end)
            {
                p_start = -1;
                p_end = -1;
                return true;
            }

            p_start = (p_start + 1) % size; 
            return true;
        }

        /** Get the front item from the queue. */
        int Front()
        {
            if (isEmpty())
            {
                return -1;
            }
            return data[p_start];
        }

        /** Get the last item from the queue. */
        int Rear() {
            if (isEmpty())
            {
                return -1;
            }
            return data[p_end];
        }

        /** Checks whether the circular queue is empty or not. */
        bool isEmpty() {
            return p_start == -1;
        }

        /** Checks whether the circular queue is full or not. */
        bool isFull() {
            return ((p_end + 1) % size) == p_start;  // 头索引-尾索引=1 or 尾索引-头索引 = size
        }
        
        /** Get size. */
        int GetSize() {
            return size;
        }
};

int main() {
    // 1. Initialize a queue.
    MyCircularQueue q(4);
    // 2. Push new element.
    q.enQueue(5);
    q.enQueue(13);
    q.enQueue(8);
    q.enQueue(6);
    // 3. Check if queue is empty.
    if (q.isEmpty()) {
        cout << "Queue is empty!" << endl;
        return 0;
    }
    // 4. Pop an element.
    q.deQueue();
    // 5. Get the first element.
    cout << "The first element is: " << q.Front() << endl;
    // 6. Get the last element.
    cout << "The last element is: " << q.Rear() << endl;
    // 7. Get the size of the queue.
    cout << "The size is: " << q.GetSize() << endl;

    return 0;
}




/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
