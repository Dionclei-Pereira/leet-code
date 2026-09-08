# Build an Array With Stack Operations
## Problem
### Build the target array using only stack operations.

You are given an integer array target and an integer n.

Starting with an empty stack, the numbers from 1 to n are read in order. For each number, you can perform:

Push — adds the current number to the stack.
Pop — removes the top element from the stack.

The goal is to build exactly the target array using the minimum number of operations.

Example

### Input:
target = [1, 3]
n = 3

### Output:
["Push", "Push", "Pop", "Push"]


The operations work as follows:

Read 1 -> Push -> [1]

Read 2 -> Push -> [1, 2]
          Pop  -> [1]

Read 3 -> Push -> [1, 3]


Therefore, the resulting stack is [1, 3], which matches the target array.

## Approach

The solution processes the numbers sequentially, starting from 1, and compares each number with the next expected value in target.

The variable p represents the current position in the target array:

int p = 0;


For every number i from 1 up to the last element of target, we initially perform a Push:

list.emplace_back("Push");


This is necessary because every number is read from the input stream and must first be pushed onto the stack.

If the current number is not the next value required by the target, we immediately remove it using Pop:

if (i != target[p]) {
    list.emplace_back("Pop");
    continue;
}


This means that the number is only temporarily added to the stack and then discarded.

For example, consider:

target = [1, 3]


We process the numbers as follows:

i = 1

1 == target[0]

Push


The stack becomes:

[1]


Then:

i = 2

2 != target[1]

Push
Pop


The stack returns to:

[1]


Finally:

i = 3

3 == target[1]

Push


The final stack is:

[1, 3]


When the current number matches the expected target value, we keep it in the stack and move the pointer forward:

p++;


Therefore, the pointer always indicates the next value that must be preserved.

Why do we stop at target[target.size() - 1]?

There is no need to process numbers after the last element of target.

For example:

target = [1, 3]
n = 5


Once 3 has been pushed, the target array is already complete. Processing 4 and 5 would only generate unnecessary operations.

Therefore, the loop only goes up to the last target value:

for (int i = 1; i <= target[target.size() - 1]; i++)


This also guarantees that the resulting sequence contains exactly the required target elements.

Step-by-Step Example

Consider:

target = [1, 3, 4]
n = 4


The process is:

i = 1
1 == target[0]

Push

Stack:
[1]


Then:

i = 2
2 != target[1]

Push
Pop

Stack:
[1]


Then:

i = 3
3 == target[1]

Push

Stack:
[1, 3]


Finally:

i = 4
4 == target[2]

Push

Stack:
[1, 3, 4]


The operations are:

Push
Push
Pop
Push
Push


And the resulting stack is exactly:

[1, 3, 4]

## Complexity
Time Complexity

O(m), where m is the value of the last element in target.

Every number from 1 through target.back() is processed exactly once.

For each number, we perform at most two operations:

Push
Pop


Therefore, the total number of operations is linear with respect to the range that needs to be processed.

Space Complexity

O(k), where k is the number of operations stored in the result.

The list vector contains all Push and Pop operations required to construct the target array.

## Key Idea

The key idea is to process the numbers in increasing order and decide whether each number belongs to the target.

For every number:

If it is needed:
    Push

If it is not needed:
    Push
    Pop


For example, with:

target = [1, 3, 5]


we process:

1 -> Push

2 -> Push, Pop

3 -> Push

4 -> Push, Pop

5 -> Push


Result:

Push
Push
Pop
Push
Push
Pop
Push

The important observation is that the numbers are given in increasing order, so we never need to push a number again or reorder elements.

We simply keep the numbers that belong to target and immediately remove the ones that do not.

This allows us to construct the target array using only the allowed Push and Pop operations.