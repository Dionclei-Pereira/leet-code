# Reverse Linked List
## Problem

### Given the head of a singly linked list, reverse the list and return the new head.

Example

### Input:

1 -> 2 -> 3 -> 4 -> 5 -> NULL


### Output:

5 -> 4 -> 3 -> 2 -> 1 -> NULL

## Approach

This solution uses an iterative approach with three pointers:

current — the node currently being processed.
previous — the previous node, which becomes the new next of the current node.
next — temporarily stores the next node so we don't lose the rest of the list.

For each node, we:

Store the next node.
Reverse the current node's next pointer.
Move previous forward.
Move current forward.

When current becomes nullptr, previous points to the new head of the reversed list.

Complexity
Time Complexity: O(n) — each node is visited exactly once.
Space Complexity: O(1) — only a constant number of pointers are used.
Key Idea

The key to reversing a linked list is to change the direction of each next pointer while keeping track of the next node before modifying it.

Before:
1 -> 2 -> 3 -> NULL

After:
NULL <- 1 <- 2 <- 3
                  ^
                previous

At the end, previous becomes the new head of the reversed linked list.
