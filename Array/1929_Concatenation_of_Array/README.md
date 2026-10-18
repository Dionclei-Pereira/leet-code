# Concatenation of Array

## Problem

### Create an array by concatenating two copies of the original array.

You are given an integer array `nums` of length `n`.

Your task is to create an array `ans` of length `2n`, where the original array is repeated twice.

For every index `i` from `0` to `n - 1`:

- `ans[i] == nums[i]`
- `ans[i + n] == nums[i]`

The goal is to return the resulting array containing two consecutive copies of `nums`.

### Example 1

**Input:**

```text
nums = [1, 2, 1]
```

**Output:**

```text
[1, 2, 1, 1, 2, 1]
```

**Explanation:**

The resulting array contains the original elements twice:

```text
ans = [nums[0], nums[1], nums[2],
       nums[0], nums[1], nums[2]]
```

Therefore:

```text
ans = [1, 2, 1, 1, 2, 1]
```

### Example 2

**Input:**

```text
nums = [1, 3, 2, 1]
```

**Output:**

```text
[1, 3, 2, 1, 1, 3, 2, 1]
```

**Explanation:**

The original array has four elements. The resulting array contains eight elements, with the original sequence repeated twice.

```text
ans = [1, 3, 2, 1, 1, 3, 2, 1]
```

## Approach

The solution creates a new array with twice the length of `nums` and copies the original elements into it two times.

First, we determine the length of the input array:

```cpp
int len = nums.size();
```

The `size()` method returns the number of elements in a `std::vector`.

For example:

```text
nums = [1, 2, 1]

len = 3
```

Next, we create the result vector with twice the original length:

```cpp
std::vector<int> result(len * 2);
```

Since `len` is `3`, the resulting vector has six positions.

Initially, these positions contain the default value for `int`, which is `0`.

```text
result = [0, 0, 0, 0, 0, 0]
```

### Copying the elements

The solution uses two nested loops:

```cpp
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < len; j++) {
        result[i * len + j] = nums[j];
    }
}
```

The outer loop controls how many times the original array is copied.

The inner loop iterates through every element of `nums`.

The expression `i * len + j` determines the destination index in the resulting array.

### Understanding the index calculation

The most important part of the solution is:

```cpp
result[i * len + j] = nums[j];
```

The variable `i` indicates which copy is being processed, while `j` indicates the position of the current element in the original array.

When `i = 0`, the elements are copied into the first half:

```text
result[0 * 3 + 0] = nums[0]  // result[0] = 1
result[0 * 3 + 1] = nums[1]  // result[1] = 2
result[0 * 3 + 2] = nums[2]  // result[2] = 1
```

The result becomes:

```text
[1, 2, 1, 0, 0, 0]
```

When `i = 1`, the elements are copied into the second half:

```text
result[1 * 3 + 0] = nums[0]  // result[3] = 1
result[1 * 3 + 1] = nums[1]  // result[4] = 2
result[1 * 3 + 2] = nums[2]  // result[5] = 1
```

The final result is:

```text
[1, 2, 1, 1, 2, 1]
```

Every element is copied into its correct position, and the original vector remains unchanged.

## Step-by-Step Example

Consider:

```text
nums = [1, 3, 2, 1]
```

The original length is:

```cpp
int len = nums.size(); // 4
```

The result vector has eight positions:

```cpp
std::vector<int> result(len * 2);
```

Initially:

```text
[0, 0, 0, 0, 0, 0, 0, 0]
```

### First iteration: `i = 0`

The first copy is written into indices `0` through `3`.

| `j` | Calculation | Assignment |
|---:|---|---|
| 0 | `0 * 4 + 0 = 0` | `result[0] = 1` |
| 1 | `0 * 4 + 1 = 1` | `result[1] = 3` |
| 2 | `0 * 4 + 2 = 2` | `result[2] = 2` |
| 3 | `0 * 4 + 3 = 3` | `result[3] = 1` |

The result becomes:

```text
[1, 3, 2, 1, 0, 0, 0, 0]
```

### Second iteration: `i = 1`

The second copy is written into indices `4` through `7`.

| `j` | Calculation | Assignment |
|---:|---|---|
| 0 | `1 * 4 + 0 = 4` | `result[4] = 1` |
| 1 | `1 * 4 + 1 = 5` | `result[5] = 3` |
| 2 | `1 * 4 + 2 = 6` | `result[6] = 2` |
| 3 | `1 * 4 + 3 = 7` | `result[7] = 1` |

The final result is:

```text
[1, 3, 2, 1, 1, 3, 2, 1]
```

Finally, the function returns the completed vector:

```cpp
return result;
```

## Complexity

### Time Complexity

**O(n)**, where `n` is the length of the original array.

The outer loop executes exactly two times, and the inner loop processes all `n` elements during each iteration.

Therefore, the total number of assignments is:

```text
2 * n = 2n
```

Since constant factors are ignored in Big O notation, the time complexity is O(n).

### Space Complexity

**O(n)**, where `n` is the length of the original array.

The result vector stores `2n` elements.

Although its size is twice the original array's length, the constant factor does not affect the asymptotic complexity.

The additional space complexity is therefore O(n).

## Key Idea

The key idea is to create a result vector twice the size of the input and use index arithmetic to place each element in both halves.

For every element `nums[j]`:

- First copy: `result[j] = nums[j]`
- Second copy: `result[j + len] = nums[j]`

The original implementation combines both operations into a single nested loop using:

```cpp
result[i * len + j] = nums[j];
```

The expression calculates the correct destination index for each copy.

For example, with:

```text
nums = [1, 2, 3]
```

The first copy occupies indices `0`, `1`, and `2`.

The second copy occupies indices `3`, `4`, and `5`.

The result is:

```text
[1, 2, 3, 1, 2, 3]
```

The important observation is that the elements do not need to be sorted, modified, or removed. They simply need to be copied into two consecutive sections of a new array.

This produces the required concatenation in linear time using a straightforward and predictable approach.