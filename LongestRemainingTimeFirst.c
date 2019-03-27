#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101 // Maximum Size Limit

int N; // Number Of Processess 

// A Structure Consists of :-
// id  :-  Name Of The Process
// at  :-  Arrival Time
// bt  :-  Burest Time
// ft  :-  Finished Time
// st  :-  Starting Time
// wt  :-  Waiting Time
// trt :-  Total TurnAround Time

struct data {
    int num;
    char id[5];
    int at;
    int bt;
    int rt;
    int ft;
    int st;
    int wt;
    int trt;
};

// Variables Which Are Usefull For The PriorityQueue
// fr :- Priority Queue Front
// rr :- Priority Queue Rear

int fr = -1, rr = -1;

// Declaration of Array of Structures

struct data priorityQueue[MAX_SIZE];

// check is a function which put data into the desire position

void check(struct data x) {
    int i, j;
    for (i = 0; i <= rr; i++) {
        if (x.bt > priorityQueue[i].bt) {
            for (j = rr + 1; j > i; j--) {
                priorityQueue[j] = priorityQueue[j - 1];
            }
            priorityQueue[i] = x;
            return;
        }
    }
    priorityQueue[i] = x;
}

// pqPush is a function which push data into the Priority Queue

void pqPush(struct data x) {
    if (fr == -1 && rr == -1) {
        fr++;
        rr++;
        priorityQueue[rr] = x;
        return;
    }
    else {
        check(x);
    }
    rr++;
}

// pqPop is a function which pop out the data from Priority Queue

void pqPop() {
    int i;
    if (fr == -1 && rr == -1) {
        return;
    }
    for (i = 0; i < rr; i++) {
        priorityQueue[i] = priorityQueue[i + 1];
    }
    rr--;
    if (rr == -1)
        fr = -1;
}

// pqEmpty is a function which tell Priority Queue is empty or not

int pqEmpty() {
    return ((fr == -1 && rr == -1));
}

// pqTop is a function which returns the top of the Priority Queue

struct data pqTop() {
    return priorityQueue[fr];
}

int pqSize() {
    return rr - fr;
}

void calculation(struct data p[], int g[], int n) {

    int i, j;
    float avgWt = 0, avgTrt = 0;

    for (i = 0; i < N; i++) {

        for (j = n; j >= 0; j--) {

            if (g[j] == i + 1) {

                p[i].ft = j + 1;
                break;
            }
        }
    }

    for (i = 0; i < N; i++) {

        for (j = 0; j < n; j++) {

            if (g[j] == i + 1) {

                p[i].st = j;
                break;
            }   
        }
    }

    for (i = 0; i < N; i++) {
        
        p[i].wt = p[i].ft - p[i].at - p[i].bt;
        p[i].trt = p[i].wt + p[i].bt;
        avgWt += p[i].wt;
        avgTrt += p[i].trt;
    }

    printf("Id \t ArrivalTime \t BurestTime \t WaitingTime \t TurnAroundTime \n");

    for (i = 0; i < N; i++) {

        printf("%d \t    %d \t\t    %d \t\t    %d \t\t    %d \n", p[i].num, p[i].at, p[i].bt, p[i].wt, p[i].trt);
    }

    avgWt /= N;
    avgTrt /= N;

    printf("\n\n");
    printf("Average Waiting Time And Average Turn Around Time \n\n");

    printf("%f %f", avgWt, avgTrt);

    printf("\n");

}

void sort1(struct data p[]) {
    int i, j, mnInd;
    struct data tmp;
    for (i = 0; i < N - 1; i++) {
        mnInd = i;
        for (j = i + 1; j < N; j++) {
            if (p[j].num < p[mnInd].num)
                mnInd = j;
        }
        tmp = p[i];
        p[i] = p[mnInd];
        p[mnInd] = tmp;
    }
}

void LRT(struct data p[]) {
    int tt = 0;
    tt += p[0].at + p[0].bt;
    for (int i = 1; i < N; i++) {
        if (tt < p[i].at)
            tt = p[i].at;
        tt += p[i].bt;
    }
    int ghart[tt], cpu_state = 0;
    for (int i = 0; i < tt; i++)
        ghart[i] = -1;
    struct data current;
    for (int i = 0 ;i < tt; i++) {
        for (int j = 0; j < N; j++) {
            if (i == p[j].at) {
                pqPush(p[j]);
            }
        }
        if (cpu_state == 0) {
            if (!pqEmpty()) {
                current = pqTop();
                pqPop();
                cpu_state = 1;
            }
        }
        if (cpu_state == 1) {
            current.bt--;
            ghart[i] = current.num;
            if (current.bt == 0) {
                cpu_state = 0;
            }
        }
    }

    for (int i = 0; i < tt; i++)
        printf("%d ", ghart[i]);
    printf("\n");

    sort1(p);

    calculation(p, ghart, tt);
}

void sort(struct data p[]) {
    int i, j, mnInd;
    struct data tmp;
    for (i = 0; i < N - 1; i++) {
        mnInd = i;
        for (j = i + 1; j < N; j++) {
            if (p[j].at < p[mnInd].at)
                mnInd = j;
        }
        tmp = p[i];
        p[i] = p[mnInd];
        p[mnInd] = tmp;
    }
}

// It calculate the average waiting time and average turnaround time


int main() {
    //("%d", &N);
    N = 10;
    struct data p[N];
    int at, bt;
    for (int i = 0; i < N; i++) {
        //scanf("%d%d%d", &p[i].num, &p[i].at, &p[i].bt);
        //p[i].num = i;
        p[i].num = i + 1;
        at = rand() % 10 + 1;
        p[i].at = at;
        bt = rand() % 20 + 1;
        p[i].bt = bt;
    }

    sort(p);

    for (int i = 0; i < N; i++) {
        printf(" %d %d %d \n", p[i].num, p[i].at, p[i].bt);
    }

    LRT(p);

    printf("\n");

    return 0;
}
