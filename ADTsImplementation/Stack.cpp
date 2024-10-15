// Stack implementation
// Class: Node, Stack
// -> isEmpty, Checks if the stack is empty
// -> push, Push operation to add an element to the stack
// -> pop, Pop operation to remove the top of the stack
// -> peek, operation to view the top of the stack without moving it
// -> display, operation to view the stack

#include <iostream>

class Node {
    public:
        int value;
        Node* next;

        // Constructor short hand 
        Node(int value) : value(value), next(nullptr) {}
};
class Stack {
    private:
        // This top pointer tracks the top of the stack
        Node* top;
    
    public:
        // Constructor to initilize the stack as empty (top is nullptr)
        Stack() : top(nullptr) {}

        // Checks if the stack is empty
        bool isEmpty() {
            return top == nullptr;
        }

        // Adds element to the top of the stack
        void push(int value) {
            // Creates a new node with the value
            Node* newNode = new Node(value);

            // Point the newNode to reference the current top node, so basically the newNode is on top of the previous Node(top)
            newNode->next = top;

            // Update the top stack to be the newNode
            top = newNode;

            std::cout << "Pushed " << value << " onto the stack." << std::endl;
        }

        // Operation to remove the top of the stack
        void pop() {
            if (isEmpty()) {
                std::cout << "Stack is empty, nothing to pop." << std::endl;
                return;
            }

            // Temporarlily stores the top node
            Node* temp = top;

            // Move the top pointer to the next Node
            top = top->next;

            // Delete the old top node
            std::cout << "Removed " << temp->value << " from the stack." << std::endl;
            delete temp;

        }

        void peek() {
            if (isEmpty()) {
                std::cout << "Stack is empty" << std::endl;
                return;
            }
            std::cout << top->value << std::endl;
        }

        void display() {
            if (isEmpty()) {
                std::cout << "Stack is empty" << std::endl;
                return;
            }

            Node* temp = top;

            while (temp != nullptr) {
                std::cout << temp->value << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }

};
int main() {

    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.peek();
    stack.pop();
    stack.peek();
    stack.display();

    return 0;
}