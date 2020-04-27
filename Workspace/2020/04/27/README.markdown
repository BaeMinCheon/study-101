
---

# Problem: Coin Change (https://www.algospot.com/judge/problem/read/COINS#)

### *Description*
우리 나라에는 10원, 50원, 100원, 500원의 네 가지 동전이 있다. (1원짜리와 5원짜리는 거의 안 쓰니까 없는 걸로 하지요) 이 동전들을 이용해 110원을 거슬러 주는 방법은 몇 가지나 될까? 다음의 네 가지가 있다:

10원 짜리 11개
10원짜리 6개, 50원짜리 1개
10원짜리 1개, 50원짜리 2개
10원짜리 1개, 100원짜리 1개
금액이 커지거나 동전의 종류가 많아질 수록 이 경우의 수는 많아진다. 동전의 종류와 금액이 주어질 때, 해당 동전들을 이용해 해당 금액을 환전하는 방법의 수를 구하는 프로그램을 작성하라.

### *Input*
입력의 첫 줄에는 테스트 케이스의 수 T (1 <= T <= 100) 가 주어진다. 각 테스트 케이스의 첫 줄에는 환전할 금액 M (1 <= M <= 5000) 과 동전 종류의 개수 C (1 <= C <= 100) 가 주어진다. 그 다음 줄에, C 개의 정수로 각 동전 종류별 금액이 주어진다. 동전의 금액은 5000 이하의 자연수이다.

### *Output*
각 테스트 케이스마다, 해당 금액을 환전할 수 있는 경우의 수를 출력한다. 경우의 수가 1000000007 보다 큰 경우, 1000000007 으로 나눈 나머지를 출력한다.

### *Example*
Input
```
4
110 4
10 50 100 500
850 4
10 50 100 500
3600 5
100 300 500 900 2000
1278 8
1 2 4 8 16 32 64 128
```
Output
```
4
110
130
873794561
```

---

# Solution

### *Concept*
- accumulate the number of cases from coins of lower value to coins of higher value

### *Note*
- analyze the example
```
example: {MoneySum: 110}, {Coin: 10, 50, 100, 500}
Coin:  10 -> MoneyToCases[ 10] = 1, MoneyToCases[ 20] = 1, MoneyToCases[ 30] = 1, ...,
	 MoneyToCases[ 90] = 1, MoneyToCases[100] = 1, MoneyToCases[110] = 1
Coin:  50 -> MoneyToCases[ 50] = 2, MoneyToCases[ 60] = 2, MoneyToCases[ 70] = 2, ...,
	 MoneyToCases[ 90] = 2, MoneyToCases[100] = 3, MoneyToCases[110] = 3
Coin: 100 -> MoneyToCases[100] = 4, MoneyToCases[110] = 4
```

- remarkable point
```
from Coin:  50
MoneyToCases[100] -> {10 + 10 + ... + 10} + {10 + 10 + ... + 50} + {50 + 50} -> 3
MoneyToCases[110] -> {10 + 10 + ... + 10} + {10 + 10 + ... + 50} + {10 + 50 + 50} -> 3

from Coin: 100
MoneyToCases[100] -> {10 + 10 + ... + 10} + {10 + 10 + ... + 50} + {50 + 50} + {100} -> 4
MoneyToCases[110] -> {10 + 10 + ... + 10} + {10 + 10 + ... + 50} + {10 + 50 + 50} + {10, 100} -> 4
```

### *Design*
- find the recurrence formula and use it
    - suppose a function `Cases_i(Money)` takes money as parameter and returns the number of cases with `i` th coin
```
with example above
Cases_0(10) = 1
Cases_0(100) = 1
Cases_1(50) = 2
Cases_1(100) = 3
Cases_2(100) = 4
```

- and the function `ValueOf(CoinIndex)` returns the value of coin
```
ValueOf(0) = 10
ValueOf(1) = 50
ValueOf(2) = 100
```

- we can generalize as...
```
Cases_i(Money) = Cases_{i - 1}(Money) + Cases_{i - 1}(Money - ValueOf(i))
```

- in other words...
```
Cases_{i + 1}(Money) = Cases_i(Money) + Cases_i(Money - ValueOf(i + 1))

with example above
Cases_1(50) = Cases_0(50) + Cases_0(0) = 1 + 1 = 2
Cases_1(100) = Cases_0(100) + Cases_0(100 - 50) = 1 + 2 = 3
Cases_2(100) = Cases_1(100) + Cases_1(100 - 100) = 3 + 1 = 4
```

### *Code*
look for the `main.cpp` in current directory