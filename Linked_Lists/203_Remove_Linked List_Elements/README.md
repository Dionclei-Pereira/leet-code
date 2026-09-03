# Remove Linked List Elements
## Problem

### Given the head of a singly linked list and an integer val, remove all the nodes of the linked list that have Node.val == val, and return the new head.

Example

### Input:

1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6 -> NULL

Value: 6

### Output:

1 -> 2 -> 3 -> 4 -> 5 -> NULL

## Approach

This solution uses an iterative approach with three pointers:

dummy — a temporary node placed before the head. It simplifies the removal of the first node when its value matches val.

current — the node currently being processed.

lastValid — the last node that should remain in the list. It is used to bypass nodes that need to be removed.

For each node, we:

Check if the current node's value is equal to val.

If it matches, update lastValid->next to skip the current node, then move current to the next valid node.

If it does not match, move both lastValid and current forward.

The dummy node allows the same logic to be used even when the original head needs to be removed.

At the end, dummy.next points to the new head of the linked list.

## Complexity

Time Complexity: O(n) — each node is visited exactly once.

Space Complexity: O(1) — only a constant number of pointers are used.

## Key Idea

The key to removing a node from a singly linked list is to change the next pointer of the previous valid node so that it skips the node that should be removed.

Before:

1 -> 2 -> 6 -> 3 -> NULL

When removing 6:

1 -> 2 ------> 3 -> NULL

The lastValid pointer allows us to update the previous node:

lastValid->next = current->next;


The dummy node also handles cases where the first node needs to be removed:

dummy -> 6 -> 2 -> 3 -> NULL
  |
  +-----------------> 2 -> 3 -> NULL


At the end, dummy.next becomes the new head of the linked list.
