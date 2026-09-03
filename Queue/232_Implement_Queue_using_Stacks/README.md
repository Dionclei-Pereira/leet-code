# Implement Queue using Stacks
## Problem
### Implement a first in first out (FIFO) queue using only two stacks.

The queue should support the following operations:

push(x) — adds element x to the back of the queue.
pop() — removes the element from the front of the queue and returns it.
peek() — returns the element at the front of the queue.
empty() — returns true if the queue is empty, otherwise false.

Example:

### Input:
push(1)
push(2)
peek()
pop()
empty()

### Output:
1
1
false

## Approach

This solution uses two stacks, in and out, to simulate the behavior of a FIFO queue using LIFO stacks.

The in stack is responsible for receiving new elements through the push() operation.

The out stack is responsible for providing elements in the correct queue order.

When calling push(x), the element is simply added to the in stack:

in.push(x);


When calling peek(), we first check whether the out stack is empty.

If it is empty, we move all elements from in to out:

in:   [1, 2, 3]

        ↓ transfer

out:  [3, 2, 1]
             ^
            top


Because a stack reverses the order of its elements, the oldest element ends up on top of out.

Therefore, the first element inserted into the queue is always available at out.top().

The pop() operation calls peek() first to guarantee that out contains the next element to remove. It then removes and returns the top element from out.

The empty() operation simply checks whether both stacks are empty:

return in.empty() && out.empty();

### Complexity

Time Complexity:

push() — O(1)
pop() — O(1) amortized
peek() — O(1) amortized
empty() — O(1)

Although peek() or pop() can take O(n) when transferring elements between the stacks, each element is moved from in to out at most once. Therefore, the amortized complexity of each queue operation is O(1).

Space Complexity: O(n) — the two stacks together can contain up to n elements.

### Key Idea

The key to this solution is using two stacks to reverse the order of elements.

A stack follows LIFO (Last In, First Out), while a queue follows FIFO (First In, First Out).

For example:

Queue:

1 -> 2 -> 3
^
front


After pushing the elements into in:

in:

3
2
1
^
top


When we transfer them to out:

out:

1  <- top
2
3


The oldest element, 1, becomes the top of out, allowing the stack to behave like the front of a queue.

This transfer only happens when out is empty, which makes the solution efficient through amortized O(1) operations.