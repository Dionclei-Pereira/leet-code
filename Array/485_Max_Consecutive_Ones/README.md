# Max Consecutive Ones
## Problem
### Find the maximum number of consecutive 1s in a binary array.

You are given a binary array nums, where each element is either 0 or 1.

The goal is to find the maximum number of consecutive 1s that appear in the array.

Example
### Input:
nums = [1, 1, 0, 1, 1, 1]

### Output:
3


The array contains the following sequences of consecutive 1s:

[1, 1]       -> 2 ones

[1, 1, 1]    -> 3 ones


Therefore, the maximum number of consecutive 1s is:

3

## Approach

The solution uses two variables:

int max = 0;
int count = 0;


The variable count keeps track of the current sequence of consecutive 1s.

The variable max stores the largest sequence found so far.

We then iterate through the entire array:

for (int i = 0; i < nums.size(); i++)


For every element, we check whether it is equal to 1.

If the current element is 1, we increase count:

if (nums[i] == 1) {
    ++count;
}


This means that the current sequence of consecutive 1s continues.

For example:

nums = [1, 1, 1]


The value of count changes as follows:

1 -> count = 1

1 -> count = 2

1 -> count = 3

Resetting the Count

If the current element is 0, the sequence of consecutive 1s has ended.

Therefore, we reset count to zero:

else {
    count = 0;
}


For example:

nums = [1, 1, 0, 1]


The process is:

1 -> count = 1
1 -> count = 2
0 -> count = 0
1 -> count = 1


The 0 separates the two sequences of 1s.

Updating the Maximum

After processing each element, we compare the current sequence with the maximum sequence found so far:

max = std::max(count, max);


This guarantees that max always contains the largest number of consecutive 1s encountered up to that point.

For example:

nums = [1, 1, 0, 1, 1, 1]


The values change as follows:

Element	count	max
1	1	1
1	2	2
0	0	2
1	1	2
1	2	2
1	3	3

At the end:

max = 3


Therefore, the answer is:

3

Step-by-Step Example

Consider:

nums = [1, 0, 1, 1, 0, 1, 1, 1]


We process each element from left to right.

i = 0
nums[0] = 1


Increment count:

count = 1
max = 1

i = 1
nums[1] = 0


Reset count:

count = 0
max = 1

i = 2
nums[2] = 1


Increment:

count = 1
max = 1

i = 3
nums[3] = 1


Increment:

count = 2
max = 2

i = 4
nums[4] = 0


Reset:

count = 0
max = 2

i = 5
nums[5] = 1


Increment:

count = 1
max = 2

i = 6
nums[6] = 1


Increment:

count = 2
max = 2

i = 7
nums[7] = 1


Increment:

count = 3
max = 3


The final answer is:

3

Why Does This Work?

The algorithm only needs to remember two pieces of information:

The length of the current sequence of consecutive 1s.
The largest sequence found so far.

Whenever we encounter a 1, the current sequence grows:

count++


Whenever we encounter a 0, the current sequence ends:

count = 0


The maximum is updated after every element:

max = std::max(count, max);


Because the array is processed from left to right, every possible sequence of consecutive 1s is considered.

C++ Implementation
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                ++count;
            } else {
                count = 0;
            }

            max = std::max(count, max);
        }

        return max;
    }
};


The algorithm does not modify the input array.

It only uses two integer variables to keep track of the current and maximum sequences.

Another Example

Consider:

nums = [1, 1, 1, 1, 0, 1]


The first four elements form a sequence of four consecutive 1s:

[1, 1, 1, 1]


When the 0 is found:

count = 0


The final 1 creates a new sequence:

count = 1


But the maximum remains:

max = 4


Therefore:

Output:
4

Edge Cases
All elements are 0
nums = [0, 0, 0]


Every 0 resets the counter:

count = 0


Therefore:

Output:
0

All elements are 1
nums = [1, 1, 1, 1, 1]


The counter increases with every element:

1 -> 1
1 -> 2
1 -> 3
1 -> 4
1 -> 5


Therefore:

Output:
5

Only one element
nums = [1]


The counter becomes:

count = 1


Therefore:

Output:
1


For:

nums = [0]


the result is:

0

## Complexity
Time Complexity

O(n), where n is the number of elements in nums.

The algorithm iterates through the array exactly once.

For each element, it performs a constant amount of work:

Check whether the element is 1.
Increment or reset count.
Update max.

Therefore, the total time complexity is:

O(n)

Space Complexity

O(1).

The algorithm only uses two integer variables:

int max = 0;
int count = 0;


No additional data structure is required.

The input array is also not modified.

Therefore, the auxiliary space complexity is:

O(1)

## Key Idea

The key idea is to count the current sequence of consecutive 1s while scanning the array.

For every element:

If it is 1:

count++


If it is 0:

count = 0


After each element:

max = max(count, max)


For example:

nums = [1, 1, 0, 1, 1, 1]


The process can be summarized as:

1 -> count = 1 -> max = 1

1 -> count = 2 -> max = 2

0 -> count = 0 -> max = 2

1 -> count = 1 -> max = 2

1 -> count = 2 -> max = 2

1 -> count = 3 -> max = 3


The final answer is:

3


The important observation is that a 0 always marks the end of the current sequence of 1s. By resetting the counter whenever this happens, we can find the longest sequence using a single pass through the array.