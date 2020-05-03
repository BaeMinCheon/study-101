
---

# Problem: Cyclic Rotation (https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/)

### *Description*
An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

vector<int> solution(vector<int> &A, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

```
    A = [3, 8, 9, 7, 6]
    K = 3
```

the function should return [9, 7, 6, 3, 8]. Three rotations were made:

```
    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
```

For another example, given

```
    A = [0, 0, 0]
    K = 1
```

the function should return [0, 0, 0]

Given

```
    A = [1, 2, 3, 4]
    K = 4
```

the function should return [1, 2, 3, 4]

Assume that:

- N and K are integers within the range [0..100];
- each element of array A is an integer within the range [−1,000..1,000].

In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

---

# Solution

### *Concept*
- find the first index satisfies the condition using `std::set`
    - http://www.cplusplus.com/reference/set/set/
    - `std::set` is implemented as binary search trees

### *Design*
- find unique numbers using `std::set`

```
<example>
Numbers: [0, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6]
Set <- Numbers
Set: {0, 1, 2, 3, 4, 5, 6}
```

- iterate array and erase an element with each equivalent value

```
<example>
foreach Number : Numbers
    if Number is in Set
        remove Number from Set
```

- stop iterating when the set is empty and return the current index

```
<example>
foreach Number : Numbers
    ...
    if Set is empty
        return CurrentIndex
```

- complexity

```
iteration on array: O(N)
searching on set: O(log(N))
∴ O(N*log(N))
```

### *Code*
- look for the `main.cpp` in current directory