# Process String
## Problem
### Process a string according to a set of special operations.

You are given a string s containing lowercase English letters and three special characters:

% — reverses the current string.
\* — removes the last character if the string is not empty.
\# — appends a copy of the current string to itself.
Any other character — appends that character to the current string.

The goal is to process the string from left to right and return the final result.

Example
### Input:
s = "a#bc\*%"


The operations are processed from left to right.

Start:

""


Read a:

"a"


Read #:

"aa"


Read b:

"aab"


Read c:

"aabc"


Read *:

"aab"


Read %:

"baa"

### Output:
"baa"

## Approach

The solution maintains the current string in a std::string.

std::string result;


We then process every character of s from left to right:

for (char c : s) {
    switch (c) {
        ...
    }
}


Each character determines which operation should be performed.

Processing Normal Characters

If the character is not one of the special characters, it is simply appended to the result:

default:
    result += c;
    break;


For example:

s = "abc"


The result evolves as:

""
"a"
"ab"
"abc"

Processing %

The % operation reverses the current string.

In C++, this can be done using std::reverse:

std::reverse(result.begin(), result.end());


For example:

result = "abcd"


After %:

"dcba"


The operation modifies the string directly.

Unlike Java's StringBuilder.reverse(), C++ uses the iterators representing the beginning and end of the string:

result.begin()
result.end()


Therefore:

std::reverse(result.begin(), result.end());


reverses the characters in-place.

Processing \*

The \* operation removes the last character if the string is not empty.

In C++, std::string provides pop_back() for exactly this purpose:

if (!result.empty()) {
    result.pop_back();
}


For example:

result = "hello"


After \*:

"hell"


If the string is empty, nothing happens.

result = ""


After \*:

""

Processing #

The # operation appends the current string to itself.

For example:

result = "abc"


After #:

"abcabc"


In C++, this can be written simply as:

result += result;


This is one of the differences from Java.

In Java, the equivalent operation with StringBuilder would be:

sb.append(sb.toString());


because StringBuilder itself is not a String.

In C++, std::string can directly append another std::string:

result += result;

Why We Use std::string Instead of a StringBuilder

Java provides StringBuilder because String is immutable.

For example:

StringBuilder sb = new StringBuilder();


Operations such as:

sb.append(c);
sb.deleteCharAt(...);
sb.reverse();


modify the mutable buffer.

C++ std::string is already mutable.

Therefore, we can directly perform:

result += c;
result.pop_back();
std::reverse(result.begin(), result.end());


There is no separate StringBuilder class required for this implementation.

Reserving Memory

We initialize the result and reserve space based on the input size:

std::string result;
result.reserve(s.length());


This pre-allocates memory for the string.

It can reduce the number of reallocations while characters are being appended.

However, reserve(s.length()) does not guarantee that no reallocations will occur.

The # operation can double the size of the current string:

result += result;


For example:

"a"


becomes:

"aa"


and then:

"aaaa"


and so on.

Therefore, the final string can be significantly larger than the original input.

Step-by-Step Example

Consider:

s = "a#bc\*%"


Initially:

result = ""

Read a

Normal character:

result += 'a';


Result:

"a"

Read #

Duplicate the current string:

result += result;


Result:

"aa"

Read b

Append:

"aab"

Read c

Append:

"aabc"

Read \*

Remove the last character:

"aab"

Read %

Reverse the string:

"baa"


Final result:

"baa"

Complete C++ Solution
class Solution {
public:
    std::string processStr(std::string s) {
        std::string result;
        result.reserve(s.length());

        for (char c : s) {
            switch (c) {
                case '%':
                    std::reverse(result.begin(), result.end());
                    break;

                case '*':
                    if (!result.empty()) {
                        result.pop_back();
                    }
                    break;

                case '#':
                    result += result;
                    break;

                default:
                    result += c;
                    break;
            }
        }

        return result;
    }
};

Java Solution

The same logic can be implemented using StringBuilder:

class Solution {
    public String processStr(String s) {
        StringBuilder sb = new StringBuilder(s.length());

        for (char c : s.toCharArray()) {
            switch (c) {
                case '%':
                    sb.reverse();
                    break;

                case '*':
                    if (sb.length() > 0)
                        sb.deleteCharAt(sb.length() - 1);
                    break;

                case '#':
                    sb.append(sb.toString());
                    break;

                default:
                    sb.append(c);
                    break;
            }
        }

        return sb.toString();
    }
}

## Complexity
Time Complexity

Let n be the length of the input string.

Appending a character is normally O(1) amortized.

Removing the last character is:

O(1)


Reversing the string is:

O(k)


where k is the current length of the string.

The # operation is also:

O(k)


because the current string must be copied to double its size.

Therefore, the total complexity depends heavily on how many % and # operations occur and how large the current string becomes.

A simple upper-bound description is:

O(n + total amount of characters processed by % and #)


In the worst case, repeated # operations can cause the string to grow exponentially, making the total amount of work exponential relative to the input length.

Space Complexity

The result string itself requires space proportional to its current size.

Because # can duplicate the string repeatedly, the final string can be much larger than the input.

Therefore:

O(k)


where k is the size of the final result.

## Key Idea

The key idea is to maintain the current state of the string and apply each operation immediately.

For every character:

Normal character:
    append it

%:
    reverse the string

\*:
    remove the last character

\#:
    duplicate the string


In C++, std::string provides all the operations necessary:

result += c;


for appending,

result.pop_back();


for removing the last character,

std::reverse(result.begin(), result.end());


for reversing,

and:

result += result;


for duplicating the current string.

The important C++ concept is that std::string is mutable, so it can serve the same role that StringBuilder serves in Java for this problem.

The implementation directly simulates the operations from left to right, keeping the current string as the state of the process.