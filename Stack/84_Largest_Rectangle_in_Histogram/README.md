# Largest Rectangle in Histogram
## Problem
### Find the largest rectangular area that can be formed in a histogram.

You are given an array heights, where each element represents the height of a histogram bar.

Each bar has a width of 1.

The goal is to find the largest rectangle that can be formed using one or more consecutive bars.

Example
### Input:
heights = [2, 1, 5, 6, 2, 3]

### Output:
10


The largest rectangle is formed by the bars with heights 5 and 6.

        6
    ┌───┐
    │   │
    │   │  5
┌───┐   ├───┐
│   │   │   │
│   │   │   │
└───┴───┴───┴──────
  2   1   5   6   2   3
          └───────┘
             2


The rectangle has:

height = 5
width = 2

area = 5 * 2 = 10

## Approach

The solution uses a monotonic increasing stack.

The stack stores the indexes of bars whose heights are in increasing order.

For example:

heights = [2, 1, 5, 6, 2, 3]

stack:
index 2 -> height 5
index 3 -> height 6


The reason for storing indexes instead of heights is that we need to calculate the width of each rectangle.

The main idea is:

When we encounter a bar shorter than the bar on top of the stack, we have found the right boundary of the rectangle represented by that bar.

This allows us to calculate the maximum area immediately.

Adding a Sentinel Value

The first operation is:

heights.push_back(0);


We add a 0 at the end of the histogram.

This is called a sentinel value.

Its purpose is to force all remaining bars in the stack to be processed when we reach the end of the array.

For example:

[2, 1, 5, 6, 2, 3]


becomes:

[2, 1, 5, 6, 2, 3, 0]


When the algorithm reaches 0, every remaining bar is taller than 0, so they are removed from the stack and their areas are calculated.

Without the sentinel, we would need an additional loop after the main iteration to process the remaining elements.

Maintaining the Monotonic Stack

The stack is maintained so that the heights are always increasing.

The condition is:

while (!stack.empty() && heights[i] <= heights[stack.back()])


If the current bar is shorter than or equal to the bar at the top of the stack, the top bar can no longer extend to the right.

Therefore, we remove it and calculate the largest rectangle for that height.

int height = heights[stack.back()];
stack.pop_back();


The removed height becomes the height of the rectangle we are calculating.

Calculating the Width

After removing the bar, we need to determine how far its rectangle can extend.

This is where storing indexes becomes important.

There are two cases.

Case 1 — The Stack Becomes Empty
if (stack.empty()) {
    width = i;
}


If the stack is empty, there is no smaller bar to the left.

Therefore, the rectangle can extend from index 0 to i - 1.

Its width is:

width = i


For example:

heights = [2, 2, 2]


When processing the final 0, the last bar can extend across all three positions:

width = 3


So:

area = 2 * 3 = 6

Case 2 — The Stack Is Not Empty

If the stack still contains an index, that index represents the closest bar to the left that is shorter than the removed height.

The current index i represents the first position to the right that is also shorter.

Therefore, the rectangle extends from:

stack.back() + 1


to:

i - 1


The width is:

width = i - stack.back() - 1;


The -1 is necessary because both boundaries themselves are excluded.

Example of Width Calculation

Consider:

heights = [2, 1, 5, 6, 2, 3]


When we reach the 2 at index 4, the bar with height 6 is removed.

Before removing it:

stack -> [1, 2, 3]
                  ^
                 6


The current index is:

i = 4


After removing index 3, the new top of the stack is index 2, whose height is 5.

Therefore:

left boundary  = 2
right boundary = 4


The rectangle with height 6 can only occupy index 3.

Thus:

width = 4 - 2 - 1
      = 1


And:

area = 6 * 1
     = 6


The bar with height 5, however, can extend across indexes 2 and 3:

width = 4 - 1 - 1
      = 2

area = 5 * 2
     = 10


Therefore, the maximum area becomes 10.

Step-by-Step Example

Consider:

heights = [2, 1, 5, 6, 2, 3]


After adding the sentinel:

[2, 1, 5, 6, 2, 3, 0]

Index 0
height = 2

stack = [0]

Index 1

Current height:

1


Since:

1 <= 2


we remove index 0.

The stack becomes empty, so:

height = 2
width = 1
area = 2


Then index 1 is added:

stack = [1]

Index 2

Current height:

5


Since 5 > 1, no rectangle needs to be closed.

stack = [1, 2]

Index 3

Current height:

6


Again, the height is increasing:

stack = [1, 2, 3]

Index 4

Current height:

2


Now 2 is smaller than 6.

We remove height 6:

height = 6
width = 1
area = 6


Then 2 is also smaller than 5, so we remove height 5:

height = 5
width = 2
area = 10


The maximum area is now:

maxArea = 10


The current index is then added:

stack = [1, 4]


The remaining elements are processed in the same way.

When we finally reach the sentinel 0, all remaining bars are removed and their areas are calculated.

The final answer is: 10

## Complexity
Time Complexity

O(n)

At first glance, the nested while loop may look like it makes the algorithm O(n²).

However, each index is:

pushed onto the stack once;
removed from the stack at most once.

Therefore, the total number of stack operations is proportional to n.

So the overall complexity is:

O(n)

Space Complexity

O(n)

In the worst case, the stack can contain all indexes.

For example, with an increasing histogram:

[1, 2, 3, 4, 5]


all indexes can remain in the stack until the sentinel 0 is processed.

Therefore:

O(n)

## Key Idea

The key idea is to maintain a monotonic increasing stack of indexes.

heights:

1  2  3  4  5
   ↑  ↑  ↑  ↑
   stack indexes


As long as the heights are increasing, we keep their indexes in the stack.

When we encounter a smaller height:

current height < stack top height


we know that the taller bar can no longer extend to the right.

At that moment, we calculate the largest rectangle using that bar's height.

The width is determined by two boundaries:

left  -> first smaller bar to the left
right -> first smaller bar to the right


The area is then:

area = height * width


The sentinel 0 at the end guarantees that every remaining bar is eventually processed.

Therefore, the algorithm solves the problem efficiently using:

Monotonic increasing stack
O(n) time
O(n) extra space

The most important observation is that a bar's maximum rectangle can be calculated exactly when we discover the first smaller bar to its right.