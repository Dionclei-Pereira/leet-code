# Linked List Cycle
## Problem
### Determine whether a linked list contains a cycle.

You are given the head of a singly linked list.

A cycle exists if, by continuously following the next pointer, we can reach a node that has already been visited.

The goal is to return:

true — if the linked list contains a cycle.
false — if the linked list eventually reaches nullptr.
Example
### Input:
head = [3, 2, 0, -4]


Where the last node points back to the node containing 2:

3 -> 2 -> 0 -> -4
     ^          |
     |__________|

### Output:
true


Another example without a cycle:

1 -> 2 -> 3 -> nullptr

Output:
false

## Approach

This solution uses Floyd's Cycle Detection Algorithm, also known as the slow and fast pointer technique.

We create two pointers:

ListNode* slow = head;
ListNode* fast = head;


The two pointers move through the linked list at different speeds:

slow -> moves 1 node at a time
fast -> moves 2 nodes at a time


The main idea is simple:

If there is a cycle, the faster pointer will eventually catch the slower pointer.

If there is no cycle, fast will eventually reach nullptr.

Moving the Pointers

The loop continues while fast and fast->next are valid:

while (fast && fast->next)


Inside the loop:

fast = fast->next->next;
slow = slow->next;


Therefore:

slow -> 1 step
fast -> 2 steps


After moving both pointers, we check whether they are pointing to the same node:

if (fast == slow) {
    return true;
}


If they meet, a cycle must exist.

Why Does This Work?

Consider a linked list with a cycle:

1 -> 2 -> 3 -> 4
         ^    |
         |____|


Once both pointers enter the cycle, they are effectively moving around a circular path.

Since fast moves twice as quickly as slow, the distance between them changes until fast catches slow.

For example:

slow -> 2
fast -> 3


Then:

slow -> 3
fast -> 2


Then eventually:

slow -> 4
fast -> 4


At this point:

fast == slow


and the function returns:

true

Why Does It Detect a Cycle Without Storing Visited Nodes?

A common solution would be to use a set or unordered_set to store every node that has already been visited.

For example:

visited = {
    address of node 1,
    address of node 2,
    address of node 3,
    ...
}


When encountering a node that already exists in the set, we know there is a cycle.

However, that approach requires O(n) additional memory.

The slow and fast pointer approach does not need to store visited nodes.

It only uses:

ListNode* slow;
ListNode* fast;


Therefore, the solution uses O(1) extra space.

Example with a Cycle

Consider:

1 -> 2 -> 3 -> 4
         ^    |
         |____|


Initial state:

slow
 ↓
1 -> 2 -> 3 -> 4
 ↑
fast


After one iteration:

1 -> 2 -> 3 -> 4
     ↑    ↑
    slow fast


After another iteration:

1 -> 2 -> 3 -> 4
          ↑
         slow


The fast pointer continues moving around the cycle.

Eventually:

1 -> 2 -> 3 -> 4
          ↑
       slow/fast


Both pointers meet at the same node.

Therefore:

return true;

Example Without a Cycle

Consider:

1 -> 2 -> 3 -> 4 -> nullptr


The pointers move forward:

slow -> 1
fast -> 1


Then:

slow -> 2
fast -> 3


Then:

slow -> 3
fast -> nullptr


Since fast eventually reaches nullptr, the loop ends:

return false;


Therefore, there is no cycle.

## Complexity
Time Complexity

O(n)

In the case where there is no cycle, the fast pointer reaches the end of the list after traversing the nodes.

If there is a cycle, the fast pointer eventually catches the slow pointer.

Therefore, the overall time complexity is:

O(n)

Space Complexity

O(1)

The solution only uses two pointers:

ListNode* slow;
ListNode* fast;


No additional data structures are required.

Therefore:

O(1)

## Key Idea

The key idea is to use two pointers moving at different speeds:

slow -> 1 node
fast -> 2 nodes


There are two possible scenarios.

No Cycle

The linked list eventually reaches:

nullptr


Therefore, fast or fast->next becomes nullptr and the algorithm returns:

false

Cycle

The pointers enter the cycle and continue moving around it.

Because fast moves twice as fast as slow, it must eventually catch the slow pointer:

fast == slow


When this happens, we know that the linked list contains a cycle and return:

true


The main advantage of this approach is that it detects the cycle in O(n) time using only O(1) extra space, without modifying the linked list or storing visited nodes.