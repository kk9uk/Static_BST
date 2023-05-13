# Data
***ds.txt*** describes a set *S* of *n* integers in the format of one integer per line
> *S* = {25,81,47,23,59} with *n* = 5:  
> 
> 25  
> 81  
> 47  
> 23  
> 59

# Queries
***qry.txt*** has *n* lines, each in the form "**qry** *q*", with *q* being the search value of a predecessor query
> *n* = 5 queries with search values 95, 23, 7, 57, 72 respectively:  
> 
> **qry** 95  
> **qry** 23  
> **qry** 7  
> **qry** 57  
> **qry** 72

# Output
***output.txt*** will be generated (if the predecessor does not exist, "no" is written)
> After processing the aforementioned queries:  
> 
> 81  
> 23  
> no  
> 47  
> 59

# Usage
`./static-BST`
