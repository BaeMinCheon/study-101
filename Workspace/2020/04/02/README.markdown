
---

# Problem: N-Queen (https://www.algospot.com/judge/problem/read/NQUEEN)

### *Description*
N-Queen 퍼즐은 N x N 크기의 체스판에 N 개의 퀸을, 서로 공격할 수 없도록 올려놓는 퍼즐이다. (퀸은 체스에서 가장 강력한 기물로, 자신의 위치에서 상하좌우, 그리고 대각선 8방향으로 이어진 직선 상의 어떤 기물도 공격할 수 있다)

예를 들어, 맨 위의 그림은 8x8 크기의 체스판에 8개의 퀸을 서로 공격할 수 없도록 올려놓은 예를 보인다.

체스판의 크기 N 이 주어졌을 때, N-Queen 퍼즐의 답이 모두 몇 개나 되는지를 계산하는 프로그램을 작성하시오. 한 답은 N개 퀸 모두의 위치로 정의되며, 한 퀸의 위치만 다르더라도 다른 답이라고 가정한다.

### *Input*
입력의 첫 줄에는 테스트 케이스의 개수 C 가 주어지며, 그 이후 한 줄에 하나씩 테스트 케이스로 체스판의 크기 N (1 <= N <= 12) 이 주어진다.

### *Output*
각 테스트 케이스마다 한 줄의 답을 출력하며, 주어진 보드 크기에 대해 N-Queen 문제의 답을 출력한다.

### *Example*
Input
```
3
1
2
8
```
Output
```
1
0
92
```

---

# Solution

### *Design*
- iterate the testcases
    - prepare empty board initialized with `0`
    - call the recursive function returns `int` with parameter: first row
    - return the `int` value

```
(recursive function)
- prepare result variable initialized with 0
- iterate its own row
    - try to deploy the queen and continue if it fails
    - if its own row is last row:
        - add 1 to result variable
    - else:
        - call the recursive function with parameter: next row
    - remove the queen has been placed above
- return result variable
```

### *Code*
look for the `main.cpp` in current directory

### *Note*
- simulation #1
```
(input)
1
4

(simulate)
0000 -> 1000 -> 1000 -> 1000 -> 1000 -> 1000 -> 1000 ->
0000    0000    1000    0100    0010    0010    0010
0000    0000    0000    0000    0000    1000    0100
0000    0000    0000    0000    0000    0000    0000

1000 -> 1000 -> 1000 -> 1000 -> 1000 -> 1000 -> 1000 ->
0010    0010    0001    0001    0001    0001    0001
0010    0001    0000    1000    0100    0100    0100
0000    0000    0000    0000    0000    1000    0100

1000 -> 1000 -> 1000 -> 1000 -> 0100 -> 0100 -> 0100 ->
0001    0001    0001    0001    0000    1000    0100
0100    0100    0010    0001    0000    0000    0000
0010    0001    0000    0000    0000    0000    0000

0100 -> 0100 -> 0100 -> 0100 -> 0100 -> 0100 -> 0100 ->
0010    0001    0001    0001    0001    0001    0001
0000    0000    1000    1000    1000    1000    1000
0000    0000    0000    1000    0100    0010    0001

0100 -> 0100 -> 0100 -> 0010 -> 0010 -> 0010 -> 0010
0001    0001    0001    0000    1000    1000    1000
0100    0010    0001    0000    0000    1000    0100
0000    0000    0000    0000    0000    0000    0000

0010 -> 0010 -> 0010 -> 0010 -> ...
1000    1000    1000    1000
0010    0001    0001    0001
0000    0000    1000    0100

then, the deployments below are output:
0100    0010
0001    1000
1000    0001
0010,   0100,   ...
```

---