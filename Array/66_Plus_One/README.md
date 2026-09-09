# Plus One
## Problem
### Add one to the integer represented by an array of digits.

You are given a non-empty integer array digits, where each element represents one digit of a non-negative integer.

The digits are stored from the most significant digit to the least significant digit.

The goal is to add 1 to the represented integer and return the resulting array of digits.

The integer does not contain leading zeros, except for the number 0 itself.

Example
### Input:
digits = [1, 2, 3]

### Output:
[1, 2, 4]


The number represented by the array is:

123


After adding one:

123 + 1 = 124


Therefore, the resulting array is:

[1, 2, 4]

## Approach

The solution starts from the last digit because adding one affects the number from right to left.

For example:

[1, 2, 3]
       ^
     last digit


We first check whether the current digit is smaller than 9.

If it is, we can simply increment it and return the array:

if (digits[i] < 9) {
    digits[i]++;
    return digits;
}


For example:

[1, 2, 3]


The last digit is 3.

Since:

3 < 9


we increment it:

3 + 1 = 4


Result:

[1, 2, 4]


No other digit needs to be changed.

Handling the Carry

The important case happens when the current digit is 9.

For example:

digits = [1, 2, 9]


We cannot simply increment 9 because:

9 + 1 = 10


Therefore, the current digit becomes 0 and the carry must be passed to the digit on the left.

The code handles this with:

digits[i] = 0;


So:

[1, 2, 9]


becomes temporarily:

[1, 2, 0]


Then we continue to the previous digit.

The previous digit is 2, which is smaller than 9.

Therefore:

2 + 1 = 3


Result:

[1, 3, 0]


This represents:

130


which is the correct result of:

129 + 1 = 130

Step-by-Step Example

Consider:

digits = [1, 2, 9]


We start from the last position.

i = 2

The digit is:

9


Since:

9 < 9


is false, we set the digit to 0:

[1, 2, 0]


The carry continues to the left.

i = 1

The digit is:

2


Since:

2 < 9


is true, we increment it:

2 + 1 = 3


Result:

[1, 3, 0]


The solution can now return immediately.

When All Digits Are 9

There is one special case.

Consider:

digits = [9, 9, 9]


We start from the right:

9 -> 0


Result:

[9, 9, 0]


Then:

9 -> 0


Result:

[9, 0, 0]


Finally:

9 -> 0


Result:

[0, 0, 0]


At this point, every digit was 9, so the carry still needs to be represented.

The correct result is:

[1, 0, 0, 0]

### C++

The C++ implementation handles this by inserting 1 at the beginning:

digits.emplace(digits.begin(), 1);
return digits;


Therefore:

[9, 9, 9]


becomes:

[1, 0, 0, 0]

### Java

In Java, instead of modifying the original array, we create a new array with one additional position:

int[] result = new int[digits.length + 1];
result[0] = 1;

return result;


For:

digits = [9, 9, 9]


the new array has size 4:

[1, 0, 0, 0]


All remaining positions are automatically initialized to 0 in Java.

Why Do We Iterate From Right to Left?

When adding one to a number, the addition always starts at the least significant digit.

For example:

  129
+   1
-----
  130


The operation starts with:

9 + 1


which creates a carry.

Then the carry is passed to:

2


and finally to:

1


This is exactly what the reverse loop represents:

for (int i = digits.size() - 1; i >= 0; i--)


The same logic is used in Java:

for (int i = digits.length - 1; i >= 0; i--)

Why Can We Return Immediately?

Whenever we find a digit smaller than 9, we know that there is no longer a carry.

For example:

[4, 5, 6]


The last digit is 6.

We increment it:

[4, 5, 7]


Since there is no carry, all previous digits remain unchanged.

Therefore, we can immediately return:

return digits;


This also makes the algorithm efficient because we do not need to process unnecessary digits.

Another Example

Consider:

digits = [4, 9, 9]


The process is:

9 -> 0


Array:

[4, 9, 0]


Then:

9 -> 0


Array:

[4, 0, 0]


Finally:

4 + 1 = 5


Result:

[5, 0, 0]


This represents:

499 + 1 = 500

The main difference is how the special case where all digits are 9 is handled.

## Complexity
Time Complexity

O(n), where n is the number of digits.

In the worst case, every digit is 9, so the algorithm needs to traverse the entire array.

For example:

[9, 9, 9, 9, 9]


Every digit must be processed.

In the best case, only the last digit needs to be changed:

[1, 2, 3, 4, 5]


Only 5 is processed before the solution returns.

Space Complexity

O(1) auxiliary space for the normal case because the existing array is modified in place.

In the special case where every digit is 9:

C++ inserts an element at the beginning of the vector.
Java creates a new array with one additional position.

The returned result therefore requires O(n) space in that special case.

## Key Idea

The key idea is to simulate the normal addition of 1 from right to left.

For every digit:

If it is smaller than 9:

digit + 1


and we are done.

If it is 9:

9 -> 0


and the carry continues to the next digit on the left.

The process can be summarized as:

If digit < 9:
    Increment digit
    Return

If digit == 9:
    Set digit to 0
    Continue left


If every digit is 9, there is still a carry after processing the entire array, so we need to add a new leading 1.

For example:

[1, 2, 3]


becomes:

[1, 2, 4]


while:

[1, 2, 9]


becomes:

[1, 3, 0]


and:

[9, 9, 9]


becomes:

[1, 0, 0, 0]


The important observation is that only consecutive trailing 9s need to be changed. As soon as we encounter a digit smaller than 9, we increment it and the operation is complete.