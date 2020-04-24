
---

# Problem: Traveling Salesman Problem 1 (https://www.algospot.com/judge/problem/read/TSP1)

### *Description*
NP-Complete 문제의 가장 유명한 예 중 하나인 여행하는 외판원 문제 (Traveling Salesman Problem) 은, 여러 개의 도시와 그 도시 간의 거리가 주어졌을 때, 각 도시를 정확히 한 번씩 방문하는 가장 짧은 경로를 찾는 문제이다. 이 문제를 다항 시간에 해결할 수 있는 방법은 현재까지는 존재하지 않지만, 도시의 숫자가 작은 경우에는 비교적 사용 가능한 시간 안에 문제를 해결할 수 있다.

AOJ 에서 이 문제는 같은 내용을 가진 문제 여러 개로 구성된다. 문제 번호에 비례해 도시의 개수가 올라가므로, 뒤로 갈수록 더욱 효율적인 방법을 써야 해결할 수 있다.

도시의 수 N <= 8 이라고 할 때, 여행하는 외판원 문제를 해결하는 프로그램을 작성하라.

### *Input*
입력의 첫 줄에는 테스트 케이스의 수 C (<= 50) 이 주어진다. 각 테스트 케이스의 첫 줄에는 도시의 수 N (3 <= N <= 8) 이 주어진다. 그 후 N 줄에, 각 N 개씩의 실수로 도시간의 거리가 주어진다. 도시들은 1 부터 N 까지의 숫자로 표현되며, i 번째 줄의 j 번째 실수는 i번째 도시와 j번째 도시 사이의 거리이다. 각 거리는 0 이상 1415 이하이고, 소수점 밑 열 자리까지 주어진다.

주어진 행렬은 대칭이며, 입력되는 거리들은 삼각 부등식 (triangle inequality) 을 만족한다고 가정해도 좋다.

### *Output*
테스트 케이스마다 한 줄에 최소 경로의 길이를 소수점 밑 열 자리까지 출력한다. 1e-7 이하의 절대/상대 오차가 있어도 맞는 답으로 인정한다.

### *Example*
Input
```
2
3
0.0000000000  611.6157225201  648.7500617289
611.6157225201  0.0000000000  743.8557967501
648.7500617289  743.8557967501  0.0000000000
4
0.0000000000  326.0008994586  503.1066076077  290.0250922998
326.0008994586  0.0000000000  225.1785728436  395.4019367384
503.1066076077  225.1785728436  0.0000000000  620.3945520632
290.0250922998  395.4019367384  620.3945520632  0.0000000000
```
Output
```
1260.3657842490
841.2045646020
```

---

# Solution #1

### *Concept*
- find the answer with full search

### *Note*
- iterate cities as a starting point
    - city #0
        - city #1
            - city #2
                - ...
            - ...
        - city #2
            - ...
    - city #1
        - ...
    - ...

![](https://github.com/BaeMinCheon/study-101/blob/master/Workspace/2020/04/19/Images/01.jpg)

- city #0
    - city #1
        - city #2 → `(0 -> 1 -> 2)`
    - city #2
        - city #1 → `(0 -> 2 -> 1)`
- city #1
    - city #0
        - city #2 → `(1 -> 0 -> 2) = 1260.3657842490`
    - city #2
        - city #0 → `(1 -> 2 -> 0)`
- city #2
    - city #0
        - city #1 → `(2 -> 0 -> 1) = 1260.3657842490`
    - city #1
        - city #0 → `(2 -> 1 -> 0)`

![](https://github.com/BaeMinCheon/study-101/blob/master/Workspace/2020/04/19/Images/02.jpg)

- city #0
    - city #1
        - city #2
            - city #3 → `(0 -> 1 -> 2 -> 3)`
        - city #3
            - city #2 → `(0 -> 1 -> 3 -> 2)` 
    - city #2
        - city #1
            - city #3 → `(0 -> 2 -> 1 -> 3)` 
        - city #3
            - city #1 → `(0 -> 2 -> 3 -> 1)` 
- city #1
    - ...
- city #2
    - city #0
        - ...
    - city #1
        - city #0
            - city #3 → `(2 -> 1 -> 0 -> 3) = 841.2045646020`
        - ...
    - ...
- ...

### *Design*
- iterate with number of push on each switch and recur with number of switches
```cpp
double GetAnswer()
{
    double ReturnValue = std::numeric_limits<double>::max();
    ...
    for (int Index = 0; Index < Testcase.size(); ++Index)
    {
        ...
    }
    return ReturnValue;
}

double GetAnswerRecursive(...)
{
    double ReturnValue = std::numeric_limits<double>::max();
    ...
    return ReturnValue;
}
```

- prevent the overhead of creating container object
    - focus on the parameter of `GetAnswerRecursive`
```cpp
double GetAnswerRecursive(std::vector<bool>& VisitTable, int CityFrom)
{
    double ReturnValue = std::numeric_limits<double>::max();
    VisitTable[CityFrom] = true;
    ...
    VisitTable[CityFrom] = false;
    return ReturnValue;
}
```

### *Code*
look for the `main.cpp` in current directory with first commit

### *Limitation*
it happens `Time Out` due to brute force

---

# Solution #2

### *Concept*
- improve `Solution #1` with pruning

### *Note*
suppose an example...
- city #0
    - city #1
        - city #2 → `500.000`
    - ...
- city #1
    - city #0 → `600.000`
        - do not have to search this branch (pruning)
- ...

### *Design*
- ( in comparison to `Solution #1` ) add parameters for pruning
```cpp
double GetAnswer()
{
    double ReturnValue = std::numeric_limits<double>::max();
    std::vector<bool> VisitTable(Testcase.size(), false);
    for (int Index = 0; Index < Testcase.size(); ++Index)
    {
        double Value = GetAnswerRecursive(VisitTable, Index,
        /*Threshold*/ ReturnValue, /*AccumulatedValue*/ 0.0);
        ReturnValue = std::min(Value, ReturnValue);
    }
    return ReturnValue;
}

double GetAnswerRecursive(std::vector<bool>& VisitTable, int CityFrom, double Threshold, double AccumulatedValue)
{
    double ReturnValue = std::numeric_limits<double>::max();
    VisitTable[CityFrom] = true;
    ...
    else if (AccumulatedValue > Threshold)
    {
        // do nothing
    }
    ...
    VisitTable[CityFrom] = false;
    return ReturnValue;
}
```

### *Code*
look for the `main.cpp` in current directory with second commit