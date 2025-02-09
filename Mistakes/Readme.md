------------------------------Process_Over_Results-------------------------------



0. Don't hurry. Write the perfect code at once.
0. Try writing a clean simple running code.
1. Always look for patterns
2. Try thinking for different approaches (dp, binary search, math, graphs, cycle finding) as well
3. multiset.erase(multiset.find(element)) instead of multiset.erase(element)
4. Capital YES (only in codeforces) (Ensure Ouput is in lowercase/uppercase as per the problem)

Varible names
ga = greates_after (suffix array)
gf = greatest_from (suffix array)


Dream Budget Build :)
7600x 	  = 19500
B650M 	  = 11000
RAM(2X16) =  9800
SSD       =  5400
Cooler    =  7400
4070 S    = 57000
PSU   	  =  9100
Cabinet   =  3800
UPS       =  5000
Total 	  =   :(

_________________________________________________________________________________________

imp
1. Understand mkfile
https://github.com/ShivamBohra93/CP-Algo/commit/4ae4d098a527abb5aba35f1f25645a5a73162c23 
(Under Progress)



2. For problems having both 1 based and 0 based indexing, finding a clean coding design, resuable
3. #define int long long save ->read this
4. custom_sqrt alternative
5. dfs direction template
6. dfs on an array (https://atcoder.jp/contests/abc386/tasks/abc386_e)
7. read ioi maths

Complete templates/Generic_Template/debug.cpp


1. Instead of searching for substrings one can use
	str.find(substr) != string::npos, making sure len(substr) <= str


Please Solve More Problems on Multisource bfs and bit manipulations

Solve D in past contests
create a script to give a list of all d of past contest


https://virtual-graph-paper.com/
(Online graph paper)
Can be used in contests


a / b  in modulo is

a * b^(-1)

b^(-1) in Modulo M is b ^ (m - 2) using binanry expo

a / b = a * pow(b, m - 2) using binary expo where m is modulo & prime

Dont get stuck on one technique. Dont enforce DP or graph algo or something 

Make a template for index using lower_bound

While using map, on accessing elements not present will create indexes, and if you reiterate, there will be extra elements having frequency 0

so better use

if (m.count(x)) {
	//you logic here
}