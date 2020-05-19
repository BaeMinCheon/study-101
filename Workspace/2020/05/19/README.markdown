
---

# Problem: Passing Cars (https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/)

### *Description*
A non-empty array A consisting of N integers is given. The consecutive elements of array A represent consecutive cars on a road.

Array A contains only 0s and/or 1s:

- 0 represents a car traveling east,
- 1 represents a car traveling west.

The goal is to count passing cars. We say that a pair of cars (P, Q), where 0 ≤ P < Q < N, is passing when P is traveling to the east and Q is traveling to the west.

For example, consider array A such that:

```
  A[0] = 0
  A[1] = 1
  A[2] = 0
  A[3] = 1
  A[4] = 1
```

We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).

Write a function:

```cpp
int solution(vector<int> &A);
```

that, given a non-empty array A of N integers, returns the number of pairs of passing cars.

The function should return −1 if the number of pairs of passing cars exceeds 1,000,000,000.

For example, given:

```
  A[0] = 0
  A[1] = 1
  A[2] = 0
  A[3] = 1
  A[4] = 1
```

the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

- N is an integer within the range [1..100,000];
- each element of array A is an integer that can have one of the following values: 0, 1.

---

# Solution

### *Note*
```
P represents 0
Q represents 1

A = {0, 1, 0, 1, 1}

P = {0, 2}
Q = {1, 3, 4}

PSumUpTo = {1, 1, 2, 2, 2}
QSumUpTo = {0, 1, 1, 2, 3}

PairNumOf[0] = QSumUpTo[4] - QSumUpTo[0] = 3 - 0 = 3
PairNumOf[2] = QSumUpTo[4] - QSumUpTo[2] = 3 - 1 = 2

for Index in P:
	PairNumOf[Index] = QSumUpTo[LastIndex] - QSumUpTo[Index]
```

### *Concept*
- maintaining sum of Q

### *Design*
- store indices indicates P
- store sum of Q upto the index
- iterate with stored indices of P
    - add the difference in range of `[index of P, size of A)`

### *Result*
- https://app.codility.com/demo/results/training2QAMTA-SJY/

### *Code*
- look for the `main.cpp` in current directory