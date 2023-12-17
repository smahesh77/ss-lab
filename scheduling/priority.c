#include <stdio.h>

struct process {
    int id, prio, at, bt, ct, tat, wt;
} p[20], temp;

void main() {
    printf("\nEnter number of processes: ");
    int n;
    scanf("%d", &n);

    int check[n]; // To keep track of whether a process is done or not

    printf("\nEnter processes: ");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        check[i] = 0; // Initializing check array
        printf("\nEnter arrival time, burst time, and priority for process P%d: ", p[i].id);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].prio);
    }

    int total_tat = 0;
    int total_wt = 0;
    int sum = 0;
    int done = 0;

    // Sorting processes based on arrival time using Bubble Sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    while (done < n) {
        int high = -1;

        // Selecting the process with the highest priority among arrived processes
        for (int i = 0; i < n; i++) {
            if (p[i].at <= sum && (high == -1 || p[i].prio < p[high].prio) && check[i] == 0) {
                high = i;
            }
        }

        if (high == -1) {
            sum++;
            continue;
        }

        sum += p[high].bt;
        check[high] = 1;
        p[high].ct = sum;
        p[high].tat = p[high].ct - p[high].at;
        total_tat += p[high].tat;
        p[high].wt = p[high].tat - p[high].bt;
        total_wt += p[high].wt;
        done++;
    }

    // Displaying process details and average turnaround time, average waiting time
    printf("\nPno\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Average Turnaround Time: %.2f", (float)total_tat / n);
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
}
