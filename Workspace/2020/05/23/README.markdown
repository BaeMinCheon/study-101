
---

# Problem: Max Product Of Three (https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/)

### *Description*
A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:

```
  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
```

contains the following example triplets:

- (0, 1, 2), product is −3 * 1 * 2 = −6
- (1, 2, 4), product is 1 * 2 * 5 = 10
- (2, 4, 5), product is 2 * 5 * 6 = 60

Your goal is to find the maximal product of any triplet.

Write a function:

```cpp
int solution(vector<int> &A);
```

that, given a non-empty array A, returns the value of the maximal product of any triplet.

For example, given array A such that:

```
  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
```

the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Write an efficient algorithm for the following assumptions:

- N is an integer within the range [3..100,000];
- each element of array A is an integer within the range [−1,000..1,000].

---

# Solution

### *Concept*
- sorting the array and pick up 3 elements from each edge → total 6 elements
    - pick up all elements when the size of array is less than 6

### *Design*
- sort the array
- check the size of array
    - if the size of array is less than 6
        - pick up all elements
    - else
        - pick up 3 elements from each edge
- iterate the elements
    - iterate the elements
        - iterate the elements
            - calculate tuple
            - compare with max value

### *Result*
- https://app.codility.com/demo/results/trainingQ2AFU3-CGQ/

### *Code*
- look for the `solution.cpp` in current directory