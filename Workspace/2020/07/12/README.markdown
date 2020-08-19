
---

# Problem: CountNonDivisible (https://app.codility.com/programmers/lessons/11-sieve_of_eratosthenes/count_non_divisible/)

### *Description*
You are given an array A consisting of N integers.

For each number A[i] such that 0 ≤ i < N, we want to count the number of elements of the array that are not the divisors of A[i]. We say that these elements are non-divisors.

For example, consider integer N = 5 and array A such that:

```
    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 3
    A[4] = 6
```

For the following elements:

- A[0] = 3, the non-divisors are: 2, 6,
- A[1] = 1, the non-divisors are: 3, 2, 3, 6,
- A[2] = 2, the non-divisors are: 3, 3, 6,
- A[3] = 3, the non-divisors are: 2, 6,
- A[4] = 6, there aren't any non-divisors.

Write a function:

```cpp
vector<int> solution(vector<int> &A);
```

that, given an array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.

Result array should be returned as a vector of integers.

For example, given:

```
    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 3
    A[4] = 6
```

the function should return [2, 4, 3, 2, 0], as explained above.

Write an efficient algorithm for the following assumptions:

- N is an integer within the range [1..50,000];
- each element of array A is an integer within the range [1..2 * N].

---

# Solution

### *Design*
- find max element
- count number of each unique element
- iterate all elements
    - iterate all divisors smaller than the element
        - if the divisor can divide the element, count the divisor & quotient
    - check the divisor whose value is square root of the element
        - if the divisor can divide the element, count the divisor
    - save the result by subtracting the count from array size

### *Result*
- https://app.codility.com/demo/results/trainingA7DP7M-9YS/

### *Code*
- look for the `solution.cpp` in current directory