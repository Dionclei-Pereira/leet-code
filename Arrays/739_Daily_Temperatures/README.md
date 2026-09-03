# Daily Temperatures
## Problem

### Given an array of integers temperatures representing the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.

If there is no future day for which this is possible, keep answer[i] == 0.

Example

### Input:

[73, 74, 75, 71, 69, 72, 76, 73]

### Output:

[1, 1, 4, 2, 1, 1, 0, 0]

## Approach

This solution uses a monotonic stack to keep track of the indices of temperatures that have not yet found a warmer day.

The stack stores indices instead of temperature values because we need the index to calculate how many days we have to wait.

For each temperature, we:

Check whether the current temperature is warmer than the temperature at the top of the stack.

While it is warmer, remove the index from the stack and calculate the number of days between the current index and the removed index.

Store this difference in the corresponding position of the answer array.

Add the current index to the stack.

The stack maintains temperatures in decreasing order. When a warmer temperature is found, it can resolve multiple previous temperatures at once.

## Complexity

Time Complexity: O(n) — each index is added to the stack once and removed at most once.

Space Complexity: O(n) — the stack can contain up to n indices.

## Key Idea

The key to this solution is using a monotonic decreasing stack.

For example:

Temperatures:

75 -> 71 -> 69
              ^
             top


When we find 72, it is warmer than both 69 and 71:

72 > 69  -> answer[4] = 1
72 > 71  -> answer[3] = 2
72 < 75  -> keep 75 in the stack


The stack allows us to efficiently find the next warmer temperature without comparing every pair of days.

Instead of looking forward for every temperature, each index is processed at most twice: once when it enters the stack and once when it is removed.