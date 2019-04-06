# OS-Project

## 1. Mutli Level Queue

```
Design a scheduling program to implements a Queue with two levels:
Level 1 : Fixed priority preemptive Scheduling
Level 2 : Round Robin Scheduling
For a Fixed priority preemptive Scheduling (Queue 1), the Priority 0 is highest priority. If one 
process P1 is scheduled and running , another process P2 with higher priority comes. The New process 
(high priority) process P2 preempts currently running process P1 and process P1 will go to 
second level queue. Time for which process will strictly execute must be considered in the multiples 
of 2.. All the processes in second level queue will complete their execution according to round robin
scheduling.
Consider: 
1. Queue 2 will be processed after Queue 1 becomes empty.
2. Priority of Queue 2 has lower priority than in Queue 1.
```

### Sample Input

```
3
p1 0 3 3
p2 0 3 2
p3 0 4 1
```
### Sample Output

```
Ghant Chart
p1 p2 p3 p3 p3 p3 p2 p2 p1 p1

Id ArrivalTime BurestTime WaitingTime TurnAroundTime
p1     0            3          5           8
p2     1            3          6           9
p3     2            4          0           4

Average waiting time and total turn around time
3.666667 7.000000

```

## Longest Remaining First

```
Ten students (a,b,c,d,e,f,g,h,i,j) are going to attend an event. There are lots of gift shops, they 
all are going to the gift shops and randomly picking the gifts. After picking the gifts they are 
randomly arriving in the billing counter. The accountant gives the preference to that student who 
has maximum number of gifts. Create a C or Java program to define order of billed students?
```
### Sample Input

```
Randomly generated by compiler
7 1 20
9 1 7
6 3 8
10 3 17
3 4 16
1 4 7
8 4 7
4 7 13
2 8 16
5 10 2
```
### Sample Output

```
Ghart Chart
-1 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 4 4 4 4 4 4 4 4 4 4 4 4 4
6 6 6 6 6 6 6 6 9 9 9 9 9 9 9 1 1 1 1 1 1 1 8 8 8 8 8 8 8 5 5

Id ArrivalTime BurestTime WaitingTime TurnAroundTime
1      4          7            94          101
2      8          16           46          62
3      4          16           34          50
4      7          13           63          76
5      10         2            102         104
6      3          8            80          88
7      1          20           0           20
8      4          7            101         108
9      1          7            90          97
10     3          17           18          35

Average Waiting Time and Average Total Turn Around Time

62.799999 74.099999
```




