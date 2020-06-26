
---

# Problem: Flags (https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/)

### *Description*
A non-empty array A consisting of N integers is given.

A peak is an array element which is larger than its neighbours. More precisely, it is an index P such that 0 < P < N − 1 and A[P − 1] < A[P] > A[P + 1].

For example, the following array A:

```
    A[0] = 1
    A[1] = 5
    A[2] = 3
    A[3] = 4
    A[4] = 3
    A[5] = 4
    A[6] = 1
    A[7] = 2
    A[8] = 3
    A[9] = 4
    A[10] = 6
    A[11] = 2
```

has exactly four peaks: elements 1, 3, 5 and 10.

You are going on a trip to a range of mountains whose relative heights are represented by array A, as shown in a figure below. You have to choose how many flags you should take with you. The goal is to set the maximum number of flags on the peaks, according to certain rules.

![](https://codility-frontend-prod.s3.amazonaws.com/media/task_static/flags/static/images/auto/6f5e8faa3000c0a74157e6e0bc759b8a.png)

Flags can only be set on peaks. What's more, if you take K flags, then the distance between any two flags should be greater than or equal to K. The distance between indices P and Q is the absolute value |P − Q|.

For example, given the mountain range represented by array A, above, with N = 12, if you take:

- two flags, you can set them on peaks 1 and 5;
- three flags, you can set them on peaks 1, 5 and 10;
- four flags, you can set only three flags, on peaks 1, 5 and 10.

You can therefore set a maximum of three flags in this case.

Write a function:

```cpp
int solution(vector<int> &A);
```

that, given a non-empty array A of N integers, returns the maximum number of flags that can be set on the peaks of the array.

For example, the following array A:

```
    A[0] = 1
    A[1] = 5
    A[2] = 3
    A[3] = 4
    A[4] = 3
    A[5] = 4
    A[6] = 1
    A[7] = 2
    A[8] = 3
    A[9] = 4
    A[10] = 6
    A[11] = 2
```

the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

- N is an integer within the range [1..400,000];
- each element of array A is an integer within the range [0..1,000,000,000].

---

# Solution

### *Note*
```

"X" : no peak
"P" : yes peak

minimally required SizeOfArray when NumberOfFlags is...
1
X P X => 3
2
X P X P X => 5
3
X P XX P XX P X => 9
4
X P XXX P XXX P XXX P X => 15
5
X P XXXX P XXXX P XXXX P XXXX P X => 23
6
X P XXXXX P XXXXX P XXXXX P XXXXX P XXXXX P X => 33

minimally required SizeOfArray when NumberOfFlags is N: MRS(N)
MRS(N) = MRS(N - 1) + (N - 1)*2 (when N > 1), MRS(1) = 3
MRS(N) = (N - 1)*2 + (N - 2)*2 + (N - 3)*2 + ... + 3*2 + 2*2 + 1*2 + 3 = (N - 1)*(N - 1 + 1) + 3 = (N - 1)*N + 3
∴ MRS(N) = N^2 - N + 3 ≤ N^2 (when N ≥ 3)
<approximation> suppose MRS as MRS(N) = N^2

inverse of MRS: MRS^{-1}
MRS(N) = N^2 ⇔ Y = X^2
Y^{1/2} = X ⇔ X = Y^{1/2}
∴ MRS^{-1}(N) = N^{1/2}
<example> MRS^{-1}(9) = 3, MRS^{-1}(16) = 4

maximally possible NumberOfFlags when SizeOfArray is N: MPN(N)
<approximation> MPN(N) = MRS^{-1}(N) + 1 = N^{1/2} + 1
<example> MPN(8) = 3, MPN(9) = 4, MPN(15) = 4, MPN(16) = 5
```

### *Design*
- calculate peak indices
- calculate max number of flags
- iterate from max number of flags to min number of flags
    - iterate peak indices
        - check whether a flag can be placed in the peak
    - check is this an optimal answer

### *Result*
- https://app.codility.com/demo/results/trainingMDWQHW-Y3X/

### *Code*
- look for the `solution.cpp` in current directory