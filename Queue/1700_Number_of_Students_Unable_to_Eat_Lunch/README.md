# Number of Students Unable to Eat Lunch
## Problem
### Determine how many students are unable to eat lunch.

You are given two integer arrays:

students — represents the preference of each student.
sandwiches — represents the order in which sandwiches are available.

There are two types of sandwiches:

0 — circular sandwich.
1 — square sandwich.

Students form a queue and, at each step, the student at the front takes the sandwich if it matches their preference.

If it does not match, the student goes to the end of the queue.

The process continues until either all students have eaten or the student at the front cannot eat the available sandwich and no other student can eat it either.

The goal is to return the number of students who are unable to eat.

Example
### Input:
students = [1, 1, 0, 0]
sandwiches = [0, 1, 0, 1]

### Output:
0


All students are able to eat a sandwich.

Another example:

students = [1, 1, 1, 0, 0, 1]
sandwiches = [1, 0, 0, 0, 1, 1]

Output:
3


There are three students who are unable to eat.

## Approach

Instead of explicitly simulating the queue, this solution only keeps track of how many students prefer each type of sandwich.

Since there are only two possible preferences, we can use an array with two positions:

std::array<int, 2> swCount = {0, 0};


The indexes represent the sandwich/student types:

swCount[0] -> number of students who prefer type 0
swCount[1] -> number of students who prefer type 1


We first count the students according to their preference:

for (const auto& type : students) {
    swCount[type]++;
}


For example:

students = [1, 1, 0, 0]

swCount:
type 0 -> 2 students
type 1 -> 2 students


We then process the sandwiches in order.

For each sandwich, we check whether there is at least one student who wants that type:

if (swCount[type] == 0) {
    return type == 1 ? swCount[0] : swCount[1];
}


If nobody wants the current sandwich, the process stops.

This is because all remaining students want the other type of sandwich, while the current sandwich is the only one available at the front.

Therefore, no student can eat the current sandwich, and moving students to the back of the queue cannot change the situation.

Processing a Sandwich

If there is a student who wants the current sandwich, we simply decrease the corresponding counter:

swCount[type]--;


For example:

swCount:
type 0 -> 2
type 1 -> 2

sandwich = 1

swCount[1]--

Result:

type 0 -> 2
type 1 -> 1


We do not need to know which specific student eats the sandwich.

Only the number of students with each preference matters.

Why We Don't Need to Simulate the Queue

At first, the problem appears to require a queue simulation because students who cannot eat their current sandwich move to the back.

However, the order of students with the same preference does not matter.

What matters is simply:

How many students want type 0?
How many students want type 1?


Suppose the current sandwich is type 0.

If there is at least one student who wants type 0, eventually one of those students will reach the front and eat it.

If:

swCount[0] == 0


then every remaining student wants type 1.

Since the current sandwich is type 0, nobody can eat it.

Therefore, the number of remaining students can be returned immediately.

This allows us to replace a queue simulation with simple counting.

Step-by-Step Example

Consider:

students = [1, 1, 0, 0]
sandwiches = [0, 1, 0, 1]


First, count the students:

swCount[0] = 2
swCount[1] = 2


The first sandwich is:

0


There are two students who want type 0, so one eats it:

swCount[0] = 1
swCount[1] = 2


Next sandwich:

1


There are students who want type 1:

swCount[0] = 1
swCount[1] = 1


Next:

0


A student who wants type 0 eats it:

swCount[0] = 0
swCount[1] = 1


Finally:

1


The last student wants type 1:

swCount[0] = 0
swCount[1] = 0


All students have eaten, so the function returns:

0

When the Process Stops

Consider:

students = [1, 1, 1, 0, 0, 1]
sandwiches = [1, 0, 0, 0, 1, 1]


Initially:

swCount[0] = 2
swCount[1] = 4


Process the sandwiches:

sandwich = 1
swCount[1] = 3

sandwich = 0
swCount[0] = 1

sandwich = 0
swCount[0] = 0


The next sandwich is:

0


But now:

swCount[0] == 0


There are no students who want type 0.

The only students remaining want type 1:

swCount[1] = 3


Therefore, the process cannot continue and the answer is:

3

## Complexity
Time Complexity

O(n)

The students array is traversed once to count the preferences, and the sandwiches array is traversed once to process the available sandwiches.

Therefore:

O(n) + O(n) = O(n)

Space Complexity

O(1)

The solution uses only a fixed-size array containing two counters:

std::array<int, 2>


Since its size is always 2, the additional space is constant.

## Key Idea

The key idea is to count student preferences instead of simulating the queue.

There are only two possible types:

0 -> circular
1 -> square


So we only need to know:

How many students want 0?
How many students want 1?


For every sandwich:

If someone wants it:
    consume one student of that type

If nobody wants it:
    stop immediately


The critical observation is:

If swCount[type] == 0,


then every remaining student wants the opposite type.

Since the current sandwich is type, nobody can eat it, regardless of how many times the remaining students are moved from the front to the back of the queue.

Therefore, the queue does not actually need to be simulated.

This reduces the problem to a simple counting solution with O(n) time and O(1) extra space.