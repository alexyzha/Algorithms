/*
n  k  l  c   d  p   nl np
3  4  5  10  8  100 3  1

    n = divisor (fren)
    k*l = total ml
    c*d = lime slices
    p = grams of salt
    nl = needed l per person
    np = salt needed per person

find bottleneck
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n,k,l,c,d,p,nl,np,ts,tl,r;
    scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
    ts=c*d,tl=k*l;
    r = min({ts/n,tl/(n*nl),p/(n*np)});
    printf("%d\n",r);
}