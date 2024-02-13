## Rabin-Karp

We love hashing yayyyy

I'm going to define the R-K recommended hashing method:
- We use hashing to compare strings and substrings of the same size.
- Say we have a string composed of "n" unique characters.
- This will be our base, base "n".
- We will hash by incrementing and taking powers of "n" for every character in the hashing window.
- That's not very clear, so I will explain it better with examples down below


Say we have 2 strings we want to compare. One is of size "m" with 10 unique characters, and the other one is of size 4, consisting solely of characters used in string 1.
- String 1: B ABCD EFGH IJ ABCABC......
- String 2: ABCD

In order to hash ABCD, we need to determine how many unique characters there will be. There are 10 unique characters: A-J. This means we will be working in base 10. Lets order the numbers the same way they appear in the alphabet: A = 1, B = 2, ... ..., J = 10.
- Starting with the last letter of string 2, "D", we do the operation: D->4, 4 \* 10^0 = 4.
- For "C": C->3, 3 \* 10^1 = 30.
- For "B": B->2, 2 \* 10^2 = 200.
- For "A": A->1, 1 \* 10^3 = 1000.
- Adding them all together gives the hash 1234. This will be unique.

This is the method for hashing.

This is the template for hashing:
```cpp
//given string s, compared string c, number of uniques u
int mod = 1e9+7
int base = u;
int power = 1;
int ORIGINAL_HASH = 0;
int COMPARED_HASH = 0;
int CONDITION;

for(int i = c.size()-1; i >= 0; i--) {
    ORIGINAL_HASH += power * s[i];
    COMPARED_HASH += power * c[i];
    power *= base;
}

//compare first:
if(ORIGINAL_HASH == COMPARED_HASH) CONDITION = CONDITION;

//to "roll" hash
for(int i = c.size(); i < s.size(); i++) {
    ORIGINAL_HASH -= power * s[i-c.size()];
    ORIGINAL_HASH *= base;
    ORIGINAL_HASH += s[i];
    if(ORIGINAL_HASH == COMPARED_HASH) CONDITION = CONDITION;
}

return CONDITION;
```