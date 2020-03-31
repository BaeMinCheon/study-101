
---

# Problem: URI Decoding (https://www.algospot.com/judge/problem/read/URI)

### *Description*
URI (Uniform Resource Identifier) is a compact string used to identify or name resources on the Internet. Some examples of URI are below:

- http://icpc.baylor.edu.cn/
- mailto:foo@bar.org
- ftp://127.0.0.1/pub/linux
- readme.txt

When transmitting *URI*s through the Internet, we escape some special characters in *URI*s with percent-encoding. Percent-encoding encodes an ASCII character into a percent sign ("%") followed by a two-digit Hexadecimal representation of the ASCII number. The other characters are not touched in the encoding process. The following table shows the special characters and their corresponding encodings:

Special Character | Encoded String
--- | ---
`" "` | %20
`"!"` | %21
`"$"` | %24
`"%"` | %25
`"("` | %28
`")"` | %29
`"*"` | %2a

Note that the quotes are for clarity only.
Write a program which reverses this process.

### *Input*
The first line of the input file will contain the number of test cases C (1≤C≤100). The following C lines will each contain a test case — which is the percent-encoded URI. Their length will be at most 80.

### *Output*
Print one line for each test cases — the decoded original URI.

### *Example*
Input
```
2
Happy%20Joy%20Joy%21
http://algospot.com/%2a
```
Output
```
Happy Joy Joy!
http://algospot.com/*
```

---

# Solution

### *Design*
- take input as array of string
    - iterate taking input as many as number of testcase
- iterate the array and replace each string with decoded one
    - prepare lookup table for decoding
    (otherwise, brute force with ugly if statements would be needed)
    - create an empty new string for replacing old one
    - iterate the characters of the encoded string to fill the decoded one
        - when the percent-encoding is found, replace 3 characters of old one into 1 character based on lookup table
        - otherwise, just copy characters of old one into new one
- iterate the array and print each string
    - iterate printing each string as many as size of array

### *Code*
look for the `main.cpp` in current directory

### *Note*
- `input: 25%2525%2525` should be `output: 25%25%25`
```
()25%2525%2525
(2)5%2525%2525
2(5)%2525%2525
25(%)2525%2525 -> 25%25%2525
25%(2)5%2525
25%2(5)%2525
25%25(%)2525 -> 25%25%25
25%25%(2)5
25%25%2(5)
25%25%25()
```

---