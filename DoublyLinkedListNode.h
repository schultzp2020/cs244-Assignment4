#pragma once

// A struct for representing a single node of a doubly-linked list.
template <typename T>
struct DoublyLinkedListNode
{
public:
    // The data stored in the node.
    T value;

    // A pointer to the previous node in the list.
    DoublyLinkedListNode<T>* previous { nullptr };

    // A pointer to the next node in the list.
    DoublyLinkedListNode<T>* next { nullptr };
};
