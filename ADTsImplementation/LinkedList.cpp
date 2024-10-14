#include <iostream>

class Node {
    public:
        int data;
        Node* next;

};
void printLinkedList(Node* n) {
    // Check if n because if it hits the last not it won't run the function because it == nullptr
    while (n != nullptr) {
        std::cout << n->data << " ";
        n = n->next;
    }
    std::cout << '\n';
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
void BubbleSort(Node* head) {
    if (head == nullptr) { std::cout << "List is empty\n"; return; }

    
    bool swapped;               // Bool to check if elements are being swapped
    Node* ptr1;                 // This pointer will traverse the list
    Node* lptr = nullptr;       // This pointer will mark the sorted portion of the list, "lptr" is built in

    do {                        // Main Loop: only works if items are being swapped.
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) { // Inner While Loop: we stop looping after lptr because everything after is already sorted
            if (ptr1->data > ptr1->next->data) { // While the Data for the pointer value is greater than the next nodes value
                std::swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
        
            ptr1 = ptr1->next;  // Then move to the next values

        }

        lptr = ptr1; // sets the sorted list to the next number so we don't touch the old values
    } while (swapped);
}
void SortedInsertion(Node*& sorted, Node* newNode) { // sorted is the head of the list, newNode is the new node to be inserted
    if (sorted == nullptr || sorted->data >= newNode->data) {  // Checks the condition if sorted is empty or greater than the newNode
        newNode->next = sorted; // Points new node to the sorted
        sorted = newNode;       // makes newNode the new head of the list cause its being inserted in the front
    } else {
        // if the if condition fails then you need to start from the head of the sorted list to find the correct insertion
        Node* current = sorted;
        while (current->next != nullptr && current->next->data < newNode->data) {
            current = current->next;
        }
        // Insert newNode between current and current->next
        newNode->next = current->next;
        current->next = newNode;
    }
}
void InsertionSort(Node*& head) {
    Node* sorted = nullptr; // Start with an empty sorted list
    Node* current = head;   // Pointer to traverse the original unsorted list

    while (current != nullptr) {
        Node* next = current->next;
        SortedInsertion(sorted, current); // Insert the current node into the sorted List
        current = next;
    }

    head = sorted;

}
int main() {

    // These create a new node
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 40;
    head->next = second;
    second->data = 32;
    second->next = third;
    third->data = 10;
    third->next = fourth;
    fourth->data = 188;
    fourth->next = nullptr;

    //AddToEnd(head, 50);
    //AddToFront(head, 5);
    //AddAfterNode(head, 30, 15);
    //DeleteNodeValue(head, 30);
    printLinkedList(head);
    //BubbleSort(head);
    InsertionSort(head);
    printLinkedList(head);

    return 0;
}