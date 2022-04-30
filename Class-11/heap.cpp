#include<bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------------------------------------------------------------

// TC: O(log(n))
// Aux Space: O(log(n))

// HW: Try performing top-down heapify iteratively. (Will decrease the aux space to O(1)).

void top_down_heapify(vector<int> &heap, int index) {

    int left_child_index = 2*index + 1;
    int right_child_index = 2*index + 2;

    // Check that out the following 3 indexes, which index has the maximum value:
    // `index`, `left_child_index`, `right_child_index`.

    int largest_value_index = index;
    if (left_child_index < heap.size() and heap[left_child_index] > heap[largest_value_index]) {
        largest_value_index = left_child_index;
    }
    if (right_child_index < heap.size() and heap[right_child_index] > heap[largest_value_index]) {
        largest_value_index = right_child_index;
    }

    if (largest_value_index != index) {
        swap(heap[index], heap[largest_value_index]);
        top_down_heapify(heap, largest_value_index);
    }
}


void delete_from_max_heap(vector<int> &heap) {

    int n = heap.size();
    if (n == 0) {
        return;
    }

    // Step-1: Replace the root with the last node and scrap-off the last node.
    heap[0] = heap[n - 1];
    heap.pop_back();

    top_down_heapify(heap, 0);
}

// ----------------------------------------------------------------------------------------------------------------

// TC: O(log(n))
// Aux Space: O(log(n))

// HW: Try performing bottom-up heapify iteratively. (Will decrease the aux space to O(1)).

void bottom_up_heapify(vector<int> &heap, int index) {

    if (index == 0) {
        return;
    }

    int parent_index = (index - 1) / 2;

    if (heap[index] > heap[parent_index]) {
        swap(heap[index], heap[parent_index]);
        bottom_up_heapify(heap, parent_index);
    }
}

void insert_in_max_heap(vector<int> &heap, int element) {

    // Step-1 & 2: Create some space and insert the new element at the end.
    heap.push_back(element);

    // Step-3: Bottom-up heapify on the last index.
    bottom_up_heapify(heap, heap.size() - 1);
}

// ----------------------------------------------------------------------------------------------------------------

int main() {

    vector<int> heap = {10, 5, 3, 2, 4, 0, 1};
    delete_from_max_heap(heap);

    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    heap = {10, 5, 3, 2, 4};
    insert_in_max_heap(heap, 15);

    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    insert_in_max_heap(heap, 12);
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

}