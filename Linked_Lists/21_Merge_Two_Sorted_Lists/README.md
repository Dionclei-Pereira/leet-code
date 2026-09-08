# Merge Two Sorted Lists
## Problem
### Merge two sorted linked lists into one sorted linked list.

You are given two singly linked lists, list1 and list2, sorted in ascending order.

The goal is to merge both lists into a single sorted linked list and return its head.

The solution should preserve the existing nodes instead of creating new nodes for every element.

Example
### Input:
list1 = [1, 2, 4]
list2 = [1, 3, 4]

### Output:
[1, 1, 2, 3, 4, 4]


The two lists are:

list1:

1 -> 2 -> 4


list2:

1 -> 3 -> 4


By comparing the values at the current position of each list, we can construct:

1 -> 1 -> 2 -> 3 -> 4 -> 4

## Approach

This solution uses a dummy node to simplify the process of building the resulting linked list.

We start with:

ListNode dummy(-1);
ListNode* current = &dummy;


The dummy node acts as a temporary starting point.

The current pointer always represents the last node of the merged list.

Instead of creating new nodes, we simply connect the existing nodes from list1 and list2.

Comparing the Lists

While both lists still contain nodes:

while (list1 && list2)


we compare their current values:

if (list1->val <= list2->val)


If the value from list1 is smaller or equal, we append that node to the merged list:

current->next = list1;
list1 = list1->next;


Then we move current forward:

current = current->next;


Otherwise, we take the node from list2:

current->next = list2;
list2 = list2->next;


and again move current forward.

Example

Consider:

list1 = 1 -> 2 -> 4
list2 = 1 -> 3 -> 4


Initially:

dummy
  |
  v
 -1

list1 -> 1 -> 2 -> 4
list2 -> 1 -> 3 -> 4


Both values are 1.

Since the condition uses <=, the node from list1 is selected:

dummy -> 1


Now:

list1 -> 2 -> 4
list2 -> 1 -> 3 -> 4


The next comparison is:

2 vs 1


The node from list2 is selected:

dummy -> 1 -> 1


Then:

2 vs 3


The node from list1 is selected:

dummy -> 1 -> 1 -> 2


The process continues until one of the lists becomes empty.

Connecting the Remaining Nodes

When the loop ends, at least one of the lists is empty.

For example:

list1 = nullptr
list2 = 4 -> 5 -> 6


There is no need to compare anything else because list2 is already sorted.

We can simply connect the remaining list:

current->next = list1 ? list1 : list2;


This attaches whichever list still contains nodes.

For example:

merged:

1 -> 2 -> 3

remaining:

4 -> 5 -> 6


After connecting:

1 -> 2 -> 3 -> 4 -> 5 -> 6


No additional traversal is necessary.

Why Use a Dummy Node?

Without a dummy node, we would need to handle the first node of the resulting list separately.

For example, we would have to determine:

Which node should be the head?


and then initialize the rest of the list.

The dummy node eliminates this special case.

We always append the next node using:

current->next = ...


At the end, the actual head of the merged list is:

dummy.next


The dummy node itself is not part of the returned list.

Therefore:

return dummy.next;


returns the first real node.

Step-by-Step Example

Consider:

list1 = [1, 2, 4]
list2 = [1, 3, 4]


Initial state:

dummy -> nullptr

list1 -> 1 -> 2 -> 4
list2 -> 1 -> 3 -> 4

Step 1

Compare:

1 <= 1


Take list1:

merged:
dummy -> 1

Step 2

Compare:

2 > 1


Take list2:

merged:
dummy -> 1 -> 1

Step 3

Compare:

2 <= 3


Take list1:

merged:
dummy -> 1 -> 1 -> 2

Step 4

Compare:

4 > 3


Take list2:

merged:
dummy -> 1 -> 1 -> 2 -> 3

Step 5

Compare:

4 <= 4


Take list1:

merged:
dummy -> 1 -> 1 -> 2 -> 3 -> 4


Now list1 is empty.

The remaining nodes from list2 are:

4


They are connected directly:

1 -> 1 -> 2 -> 3 -> 4 -> 4


The final result is:

[1, 1, 2, 3, 4, 4]

## Complexity
Time Complexity

O(n + m)

Where:

n is the number of nodes in list1.
m is the number of nodes in list2.

Each node is processed at most once.

Therefore, the total time complexity is:

O(n + m)

Space Complexity

O(1)

The solution only uses a few pointers:

ListNode dummy(-1);
ListNode* current = &dummy;


No additional data structures are created.

The existing nodes are reused and their next pointers are rearranged.

Therefore, the extra space complexity is:

O(1)

## Key Idea

The key idea is to take advantage of the fact that both linked lists are already sorted.

At every step, compare the first remaining node of each list:

list1 -> 2 -> ...
list2 -> 3 -> ...

2 < 3

Take 2


After selecting a node, move its list forward and repeat the comparison.

The dummy node provides a convenient starting point for the merged list, while current keeps track of where the next node should be connected.

The overall process is essentially the same merging step used in Merge Sort:

Compare
   ↓
Take the smaller node
   ↓
Move that list forward
   ↓
Repeat


Once one list is empty, the remaining nodes from the other list can be attached directly because they are already sorted.

This results in an efficient solution with:

O(n + m) time
O(1) extra space
No need to create new nodes