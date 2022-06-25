#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    //Passing in head pointer, payload, and position of payload (where 0 = head, and 1 is 1 unit away from head)
    SinglyLinkedListNode *iterator = head;
    SinglyLinkedListNode *tail = nullptr;

    int linkedListSize = 0;
    //Edge case, position is outside the range of the linkedList...
        //Could solve by checking the current size (O(N)).
    while (iterator) {
        linkedListSize++;
        iterator->next;
    }
    tail = iterator;

    //Check to see if position is viable
    if (position <= linkedListSize) {
        //Create node to insert
        SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);

        //traverse n times to get to position
        //Check if head, mid, or tail case
        //Head Case
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        }
        //Tail Case
        else if (position == linkedListSize) {
            tail->next = newNode;
        }
        //Mid Case
        else {
            //Restart iterator at the beginning
            iterator = head;
            //Traverse LL until at 1 to the left of the desired insertion position
            for (int i = 0; i < (position-1); i++) {
                iterator->next;
            }
            //To insert new node
            //Neighbor to the left need to point to new node
            //Neighbor's -> next needs to be added to our new node's next.
            newNode->next = iterator->next->next;
            iterator->next = newNode;
        }
    }
    else {
        std::cout << "ERROR: Position not valid" << std::endl;
    }
    //Return head
    return head;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist_head);

    fout.close();

    return 0;
}
