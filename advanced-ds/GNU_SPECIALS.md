# GNU C++ has special data policy-based data structures

Ordered set:
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

Standard red-black config, less_equal comparator allows for duplicates (multiset), tree_order_statistics... allows for
functions such as:
order_of_key(x) <––– how many elements are STRICTLY SMALLER than x, (includes duplicates)
*find_by_order(x) <––– returns the index of x
