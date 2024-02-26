/*
10 4
1 8 4 10 2 7 5 9 3 6
        +1-1+1-1+1-1

23 from 55/10*4 + 1

1 2 3 | 4 5 | 6 7 8 | 9 10
partitioned like that because:
(1) 2 3
(8) 7 6
(4) 5
(10) 9

1 8 4 10             23
  8 4 10 2           24
    4 10 2 7         23
      10 2 7 5       23
         2 7 5 9     23
           7 5 9 3   24
             5 9 3 6 23



N IS ALWAYS EVEN BECAUSE
of adding n(max)+1 adds 0.5 from avg for some reason?

91/13+1 -> 28 STARTING

4 10 1 13  5 9 2 12  6 8 3 11  7
          +1-1+1-1  +1-1+1-1  +1

1 2 3 | 4 5 6 | 7 | 8 9 10 | 11 12 13

15 4

1 12 4 15
1 2 3 4 | 5 6 7 8 | 9 10 11 12 | 13 14 15
1 12 5 15 | 2 11 6 14 | 3 10 7 13 | 4 9 8

** n patitions
** essentially:
** partition base size is length/n
** if length%n > 0, then go through and add 1 to each partition size

13, 4
1 2 3 4 | 5 6 7 | 8 9 10 | 11 12 13
> 1 10 5 13 | 2 9 6 12 | 3 8 7 11 | 4

4 10 1 13                     
  10 1 13 5                   
     1 13 5 9                 
       13 5 9 2
          5 9 2 12
            9 2 12 6
              2 12 6 8
                12 6 8 3
                   6 8 3 11
                     8 3 11 7
*/
#include <iostream>
#include <vector>
using namespace std;

int ptn[200005] = {0}, sz[200005] = {1};

int main() {
    int t, n, k; cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> r(n,0);
        for(int i = 0, o = 1, e = n; i < k; ++i) {
            for(int j = i; j < n; j+=k) {
                r[j] = (i&1) ? e-- : o++;
            }
        }
        for(auto& i : r) cout << i << " ";
        cout << endl;
    }
    return 0;
}
/*
what about 3,2?
n partitions, 2 partitions
1 2 3

1 | 2 ...

3%2 = 1, +1 to partition 1's size

Therefore partitions are:
1 2 | 3

start with: 1 3 | 2
exact ans as given
*/