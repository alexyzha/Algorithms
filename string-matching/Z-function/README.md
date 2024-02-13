## Z-Function

The Z-function is used to create an array that, at index "i", contains the **length of the longest suffix starting at index "i" that also matches with a prefix of the same length**. For example:

- Take the string: aabcaabx
- The array we'd get from this string is: [0,1,0,0,3,1,0,0]
- For example, at index 4, there is a suffix "aab". This matches with the 3 letter prefix "aab", so Z[4] = 3.

In order to efficiently generate the Z-table, we use something similar to tabulation. We keep track of the furthest we have explored (variable: right) as well as the beginning of our current window (variable: left).

Right lets us make educated guesses about the Z-value at any index, while Left allows us to access the corresponding character in the prefix.

To begin, we define the variables for the function:
```cpp
//given string s;
int n = s.size();
vector<int> Z(n,0);
int R = 0, L = 0;
```

Then, we iterate through the string and create the Z-table:
```cpp
for(int i = 1; i < n; i++) {
    if(i < R) Z[i] = min(R-i, Z[i-l]);
    while(i + Z[i] < n && s[Z[i]] == s[Z[i]+i]) Z[i]++;
    if(i + Z[i] > R) {
        R = i + Z[i];
        L = i;
    }
}
```

This line:
```cpp
if(i < R) Z[i] = min(R-i, Z[i-l]);
```
Uses the boundaries to make an educated guess about the value of Z[i]. This simply sets a baseline which will be compared later in the while loop.

This while loop:
```cpp
while(i + Z[i] < n && s[Z[i]] == s[Z[i]+i]) Z[i]++;
```
Is what ultimately compares every letter in the string. It pushes the right bound if there are matching letters.

These lines:
```cpp
if(i + Z[i] > R) {
    R = i + Z[i];
    L = i;
}
```
Are what actually change the boundaries if the conditions are met. In the case that there are no matches and i > R, R will increment based on i, as will L.

**Easy.**