// Queue Implementation: 
// Class: Node, Queue
// functions -> isEmpty, enqueue, dequeue, peek
// isEmpty, checks if the front is empty or not to test the list
// enqueue, adds to the queue
// dequeue, removes the front value from the queue
// peek, checks the front of the queue

#include <iostream>
class Node {
    public:
         int value;
         Node* next;

         Node(int data) : value(data), next(nullptr) {}
};
class Queue {
    public:
        Node* front;
        Node* rear;

        Queue() : front(nullptr), rear(nullptr) {}

        bool isEmpty() {
            return front == nullptr;
        }

        //adds value to the rear of the queue
        void enqueue(int value) {
            Node* newNode = new Node(value);
            if (rear == nullptr) {
                // If the queue is empty, set both front and rear to the new node
                front = rear = newNode;
            } else {
                // If the queue is not empty, link the new node at the end of the queue
                rear->next = newNode;
                rear = newNode;
            }
        }

        int dequeue() {
            if (isEmpty()) {
                std::cout << "Queue is empty\n";
                return -1;
            }

            Node* temp = front;
            int result = temp->value;
            front = front->next;

            // If the front becomes nullptr, also set the rear to nullptr (queue is empty)
            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;
            return result;
        }

        int peek() {
            if (isEmpty()) {
                std::cout << "Queue is empty\n";
                return -1;
            }

            return front->value;
        }
        void DisplayQueue() {
            while (front != nullptr) {
                std::cout << front->value << std::endl;
                front = front->next;
            }
        }

        // Destructor to clean up all nodes and prevent memory leaks
        ~Queue() {
            while (!isEmpty()) {
                dequeue();
            }
        }

};
int main() {

    Queue queue;

    queue.enqueue(40);
    queue.enqueue(20);
    queue.enqueue(44);
    queue.enqueue(19);
    queue.enqueue(100);

    queue.DisplayQueue();

    return 0;
}