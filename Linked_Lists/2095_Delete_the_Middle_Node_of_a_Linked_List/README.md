# Delete the Middle Node of a Linked List
## Problem
### Delete the middle node of a singly linked list.

You are given the head of a singly linked list.

The middle node is defined as the node at index n / 2, where the list uses zero-based indexing.

If there are two middle nodes, the second middle node must be removed.

After removing the middle node, return the head of the modified linked list.

Example
### Input:
head = [1, 3, 4, 7, 1, 2, 6]

### Output:
[1, 3, 4, 1, 2, 6]


The linked list is:

1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6
             ^
           middle


The node 7 is the middle node, so it is removed:

1 -> 3 -> 4 -> 1 -> 2 -> 6

## Approach

This solution uses the slow and fast pointer technique to find the middle of the linked list in a single traversal.

We use two pointers:

ListNode* slow = head;
ListNode* fast = head->next->next;


The slow pointer moves one node at a time, while fast moves two nodes at a time.

slow -> 1 step
fast -> 2 steps


When fast reaches the end of the list, slow will be positioned immediately before the middle node.

This is important because we need access to the node before the middle in order to remove it from the linked list.

Handling the Single-Node Case

Before using the two pointers, the solution checks whether the list contains only one node:

if (!head->next) return nullptr;


If the list contains only one node:

1


that node is the middle node.

After removing it, the list becomes empty:

nullptr


Therefore, we can return nullptr immediately.

Finding the Middle

For lists with at least two nodes, the pointers are initialized as:

ListNode* slow = head;
ListNode* fast = head->next->next;


The important detail is that fast starts at the third node, instead of head.

The loop is:

while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}


During each iteration:

slow -> moves 1 node
fast -> moves 2 nodes


Because fast starts two positions ahead, slow ends up exactly at the node immediately before the middle.

Example with 5 Nodes

Consider:

1 -> 2 -> 3 -> 4 -> 5


Initial state:

slow
 ↓
1 -> 2 -> 3 -> 4 -> 5
          ↑
         fast


After one iteration:

      slow
       ↓
1 -> 2 -> 3 -> 4 -> 5
                  ↑
                 fast


Now fast cannot move two nodes further, so the loop stops.

slow is at node 2, which is immediately before the middle node 3.

Therefore, node 3 can be removed.

Example with 6 Nodes

Consider:

1 -> 2 -> 3 -> 4 -> 5 -> 6


There are two middle nodes:

1 -> 2 -> 3 -> 4 -> 5 -> 6
          ^    ^
       middle candidates


According to the problem, the second middle node, 4, must be removed.

The pointers work as follows:

Initial:

slow
 ↓
1 -> 2 -> 3 -> 4 -> 5 -> 6
          ↑
         fast


After the first iteration:

      slow
       ↓
1 -> 2 -> 3 -> 4 -> 5 -> 6
                  ↑
                 fast


The loop stops because fast is at node 5 and fast->next is node 6.

Therefore:

slow = 3
slow->next = 4


The node after slow is the second middle node.

Removing the Middle Node

Once slow is positioned immediately before the middle node, removing it is straightforward:

slow->next = slow->next->next;


Suppose the list is:

1 -> 2 -> 3 -> 4 -> 5
          ^
        middle


Here:

slow = 2
slow->next = 3


Executing:

slow->next = slow->next->next;


changes the links to:

1 -> 2 ------> 4 -> 5
     |
     +---- 3 is skipped


The node 3 is no longer part of the linked list.

Finally, we return the original head:

return head;

## Complexity
Time Complexity

O(n)

The linked list is traversed only once.

The fast pointer moves two nodes at a time, while slow moves one node at a time.

Therefore, the total number of operations grows linearly with the number of nodes.

Space Complexity

O(1)

Only two pointers are used:

ListNode* slow;
ListNode* fast;


No additional data structures are required.

## Key Idea

The key idea is to use two pointers moving at different speeds.

slow -> 1 node at a time
fast -> 2 nodes at a time


The special initialization:

slow = head;
fast = head->next->next;


allows slow to stop immediately before the middle node.

This is exactly what is needed because deleting a node from a singly linked list requires changing the next pointer of the node that comes before it.

Once slow is in the correct position, the deletion is just:

slow->next = slow->next->next;


Therefore, the entire problem can be solved with:

O(n) time
O(1) extra space
One traversal of the linked list