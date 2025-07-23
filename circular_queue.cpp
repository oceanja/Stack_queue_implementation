class MyCircularQueue {
public:
    vector<int> cq;
    int K;
    int front_idx;
    int rear_idx;
    int currCnt;

    MyCircularQueue(int k) {
        K = k;
        cq = vector<int>(K);
        front_idx = 0;
        rear_idx = 0;
        currCnt = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        cq[rear_idx] = value;
        rear_idx = (rear_idx + 1) % K;
        currCnt++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front_idx = (front_idx + 1) % K;
        currCnt--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return cq[front_idx];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return cq[(rear_idx - 1 + K) % K]; 
    }

    bool isEmpty() {
        return currCnt == 0;
    }

    bool isFull() {
        return currCnt == K;
    }
};

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
