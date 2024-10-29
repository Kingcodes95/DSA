/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy Head will hold the resulting linkedList
        ListNode* dummyHead = new ListNode(0);
        
        // Tail will keep track of the last node in the results list
        ListNode* tail = dummyHead;

        // Variable that holds the carry value during addition
        int carry = 0;

        // Loop that continues untill there are no more digits in both input lists
        // and no remaining carry value
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // If d1 and d2 don't exist set them equal to 0 or if they do then set
            // too l1.val/l2.val
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            // Add digit l1, l2 and carry to sum then % the remainder in digit
            int sum = digit1 + digit2 + carry;
            // so lets say the value of sum is 13, the digit is the left over ammount
            // of 13 so it would be 13 % 10 = 3
            int digit = sum % 10;
            // and then the carry would be 13 / 10 = 1 which would be the tens carry over
            carry = sum / 10;

            // Make a new node and set the digit to the value
            // Then set the tails next value to the newNode
            // and set tail to the last value (tail.next)
            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;
  
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        // create list node result and set the dummyhead.next to it
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};


// 1. First need to set a dummyHead node to 0 so we have a result Head Node
// 2. Then need to initialize a tail node and set it to the dummyHead to keep track of
// the last node
// 3. Need to set up a variable for the carry over value (incase a value adds to over 10)
// 4. in a while loop check each value for l1, l2, carry and add them together to
// variable sum
// 5. Then take the sum value and divide it by module % 10 to get the remainder and set
// to a new variable digit
// 6. carry will be sum divided by 10 to get the carry over value
// 7. Create a newNode with digit as the value
// 8. set tail to point to the newNode and then tail to the next value
// 9. then check l1 and l2 to either next or nullptr
// 10. create new result node and set dummyhead.next to it
// 11. delete the dummy node
// 12. return result