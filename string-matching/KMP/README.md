## KMP Algorithm

For finding the matching substrings while skipping obvious mismatches.

Skip backwards to the last matching possible substring before checking again. For example:

abe abe abe abc abc

              ^

        abc abe

Say we're here: abc. The string we want to find occurrences of is "abe". "abe" != "abc", so we jump back to the last possible index for a substring match (found from the second "b", or table[4]). because there is another "b" at index 1, this is what table[4] equals. Therefore we jump back to the first be to check if the substring "ab"(+"c") = "abc". It does, so we move on.

That was the general logic for the algorithm.

Template:
```cpp
int CONDITION;
//given string s, compared string c
vector<int> table(c.size(),0);
int cPtr = 0;
//setting table
for(int i = 1; i < c.size(); i++) {
    while(cPtr > 0 && c[cPtr] != c[i]) cPtr = table[cPtr-1];
    if(c[cPtr] == c[i]) cPtr++;
    table[i] = cPtr;
}
//calculations
cPtr = 0;
for(int i = 0; i < s.size(); i++) {
    while(cPtr > 0 && c[cPtr] != s[i]) cPtr = table[cPtr-1];
    if(c[cPtr] == s[i]) cPtr++;
    if(cPtr == c.size()) {
        CONDITION = CONDITION;
        cPtr = table[cPtr-1];
    }
}

return CONDITION;
```
