
---

# Problem: Triangle (https://app.codility.com/programmers/lessons/6-sorting/triangle/)

### *Description*
An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

- A[P] + A[Q] > A[R],
- A[Q] + A[R] > A[P],
- A[R] + A[P] > A[Q].

For example, consider array A such that:

```
  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
```

Triplet (0, 2, 4) is triangular.

Write a function:

```cpp
int solution(vector<int> &A);
```

that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

For example, given array A such that:

```
  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
```

the function should return 1, as explained above. Given array A such that:

```
  A[0] = 10    A[1] = 50    A[2] = 5
  A[3] = 1
```

the function should return 0.

Write an efficient algorithm for the following assumptions:

- N is an integer within the range [0..100,000];
- each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

---

# Solution

### *Concept*
- sorting the array and pick up 3 elements from the start
    - check whether the elements satisfy the triplet condition

### *Design*
- sort the array
- check the size of array
    - if the size of array is less than 3
        - do nothing
    - else
        - pick up 3 elements from start
        - check whether the elements satisfy the condition

### *Result*
- https://app.codility.com/demo/results/trainingR2HMP5-X8G/

### *Code*
- look for the `solution.cpp` in current directory