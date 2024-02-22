#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    using schlong = long long;
    int n,s[500005];
    schlong c[500005],m=0,r=0,a=0;
    cin>>n;
    for(int i=0;i<n;++i) { cin>>s[i]; m+=s[i]; }
    if(m%3) cout<<"0\n";
    else {
        m/=3;
        for(int i=n-1;i>=0;--i) {
            r+=s[i];
            if(r==m) c[i]=1;
            else c[i]=0;
        }
        for(int i=n-2;i>=0;--i) c[i]+=c[i+1];
        r=0;
        for(int i=0;i+2<n;++i) {
            r+=s[i];
            if(r==m) a+=c[i+2];
        }
        cout<<a<<endl;
    }
    return 0;
}


/*
first find all suffix sums that add up to m/3
increment count at index (for all occurrences of suffix sum = m/3), otherwise set to 0 to prevent bad memoy
sum up all counts like suffix sum

this gives all the counts for suffixes that sum up to m/3

then, iterate through the array normally to find all the prefixes that add up to m/3
if they do, then taking the suffix sum for the counts array at index i+2 will yield the maximum number
of combinations with prefix ending at index i, and variable 2nd and 3rd partitions
i+2 is needed since i+1 doesn't leave enough room for another partition
*/