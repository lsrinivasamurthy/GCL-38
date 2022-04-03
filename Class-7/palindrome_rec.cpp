#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int d) {
        data = d;
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

Node *reverse(Node *head) {

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL) {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

// TC: O(n)
Node *get_middle(Node *head) {

    Node *slow = head, *fast = head;

    while (fast->next != NULL and fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// ------------------------------- START --------------------------------------------

Node *check_palindrome_util(Node *current, Node *head, bool &flag) {

    if (current == NULL) {
        return head;
    }

    Node *corresponding_node = check_palindrome_util(current->next, head, flag);
    if (current->data != corresponding_node->data) {
        flag = false;
    }

    return corresponding_node->next;
}

bool check_palindrome(Node *head) {

    bool flag = true;
    check_palindrome_util(head, head, flag);

    return flag;
}

// TC: O(n)
// Aux Space: O(1)
bool check_palindrome_iter(Node *head) {

    if (head == NULL) {
        return true;
    }

    Node *head1 = head;
    Node *middle = get_middle(head);

    Node *head2 = middle->next;
    middle->next = NULL;

    head2 = reverse(head2);

    while(head2 != NULL) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}

bool detect_cycle(Node *head) {

    Node *slow = head, *fast = head;
    while (fast != NULL and fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}


Node *detect_and_remove_cycle(Node *head) {

    Node *slow = head, *fast = head;
    while (fast != NULL and fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // LL does not contain any cycle.
    if (slow != fast) {
        return head;
    }

    // If slow and fast meet at the head, it means the linked list is circular.
    if (slow == head) {
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
        return head;
    }

    // Now, slow and fast will both run one-step at a time.
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
    return head;
}

int main() {

    Node *head = new Node(10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 10);

    cout << check_palindrome(head) << endl;

    head = NULL;
    head = insert_at_end(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 10);

    cout << check_palindrome(head) << endl;

    // -------------------------------------------------

    head = new Node(10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 10);

    cout << check_palindrome_iter(head) << endl;

    head = NULL;
    head = insert_at_end(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 10);

    cout << check_palindrome_iter(head) << endl;

    head = NULL;
    head = insert_at_end(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 10);

    cout << check_palindrome_iter(head) << endl;

    // -------------------------------------------------

    cout << endl;

    head = new Node(1);
    Node *tail = head;
    tail->next = new Node(2);
    tail = tail->next;
    tail->next = new Node(3);
    tail = tail->next;
    tail->next = new Node(4);
    tail = tail->next;
    tail->next = new Node(5);
    tail = tail->next;
    tail->next = new Node(6);
    tail = tail->next;
    tail->next = new Node(7);
    tail = tail->next;
    tail->next = head->next->next;

    cout << detect_cycle(head) << endl;

    // -------------------------------------------------

    head = detect_and_remove_cycle(head);
    print_linked_list(head);

    // -------------------------------------------------

    head = new Node(1);
    tail = head;
    tail->next = new Node(2);
    tail = tail->next;
    tail->next = new Node(3);
    tail = tail->next;
    tail->next = new Node(4);
    tail = tail->next;
    tail->next = head;
    head = detect_and_remove_cycle(head);
    print_linked_list(head);

}