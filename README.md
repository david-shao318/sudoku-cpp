# Sudoku Solver in C++

C++ implementation of basic sudoku solver ([see Python implementation](https://github.com/david-shao318/sudoku)).

## Usage

Input using file input (currently set to 'grid.txt').

Input grid using digits 1 to 9 and 0 for blanks. Newline for each row.

### Sample Input

`grid.txt`

```
040350018
020740000
000000040
003060001
560030070
100400000
030200060
007000009
000680000
```

### Sample Output

```
————Original Sudoku————
   4   | 3 5   |   1 8
   2   | 7 4   |
       |       |   4
-----------------------
     3 |   6   |     1
 5 6   |   3   |   7
 1     | 4     |
-----------------------
   3   | 2     |   6
     7 |       |     9
       | 6 8   |

———Possible Solution———
 7 4 9 | 3 5 2 | 6 1 8
 8 2 6 | 7 4 1 | 5 9 3
 3 1 5 | 8 9 6 | 7 4 2
-----------------------
 4 7 3 | 9 6 5 | 2 8 1
 5 6 2 | 1 3 8 | 9 7 4
 1 9 8 | 4 2 7 | 3 5 6
-----------------------
 9 3 1 | 2 7 4 | 8 6 5 
 6 8 7 | 5 1 3 | 4 2 9 
 2 5 4 | 6 8 9 | 1 3 7

Number of Solutions: 1
Seconds Elapsed: 0.065183
```

Source: New York Times - Hard

Date: July 14, 2021
