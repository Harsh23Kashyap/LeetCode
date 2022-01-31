Given a list of n String S0,S1,S2.... Sn-1. 
S0,S1,S2....Sn-1 

Each String has digits seperated by spaces
Ex. S0= "019 213 314"

There is a key specifying the element on whose basis sorting is to be done.
Ex: key =2 then S0 sorting element will be "213"


There is a reverse value which tells sorted in ascending or descending order.
There is a string which asks whether to sort lexicographically i.e 022<12
or numerically 12<022

Ex:
Input

3                   -n

92 022              -S0

82 012              -S1

77 013              -S3

2                   -key

false               -reverse

numeric             -lexicographic/numeric



Output

82 012

92 022

77 13
