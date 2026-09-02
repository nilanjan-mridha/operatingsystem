#include <stdio.h>

int main() {
  int n, tq;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  int at[n], bt[n], rem_bt[n];
  int ct[n], tat[n], wt[n], rt[n];
  int visited[n];

  printf("Enter AT and BT of each process:\n");

  for (int i = 0; i < n; i++) {
    printf("P%d AT BT: ", i + 1);
    scanf("%d %d", &at[i], &bt[i]);

    rem_bt[i] = bt[i];
    rt[i] = -1;
    visited[i] = 0;
  }

  printf("Enter time quantum: ");
  scanf("%d", &tq);

  int queue[1000];
  int front = 0, rear = 0;

  int time = 0;
  int completed_count = 0;

  int first = -1;

  for (int i = 0; i < n; i++) {
    if (at[i] <= time) {
      first = i;
      break;
    }
  }

  if (first == -1) {
    time = at[0];
    first = 0;

    for (int i = 1; i < n; i++) {
      if (at[i] < time) {
        time = at[i];
        first = i;
      }
    }
  }

  queue[rear++] = first;
  visited[first] = 1;

  while (completed_count < n) {

    if (front == rear) {
      int next = -1;

      for (int i = 0; i < n; i++) {
        if (rem_bt[i] > 0 && !visited[i]) {
          if (next == -1 || at[i] < at[next]) {
            next = i;
          }
        }
      }

      if (next != -1) {
        time = at[next];
        queue[rear++] = next;
        visited[next] = 1;
      }
    }

    int p = queue[front++];

    if (rt[p] == -1) {
      rt[p] = time - at[p];
    }

    int execute;

    if (rem_bt[p] > tq)
      execute = tq;
    else
      execute = rem_bt[p];

    time += execute;
    rem_bt[p] -= execute;

    for (int i = 0; i < n; i++) {
      if (!visited[i] && at[i] <= time) {
        queue[rear++] = i;
        visited[i] = 1;
      }
    }

    if (rem_bt[p] == 0) {
      ct[p] = time;
      completed_count++;
    } else {
      queue[rear++] = p;
    }
  }

  float avg_tat = 0;
  float avg_wt = 0;
  float avg_rt = 0;

  for (int i = 0; i < n; i++) {
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];

    avg_tat += tat[i];
    avg_wt += wt[i];
    avg_rt += rt[i];
  }

  avg_tat /= n;
  avg_wt /= n;
  avg_rt /= n;

  printf("\nProcess\tAT\tBT\tCT\tTAT\tRT\tWT\n");

  for (int i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i],
           rt[i], wt[i]);
  }

  printf("\nAverage TAT = %.2f\n", avg_tat);
  printf("Average WT  = %.2f\n", avg_wt);
  printf("Average RT  = %.2f\n", avg_rt);

  return 0;
}
