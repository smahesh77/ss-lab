#include <stdio.h>

struct process {
    int id, at, bt, tt, wt, rt, ct, status;
} p[20];

int q[100], front = -1, rear = -1;

// Function to enqueue a process in the ready queue
void enqueue(int j) {
    if (front == -1 && rear == -1) front++;
    q[++rear] = j;
}

// Function to dequeue a process from the ready queue
int dequeue() {
    if (front == -1) return -1;
    int item = q[front];
    if (front == rear) front = rear = -1;
    else front++;
    return item;
}

void main() {
    int n, quantum, time = 0, completed = 0, current = 0, i, dequeuedItem = -1, qExpire = 0;
    float avwt = 0, avtt = 0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    printf("\nEnter the Arrival Time and Burst Time:\n");
    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        p[i].status = 0;
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    // Input time quantum for Round Robin
    printf("\nEnter time quantum: ");
    scanf("%d", &quantum);

    while (completed < n) {
        if (dequeuedItem == -1) dequeuedItem = dequeue();

        time++;

        for (i = 0; i < n; i++) {
            // Enqueue processes that have arrived and not marked as completed
            if (p[i].status == 0 && p[i].at <= time) {
                enqueue(i);
                p[i].status = 1;
            }
            enqueue(i);
            p[i].status = 1;
        }

        if (dequeuedItem != -1) {
            if (qExpire != quantum && p[dequeuedItem].rt > 0) {
                p[dequeuedItem].rt--;
                qExpire++;
            }

            if (p[dequeuedItem].rt == 0) {
                // Process has completed its execution
                p[dequeuedItem].ct = time;
                p[dequeuedItem].tt = p[dequeuedItem].ct - p[dequeuedItem].at;
                p[dequeuedItem].wt = p[dequeuedItem].tt - p[dequeuedItem].bt;
                completed++;
                avwt += p[dequeuedItem].wt;
                avtt += p[dequeuedItem].tt;
                dequeuedItem = -1;
                qExpire = 0;
            } else if (qExpire == quantum) {
                // Time quantum expires, enqueue the process again
                enqueue(dequeuedItem);
                dequeuedItem = -1;
                qExpire = 0;
            }
        }
    }

    // Display process details and average turnaround time, average waiting time
    printf("\nPROCESS ID\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tt);
    }

    printf("\n\nAverage Waiting Time: %f", (avwt / n));
    printf("\nAverage Turnaround Time: %f\n", (avtt / n));
}
