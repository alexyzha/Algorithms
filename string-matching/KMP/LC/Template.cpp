#include <vector>
#include <iostream>
using namespace std;

vector<int> KMP_TABLE(const string& comp) {
    int cIt = 0;
    vector<int> table(comp.size(),0);
    for(int i = 1; i < comp.size(); i++) {
        while(comp[i] != comp[cIt]) cIt = table[cIt-1];
        if(comp[i] == comp[cIt]) cIt++;
        table[i] = cIt;
    }
    return table;
}

// explanation
/*
    For every index i in the string being compared:
    cIt tracks the size(index) of the current matching prefix
    For example, for string "abcdabed"
    at index 5, cIt should be 2

    While string[i] doesn't equal string[cIt], set cIt back to the last good prefix match, or, 0.
    for example, at index 6, table[5] = 2, so we get set back to 2. string[3] != string[6], so we get set
    back to table[1], which = 0.

    With the same example, since
    Since string[0] != string[6], we don't increment cIt, and therefore table[6] ends up becoming 0
*/

void KMP_CALCULATION(const string& comp, const string& orig) {
    //declare variables and make table
    int cIt = 0;
    vector<int> table = KMP_TABLE(comp);
    //loop and calculate
    for(int i = 0; i < orig.size(); i++) {
        //when they don't match
        while(cIt > 0 && orig[i] != comp[cIt]) cIt = table[cIt-1];
        //when they do match
        if(orig[i] == comp[cIt]) cIt++;
        if(cIt == comp.size()) {
            //full match found
            //CONDITION HERE
            cIt = table[cIt-1];
        }
    }
    return; //RETURN VALUE
}

// explanation
/*
    the actual calculation bit follows similar logic to the table creation bit
    the table is just already initialized in order to help with processing

    we iterate through the entire length of the original string (not the one being compared)

    while cIt (index counter for compared string) is > 0 and comp[cIt] != orig[i], go back to the last possible
    prefix starter, represented by table[cIt-1]. Will be set back to 0 if no partial match at all

    If orig[i] == comp[cIt], we increment cIt by 1, (comparing next letter in comp to next letter in orig)

    if cIt == comp.size() we've reached the end of the string, and it is valid. We can then set it back to the last
    valid prefix index AGAIN to continue comparing it with orig.
*/