#include <iostream>

class Node {
    public:
        int data;
        Node* next;
};
void printLinkedList(Node* n) {
    // Check if n because if it hits the last not it won't run the function because it == nullptr
    while (n != nullptr) {
        std::cout << n->data << std::endl;
        n = n->next;
    }
}
void AddToEnd(Node* n, int value) {
    //traverse to the last node using the next value
    while (n->next != nullptr) {
        n = n->next;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    n->next = newNode;
}
void AddToFront(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    //The head needs to be updated outside of the function so you need to ampersand it & and set it equal to the newNode
    head = newNode;
}
void AddAfterNode(Node* n, int addAfterValue, int value) {
    // Need to make sure its not the last value and the data is the correct one
    while (n != nullptr && n->data != addAfterValue) {
        n = n->next;
    }

    if (n != nullptr) {
        Node* newNode = new Node();
        newNode->data = value;

        // Point the newNode to the previous node n pointer
        newNode->next = n->next;

        // Then point the current node pointer to the newNode
        n->next = newNode;
    } else {
        std::cout << "Cannot find: " << addAfterValue << " In the list." << std::endl;
    }
    
}
void DeleteNodeValue(Node*& head, int value) {

    // Making sure the List isn't empty first
    if (head == nullptr) { std::cout << "list is empty.\n"; return;} // just short hand if statement, Not really needed but cool

    // Case 1 is the head node is the value to be deleted
    Node* temp = head;     // temp pointer to the head to traverse the list
    if (head->data == value) {
        head = head->next; // Moves head to the next node, which could just be nullptr
        delete temp;       // frees the memory of the old head
        std::cout << "Head Deleted" << std::endl;
        return;
    }

    // Case 2 is the the value is not the head node to be deleted
    Node* prev = nullptr; // pointer to store prev node
    while (temp != nullptr && temp->data != value) { // Need to use temp here because if we delete or mess up the head then we lose all of it
        prev = temp;      // sets the last node to prev so we can keep track of both value and pointer
        temp = temp->next;// moves the temp node to the next node
    }

    if (temp == nullptr) {
        std::cout << "Could not find: " << value << std::endl;
        return;
    }
    // Set the prev node to the temps pointer
    prev->next = temp->next;

    // Delete excess memory
    delete temp;
}
int main() {

    // These create a new node
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = nullptr;

    //AddToEnd(head, 50);
    //AddToFront(head, 5);
    //AddAfterNode(head, 30, 15);
    //DeleteNodeValue(head, 30);
    printLinkedList(head);

    return 0;
}