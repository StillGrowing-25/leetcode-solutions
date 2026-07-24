# Design Linked List

**Problem Link:** https://leetcode.com/problems/design-linked-list/

---

# Intuition

A linked list stores elements in nodes where each node contains a value and a pointer to the next node. Unlike arrays, linked lists do not require contiguous memory allocation, making insertion and deletion operations efficient when the position is known.

To implement the custom linked list, we maintain:
- A `head` pointer that points to the first node.
- A `size` variable to keep track of the number of nodes.
- A `Node` structure containing the value and pointer to the next node.

---

# Approach

### 1. Node Structure
- Create a `Node` class containing:
  - `value` → stores the data.
  - `next` → pointer to the next node.

### 2. Get Operation
- Check if the index is valid.
- Traverse the linked list until the required index.
- Return the node value.

### 3. Add at Head
- Create a new node.
- Point its `next` to the current head.
- Update head to the new node.

### 4. Add at Tail
- Create a new node.
- Traverse until the last node.
- Connect the last node to the new node.

### 5. Add at Index
- Handle special cases:
  - Index `0` → insert at head.
  - Index equal to size → insert at tail.
- Traverse to the previous node.
- Adjust pointers to insert the new node.

### 6. Delete at Index
- Check if the index is valid.
- Handle deletion of the head separately.
- Traverse to the previous node.
- Remove the target node by updating pointers.

---

# Complexity

Let **n = number of nodes**.

- **get(index):** `O(n)`
- **addAtHead(val):** `O(1)`
- **addAtTail(val):** `O(n)`
- **addAtIndex(index, val):** `O(n)`
- **deleteAtIndex(index):** `O(n)`

### Overall:
- **Time complexity:** `O(n)` (for traversal-based operations)
- **Space complexity:** `O(n)` (for storing linked list nodes)

---

# Code

```cpp
class MyLinkedList {
public:
    struct Node {
        int value;
        Node* next;

        Node(int x) {
            value = x;
            next = nullptr;
        }
    };

    Node* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->value;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;

            delete temp;
            size--;

            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* curr = temp->next;

        temp->next = curr->next;

        delete curr;
        size--;
    }
};
```
