#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// TC: O(1)
Node *insert_at_beginning(Node *head, int new_data) {

    Node *new_node = new Node(new_data);
    new_node->next = head;
    head = new_node;

    return head;
}

// TC: O(n)
void print_linked_list(Node *head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// TC: O(n)
Node *insert_at_end(Node *head, int new_data) {
    
    if (head == NULL) {
        return insert_at_beginning(head, new_data);
    }

    Node *new_node = new Node(new_data);

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    return head;
}

// TC: O(min(n, pos))
Node *insert_at_position(Node *head, int new_data, int pos) {
    // If pos > (len + 1) => insert at the end of the linked list.

    if (pos < 1) {
        return head;
    }
    if (pos == 1 or head == NULL) {
        return insert_at_beginning(head, new_data);
    }

    Node *new_node = new Node(new_data);
    Node *temp = head;

    pos -= 2;
    while(pos > 0 and temp->next != NULL) {
        temp = temp->next;
        pos--;
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}

// TC: O(1)
Node *delete_from_beginning(Node *head) {

    if (head == NULL) {
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete(temp);

    return head;
}


// TC: O(n)
Node *delete_from_end(Node *head) {

    if (head == NULL or head->next == NULL) {
        return delete_from_beginning(head);
    }

    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    Node *temp2 = temp->next;
    temp->next = NULL;
    delete(temp2);

    return head;
}

// TC: O(n)
Node *delete_from_pos(Node *head, int pos) {
    // For pos > n: Don't do any deletion

    if (pos < 1) {
        return head;
    }
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL) {
        if (pos == 1) {
            delete(head);
            return NULL;
        }
        else {
            return head;
        }
    }

    Node *temp = head;
    pos -= 2;
    while (pos > 0 and temp->next != NULL) {
        temp = temp->next;
        pos--;
    }

    // This means that pos > n. Therefore, don't do any deletion.
    if (temp->next == NULL) {
        return head;
    }

    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete(temp2);

    return head;
}

int main() {

    Node *head = NULL;
    head = insert_at_beginning(head, 4);
    head = insert_at_beginning(head, 3);
    head = insert_at_beginning(head, 2);
    head = insert_at_beginning(head, 1);

    print_linked_list(head);

    head = insert_at_end(head, 6);
    head = insert_at_end(head, 7);
    head = insert_at_end(head, 8);

    print_linked_list(head);

    head = insert_at_position(head, 5, 5);

    print_linked_list(head);

    head = insert_at_position(head, 9, 1000);

    print_linked_list(head);

    head = insert_at_position(head, 0, 1);

    print_linked_list(head);


    // ---------------------------------------------

    cout << endl;

    head = NULL;
    head = insert_at_end(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);

    print_linked_list(head);

    head = delete_from_beginning(head);

    print_linked_list(head);

    // ---------------------------------------------

    cout << endl;

    head = NULL;
    head = insert_at_end(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);

    print_linked_list(head);

    head = delete_from_end(head);

    print_linked_list(head);

    // ---------------------------------------------

    cout << endl;

    head = NULL;
    head = insert_at_end(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 50);

    print_linked_list(head);

    head = delete_from_pos(head, 4);

    print_linked_list(head);
    
}