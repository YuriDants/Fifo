#include <iostream>
#include <queue>

using namespace std;

class LimitedQueue {
private:
    queue<int> q;
    int maxSize;
public:
    LimitedQueue(int size) {
        maxSize = size;
    }

    void enqueue(int x) {
        if (q.size() == maxSize) {
            q.pop();
        }
        q.push(x);
    }

    int dequeue() {
        int x = q.front();
        q.pop();
        return x;
    }

    bool isEmpty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }
};

int main() {
    LimitedQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); // O elemento 1 é removido para manter o tamanho máximo

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}
