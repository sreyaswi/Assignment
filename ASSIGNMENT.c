#include <stdio.h>
#include <string.h>

int main() {
    int n, i, time = 0, completed = 0, q;
    int at[50], bt[50], rt[50], wt[50], tat[50], ct[50];
    char pid[50][10];

    float total_wt = 0, total_tat = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%s %d %d", pid[i], &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    scanf("%d", &q);

    while(completed < n) {
        int done = 1;

        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                done = 0;

                if(rt[i] > q) {
                    time += q;
                    rt[i] -= q;
                } 
                else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;

                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    total_wt += wt[i];
                    total_tat += tat[i];
                }
            }
        }

        if(done)
            time++;
    }

    printf("Waiting Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], wt[i]);
    }

    printf("Turnaround Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
