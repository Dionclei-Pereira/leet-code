# Reverse Words in a String
## Problem
### Reverse the order of words in a string.

You are given a string s containing words separated by spaces.

The string may contain:

Leading spaces.
Trailing spaces.
Multiple spaces between words.

The goal is to reverse the order of the words while ensuring that:

There is exactly one space between words.
There are no leading spaces.
There are no trailing spaces.

The characters inside each word must remain in the same order.

Example
### Input:
s = "the sky is blue"

### Output:
"blue is sky the"


Another example:

### Input:
s = "  hello world  "

### Output:
"world hello"


Another example:

### Input:
s = "a good   example"

### Output:
"example good a"

## Approach

Instead of manually manipulating the characters in the string, this solution uses stringstream to extract the words.

In C++, stringstream automatically ignores whitespace when using the extraction operator >>.

We first create a string stream:

std::stringstream ss(s);


Then we repeatedly extract words:

std::string word;

while (ss >> word) {
    words.push_back(word);
}


For example, given:

s = "  hello   world  from c++ "


The stringstream extracts:

hello
world
from
c++


The extra spaces are automatically ignored.

We store these words in a vector:

std::vector<string> words;


So the vector becomes:

words = ["hello", "world", "from", "c++"]


We can then traverse the vector backwards to reverse the order of the words.

Building the Result

After extracting all words, we create the result string:

std::string result;


We also reserve enough memory for the final result:

result.reserve(s.size());


This is useful because the final result cannot be larger than the original string.

Why Use reserve()?

std::string is mutable in C++.

Therefore, when we do:

result += words[i];


C++ does not necessarily create a completely new string every time.

The string has an internal buffer with a certain capacity.

If there is enough available capacity, the new characters can simply be appended to the existing buffer.

However, if the capacity is insufficient, the string may need to allocate a larger buffer and move/copy its contents.

By using:

result.reserve(s.size());


we request enough capacity in advance.

This reduces the need for reallocations while building the result.

This is conceptually similar to:

StringBuilder sb = new StringBuilder(s.length());


in Java.

Processing the Words

We traverse the vector from the last word to the first:

for (int i = words.size() - 1; i > 0; i--) {
    result += words[i] + ' ';
}


For example:

words = ["the", "sky", "is", "blue"]


The traversal is:

blue
is
sky
the


The result is built as:

"blue "
"blue is "
"blue is sky "


Finally, we append the first word:

result += words[0];


Giving:

"blue is sky the"


There is no trailing space because the first word is added separately.

Complete C++ Solution
class Solution {
public:
    string reverseWords(string s) {
        std::stringstream ss(s);
        std::vector<string> words;
        std::string word;

        while (ss >> word) {
            words.push_back(word);
        }

        std::string result;
        result.reserve(s.size());

        for (int i = words.size() - 1; i > 0; i--) {
            result += words[i] + ' ';
        }

        result += words[0];

        return result;
    }
};

Java Solution

The same idea can be implemented in Java using trim(), split() and StringBuilder.

First, we remove leading and trailing whitespace and split the string into words:

String[] words = s.trim().split("\\s+");


The expression:

"\\s+"


means one or more whitespace characters.

For example:

s = "  hello   world  "


After:

s.trim()


we get:

"hello   world"


And:

split("\\s+")


produces:

["hello", "world"]


We then use StringBuilder to construct the result:

StringBuilder sb = new StringBuilder(s.length());


The words are processed from right to left:

for (int i = words.length - 1; i > 0; i--) {
    sb.append(words[i] + " ");
}


Finally:

sb.append(words[0]);


The complete solution is:

class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split("\\s+");

        StringBuilder sb = new StringBuilder(s.length());

        for (int i = words.length - 1; i > 0; i--) {
            sb.append(words[i] + " ");
        }

        sb.append(words[0]);

        return sb.toString();
    }
}

Why StringBuilder in Java?

Java's String is immutable.

This means that repeatedly doing:

result = result + word;


can create new string objects as the result grows.

For this reason, StringBuilder is preferable when repeatedly constructing a string:

StringBuilder sb = new StringBuilder();
sb.append(word);


StringBuilder maintains a mutable character buffer that can grow when necessary.

The C++ equivalent is different because std::string is mutable:

string result;
result += word;


Therefore, using += with std::string is not equivalent to repeatedly concatenating immutable Java String objects.

Using:

result.reserve(s.size());


also helps prevent unnecessary reallocations.

Step-by-Step Example

Consider:

s = "  the sky is blue  "


First, we create the stream:

stringstream ss(s);


The stream ignores the unnecessary whitespace.

The extracted words are:

words = ["the", "sky", "is", "blue"]


We then reserve space for the result:

result.reserve(s.size());


Now we traverse the vector backwards.

First:

blue


Result:

"blue "


Next:

is


Result:

"blue is "


Next:

sky


Result:

"blue is sky "


Finally, we append:

the


Result:

"blue is sky the"


The final answer is:

"blue is sky the"

Why We Don't Need to Preserve the Original Spaces

The problem requires the words to be separated by a single space.

Therefore, the original spacing is irrelevant.

For example:

"hello     world"


and:

"  hello world  "


both represent:

["hello", "world"]


After reversing:

"world hello"


The stringstream makes this easier because it automatically treats consecutive whitespace as a separator.

## Complexity
Time Complexity

O(n)

The string is processed to extract all words.

Then, the words are traversed again to build the result.

Therefore:

O(n) + O(n) = O(n)


The total time complexity is:

O(n)

Space Complexity

O(n)

The solution stores all words in:

vector<string> words;


In the worst case, the total size of the stored words is proportional to the input size.

The result string also requires O(n) space.

Therefore, the overall additional space is:

O(n)

## Key Idea

The key idea is to separate the problem into two steps:

Extract the words while ignoring unnecessary whitespace.
Traverse the words backwards to construct the reversed sentence.

In C++, stringstream handles the whitespace:

while (ss >> word) {
    words.push_back(word);
}


Then we reverse the order:

for (int i = words.size() - 1; i > 0; i--) {
    result += words[i] + ' ';
}


Finally:

result += words[0];


The important observation is that we do not need to manipulate the original spaces.

We only care about:

word 1
word 2
word 3
...
word n


and then output them as:

word n
word n-1
...
word 1


The C++ solution uses std::string::reserve() to allocate enough capacity for the result and avoid unnecessary reallocations where possible.

The final solution has:

O(n) time
O(n) space


and provides a simple and readable way to reverse the words in the string.