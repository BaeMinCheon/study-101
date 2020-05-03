
---

# Problem: Number Of Disc Intersections (https://app.codility.com/programmers/task/number_of_disc_intersections/)

### *Description*
We draw N discs on a plane. The discs are numbered from 0 to N − 1. An array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:

```
    A[0] = 1
    A[1] = 5
    A[2] = 2
    A[3] = 1
    A[4] = 4
    A[5] = 0
```

![](https://codility-frontend-prod.s3.amazonaws.com/media/task_static/number_of_disc_intersections/static/images/auto/0eed8918b13a735f4e396c9a87182a38.png)

There are eleven (unordered) pairs of discs that intersect, namely:

- discs 1 and 4 intersect, and both intersect with all the other discs;
- disc 2 also intersects with discs 0 and 3.

Write a function:

```cpp
int solution(vector<int> &A);
```

that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Write an efficient algorithm for the following assumptions:

- N is an integer within the range [0..100,000];
- each element of array A is an integer within the range [0..2,147,483,647].

---

# Solution

### *Concept*
- iterating sorted points with and accumulating number of pairs
    - there can be two arrays for left and right
    - there should be no duplicated pair

### *Note*
- example

```
A is like:
    A[0] = 1
    A[1] = 5
    A[2] = 2
    A[3] = 1
    A[4] = 4
    A[5] = 0

LeftPoints is like:
    LeftPoints[0] = 0 - 1 = -1
    LeftPoints[1] = 1 - 5 = -4
    LeftPoints[2] = 2 - 2 = 0
    LeftPoints[3] = 3 - 1 = 2
    LeftPoints[4] = 4 - 4 = 0
    LeftPoints[5] = 5 - 0 = 5

RightPoints is like:
    RightPoints[0] = 0 + 1 = 1
    RightPoints[1] = 1 + 5 = 6
    RightPoints[2] = 2 + 2 = 4
    RightPoints[3] = 3 + 1 = 4
    RightPoints[4] = 4 + 4 = 8
    RightPoints[5] = 5 + 0 = 5

sorted LeftPoints: {-4, -1, 0, 0, 2, 5}
sorted RightPoints: {1, 4, 4, 5, 6, 8}
```

iteration | LeftIndex | LeftPoints[LeftIndex] | RightIndex | RightPoints[RightIndex] | Intersections
--- | --- | --- | --- | --- | ---
1 | 0 | -4 | 0 | 1 | 0 + (0 - 0)
2 | 1 | -1 | 0 | 1 | 0 + (1 - 0)
3 | 2 | 0 | 0 | 1 | 1 + (2 - 0)
4 | 3 | 0 | 0 | 1 | 3 + (3 - 0)
5 | 4 | 2 | 0 | 1 | 6
6 | 4 | 2 | 1 | 4 | 6 + (4 - 1)
7 | 5 | 5 | 1 | 4 | 9
8 | 5 | 5 | 2 | 4 | 9
9 | 5 | 5 | 3 | 5 | 9 + (5 - 3)
10 | 6 | X | X | X | 11

### *Design*

- complexity
```
sorting on array: O(N*log(N))
iterating on array: O(N)
∴ O(N*log(N))
```

### *Code*
- look for the `main.cpp` in current directory