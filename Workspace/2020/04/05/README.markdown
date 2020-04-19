
---

# Problem: Synchronizing Clocks (https://www.algospot.com/judge/problem/read/CLOCKSYNC)

### *Description*
![](http://algospot.com/media/judge-attachments/d3428bd7a9a425b85c9d3c042b674728/clocks.PNG)

그림과 같이 4 x 4 개의 격자 형태로 배치된 16개의 시계가 있다. 이 시계들은 모두 12시, 3시, 6시, 혹은 9시를 가리키고 있다. 이 시계들이 모두 12시를 가리키도록 바꾸고 싶다.

시계의 시간을 조작하는 유일한 방법은 모두 10개 있는 스위치들을 조작하는 것으로, 각 스위치들은 모두 적게는 3개에서 많게는 5개의 시계에 연결되어 있다. 한 스위치를 누를 때마다, 해당 스위치와 연결된 시계들의 시간은 3시간씩 앞으로 움직인다. 스위치들과 그들이 연결된 시계들의 목록은 다음과 같다.

스위치 | 연결되어 있는 시계
--- | ---
0 | 0, 1, 2
1 | 3, 7, 9, 11
2 | 4, 10, 14, 15
3 | 0, 4, 5, 6, 7
4 | 6, 7, 8, 10, 12
5 | 0, 2, 14, 15
6 | 3, 14, 15
7 | 4, 5, 7, 14, 15
8 | 1, 2, 3, 4, 5
9 | 3, 4, 5, 9, 13

시계들은 맨 윗줄부터, 왼쪽에서 오른쪽으로 순서대로 번호가 매겨졌다고 가정하자. 시계들이 현재 가리키는 시간들이 주어졌을 때, 모든 시계를 12시로 돌리기 위해 최소한 눌러야 할 스위치의 수를 계산하는 프로그램을 작성하시오.

### *Input*
첫 줄에 테스트 케이스의 개수 C (<= 30) 가 주어진다.
각 테스트 케이스는 한 줄에 16개의 정수로 주어지며, 각 정수는 0번부터 15번까지 각 시계가 가리키고 있는 시간을 12, 3, 6, 9 중 하나로 표현한다.

### *Output*
각 테스트 케이스당 한 줄을 출력한다. 시계들을 모두 12시로 돌려놓기 위해 눌러야 할 스위치의 최소 수를 출력한다. 만약 이것이 불가능할 경우 -1 을 출력한다.

### *Example*
Input
```
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12 
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
```
Output
```
2
9
```

---

# Solution

### *Design*
- ㅇ

### *Code*
look for the `main.cpp` in current directory

### *Note*
- simulation with example #1

![](https://github.com/BaeMinCheon/study-101/blob/master/Workspace/2020/04/05/Images/01.jpg)

- simulation with example #2

![](https://github.com/BaeMinCheon/study-101/blob/master/Workspace/2020/04/05/Images/02.jpg)


- dependency between clocks and switches

clock | switch
--- | ---
0 | `0, 3, 5`
1 | `0, 8`
2 | `0, 5, 8`
3 | `1, 6, 8, 9`
4 | `2, 3, 7, 8, 9`
5 | `3, 7, 8, 9`
6 | `3, 4`
7 | `1, 3, 4, 7`
8 | `4`
9 | `1, 9`
10 | `2, 4`
11 | `1`
12 | `4`
13 | `9`
14 | `2, 5, 6, 7`
15 | `2, 5, 6, 7`

- simultaneous equations

switch | variable
--- | ---
0 | a
1 | b
2 | c
3 | d
4 | e
5 | f
6 | g
7 | h
8 | i
9 | j

clock | equation
--- | ---
0 | `12 = n#0 + a + d + f`
1 | `12 = n#1 + a + i`
2 | `12 = n#2 + a + f + i`
3 | `12 = n#3 + b + g + i + j`
4 | `12 = n#4 + c + d + h + i + j`
5 | `12 = n#5 + d + h + i + j`
6 | `12 = n#6 + d + e`
7 | `12 = n#7 + b + d + e + h`
8 | `12 = n#8 + e`
9 | `12 = n#9 + b + j`
10 | `12 = n#10 + c + e`
11 | `12 = n#11 + b`
12 | `12 = n#12 + e`
13 | `12 = n#13 + j`
14 | `12 = n#14 + c + f + g + h`
15 | `12 = n#15 + c + f + g + h`

`min(a + b + ... + i + j)/3` is the answer. each equation of clock `#8, #11, #12, #13` has one variable, which means below:

clock | equation #1 | equation #2
--- | --- | ---
8 | `12 = n#8 + e` | `e = 12 - n#8`
11 | `12 = n#11 + b` | `b = 12 - n#11`
12 | `12 = n#12 + e` | `e = 12 - n#12`
13 | `12 = n#13 + j` | `j = 12 - n#13`

※ there is no answer if the equation(s) below is(are) false
- `n#8 = n#12`

now we can update switch-variable table.

switch | variable | value
--- | --- | ---
1 | b | `12 - n#11`
4 | e | `12 - n#8` or `12 - n#12`
9 | j | `12 - n#13`

### iteration #1

clock | equation #1 | equation #2
--- | --- | ---
0 | `12 = n#0 + a + d + f`
1 | `12 = n#1 + a + i`
2 | `12 = n#2 + a + f + i`
3 | `12 = n#3 + (12 - n#11) + g + i + (12 - n#13)` | `n#11 + n#13 - n#3 - 12 = g + i`
4 | `12 = n#4 + c + d + h + i + (12 - n#13)` | `n#13 - n#4 = c + d + h + i`
5 | `12 = n#5 + d + h + i + (12 - n#13)` | `n#13 - n#5 = d + h + i`
6 | `12 = n#6 + d + (12 - n#8)` | `n#8 - n#6 = d`
7 | `12 = n#7 + (12 - n#11) + d + (12 - n#8) + h` | `n#8 + n#11 - n#7 - 12 = d + h`
8 | `12 = n#8 + (12 - n#8)` | Done
9 | `12 = n#9 + (12 - n#11) + (12 - n#13)` | `n#9 - n#11 - n#13 + 12 = 0`
10 | `12 = n#10 + c + (12 - n#8)` | `n#8 - n#10 = c`
11 | `12 = n#11 + (12 - n#11)` | Done
12 | `12 = n#12 + (12 - n#12)` | Done
13 | `12 = n#13 + (12 - n#13)` | Done
14 | `12 = n#14 + c + f + g + h`
15 | `12 = n#15 + c + f + g + h`

※ there is no answer if the equation(s) below is(are) false
- `n#9 - n#11 - n#13 = -12`

switch | variable | value
--- | --- | ---
0 | a
1 | b | `12 - n#11`
2 | c | `n#8 - n#10`
3 | d | `n#8 - n#6`
4 | e | `12 - n#8` or `12 - n#12`
5 | f
6 | g
7 | h
8 | i
9 | j | `12 - n#13`

### iteration #2
clock | equation #1 | equation #2
--- | --- | ---
0 | `12 = n#0 + a + (n#8 - n#6) + f` | `n#6 - n#0 - n#8 + 12 = a + f`
1 | `12 = n#1 + a + i`
2 | `12 = n#2 + a + f + i`
3 | `n#11 + n#13 - n#3 - 12 = g + i`
4 | `n#13 - n#4 = (n#8 - n#10) + (n#8 - n#6) + h + i` | `n#6 + n#10 + n#13 - n#4 - 2*n#8 = h + i`
5 | `n#13 - n#5 = (n#8 - n#6) + h + i` | `n#6 + n#13 - n#5 - n#8 = h + i`
6 | Done
7 | `n#8 + n#11 - n#7 - 12 = (n#8 - n#6) + h` | `n#6 + n#11 - n#7 - 12 = h`
8 | Done
9 | Done
10 | Done
11 | Done
12 | Done
13 | Done
14 | `12 = n#14 + (n#8 - n#10) + f + g + h`
15 | `12 = n#15 + (n#8 - n#10) + f + g + h`

※ there is no answer if the equation(s) below is(are) false
- `n#14 = n#15`
- `n#5 + n#10 = n#4 + n#8`

switch | variable | value
--- | --- | ---
0 | a
1 | b | `12 - n#11`
2 | c | `n#8 - n#10`
3 | d | `n#8 - n#6`
4 | e | `12 - n#8` or `12 - n#12`
5 | f
6 | g
7 | h | `n#6 + n#11 - n#7 - 12`
8 | i
9 | j | `12 - n#13`

### iteration #3
clock | equation #1 | equation #2
--- | --- | ---
0 | `n#6 - n#0 - n#8 + 12 = a + f`
1 | `12 = n#1 + a + i`
2 | `12 = n#2 + a + f + i`
3 | `n#11 + n#13 - n#3 - 12 = g + i`
4 | `n#6 + n#10 + n#13 - n#4 - 2*n#8 = (n#6 + n#11 - n#7 - 12) + i` | `n#7 + n#10 + n#13 - n#4 - 2*n#8 - n#11 + 12 = i`
5 | `n#6 + n#13 - n#5 - n#8 = (n#6 + n#11 - n#7 - 12) + i` | `n#7 + n#13 - n#5 - n#8 - n#11 + 12 = i`
6 | Done
7 | Done
8 | Done
9 | Done
10 | Done
11 | Done
12 | Done
13 | Done
14 | `12 = n#14 + (n#8 - n#10) + f + g + (n#6 + n#11 - n#7 - 12)` | `n#7 + n#10 - n#6 - n#8 - n#11 - n#14 + 24 = f + g`
15 | `12 = n#15 + (n#8 - n#10) + f + g + (n#6 + n#11 - n#7 - 12)` | `n#7 + n#10 - n#6 - n#8 - n#11 - n#15 + 24 = f + g`

switch | variable | value
--- | --- | ---
0 | a
1 | b | `12 - n#11`
2 | c | `n#8 - n#10`
3 | d | `n#8 - n#6`
4 | e | `12 - n#8` or `12 - n#12`
5 | f
6 | g
7 | h | `n#6 + n#11 - n#7 - 12`
8 | i | `n#7 + n#13 - n#5 - n#8 - n#11 + 12` or `n#7 + n#10 + n#13 - n#4 - 2*n#8 - n#11 + 12`
9 | j | `12 - n#13`

### iteration #4
clock | equation #1 | equation #2
--- | --- | ---
0 | `n#6 - n#0 - n#8 + 12 = a + f`
1 | `12 = n#1 + a + (n#7 + n#13 - n#5 - n#8 - n#11 + 12)` | `n#5 + n#8 + n#11 - n#1 - n#7 - n#13 = a`
2 | `12 = n#2 + a + f + (n#7 + n#13 - n#5 - n#8 - n#11 + 12)` | `n#5 + n#8 + n#11 - n#2 - n#7 - n#13 = a + f`
3 | `n#11 + n#13 - n#3 - 12 = g + (n#7 + n#13 - n#5 - n#8 - n#11 + 12)` | `n#5 + n#8 + 2*n#11 - n#3 - n#7 - 24 = g`
4 | Done
5 | Done
6 | Done
7 | Done
8 | Done
9 | Done
10 | Done
11 | Done
12 | Done
13 | Done
14 | `n#7 + n#10 - n#6 - n#8 - n#11 - n#14 + 24 = f + g`
15 | `n#7 + n#10 - n#6 - n#8 - n#11 - n#15 + 24 = f + g`

※ there is no answer if the equation(s) below is(are) false
- `n#2 + n#6 + n#7 + n#13 + 12 = n#0 + n#5 + 2*n#8 + n#11`

switch | variable | value
--- | --- | ---
0 | a | `n#5 + n#8 + n#11 - n#1 - n#7 - n#13`
1 | b | `12 - n#11`
2 | c | `n#8 - n#10`
3 | d | `n#8 - n#6`
4 | e | `12 - n#8` or `12 - n#12`
5 | f
6 | g | `n#5 + n#8 + 2*n#11 - n#3 - n#7 - 24`
7 | h | `n#6 + n#11 - n#7 - 12`
8 | i | `n#7 + n#13 - n#5 - n#8 - n#11 + 12` or `n#7 + n#10 + n#13 - n#4 - 2*n#8 - n#11 + 12`
9 | j | `12 - n#13`

### iteration #5
clock | equation #1 | equation #2
--- | --- | ---
0 | `n#6 - n#0 - n#8 + 12 = (n#5 + n#8 + n#11 - n#1 - n#7 - n#13) + f` | `n#1 + n#6 + n#7 + n#13 - n#0 - n#5 - 2*n#8 - n#11 + 12 = f`
1 | Done
2 | `n#5 + n#8 + n#11 - n#2 - n#7 - n#13 = (n#5 + n#8 + n#11 - n#1 - n#7 - n#13) + f` | `n#1 - n#2 = f`
3 | Done
4 | Done
5 | Done
6 | Done
7 | Done
8 | Done
9 | Done
10 | Done
11 | Done
12 | Done
13 | Done
14 | `n#7 + n#10 - n#6 - n#8 - n#11 - n#14 + 24 = f + (n#5 + n#8 + 2*n#11 - n#3 - n#7 - 24)` | `n#3 + 2*n#7 + n#10 - n#5 - n#6 - 2*n#8 - 3*n#11 - n#14 + 48 = f`
15 | `n#7 + n#10 - n#6 - n#8 - n#11 - n#15 + 24 = f + (n#5 + n#8 + 2*n#11 - n#3 - n#7 - 24)` | `n#3 + 2*n#7 + n#10 - n#5 - n#6 - 2*n#8 - 3*n#11 - n#15 + 48 = f`

※ there is no answer if the equation(s) below is(are) false
- `n#2 + n#6 + n#7 + n#13 + 12 != n#0 + n#5 + 2*n#8 + n#11`

switch | variable | value
--- | --- | ---
0 | a | `n#5 + n#8 + n#11 - n#1 - n#7 - n#13`
1 | b | `12 - n#11`
2 | c | `n#8 - n#10`
3 | d | `n#8 - n#6`
4 | e | `12 - n#8` or `12 - n#12`
5 | f | `n#1 - n#2` or `n#1 + n#6 + n#7 + n#13 - n#0 - n#5 - 2*n#8 - n#11 + 12` or ...
6 | g | `n#5 + n#8 + 2*n#11 - n#3 - n#7 - 24`
7 | h | `n#6 + n#11 - n#7 - 12`
8 | i | `n#7 + n#13 - n#5 - n#8 - n#11 + 12` or `n#7 + n#10 + n#13 - n#4 - 2*n#8 - n#11 + 12`
9 | j | `12 - n#13`

apply the value of example

switch | variable | value | example #1
--- | --- | --- | ---
0 | a | `n#5 + n#8 + n#11 - n#1 - n#7 - n#13` | `6 + 12 + 12 - 6 - 12 - 12 = 0`
1 | b | `12 - n#11` | `12 - 12 = 0`
2 | c | `n#8 - n#10` | `12 - 12 = 0`
3 | d | `n#8 - n#6` | `12 - 12 = 0`
4 | e | `12 - n#8` | `12 - 12 = 0`
5 | f | `n#1 - n#2` | `6 - 6 = 0`
6 | g | `n#5 + n#8 + 2*n#11 - n#3 - n#7 - 24` | `6 + 12 + 24 - 6 - 12 - 24 = 0`
7 | h | `n#6 + n#11 - n#7 - 12` | `12 + 12 - 12 - 12 = 0`
8 | i | `n#7 + n#13 - n#5 - n#8 - n#11 + 12` | `12 + 12 - 6 - 12 - 12 + 12 = 6`
9 | j | `12 - n#13` | `12 - 12 = 0`

switch | variable | value | example #2
--- | --- | --- | ---
0 | a | `n#5 + n#8 + n#11 - n#1 - n#7 - n#13` | `6 + 12 + 9 - 9 - 3 - 12 = 3`
1 | b | `12 - n#11` | `12 - 9 = 3`
2 | c | `n#8 - n#10` | `12 - 12 = 0`
3 | d | `n#8 - n#6` | `12 - 9 = 3`
4 | e | `12 - n#8` | `12 - 12 = 0`
5 | f | `n#1 - n#2` | `9 - 3 = 6`
6 | g | `n#5 + n#8 + 2*n#11 - n#3 - n#7 - 24` | `6 + 12 + 18 - 12 - 3 - 24 = -3` → `12 - 3 = 9`
7 | h | `n#6 + n#11 - n#7 - 12` | `9 + 9 - 3 - 12 = 3`
8 | i | `n#7 + n#13 - n#5 - n#8 - n#11 + 12` | `3 + 12 - 6 - 12 - 9 + 12 = 0`
9 | j | `12 - n#13` | `12 - 12 = 0`