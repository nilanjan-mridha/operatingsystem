#include <stdio.h>

int main() {
  int n, r = 3;
  printf("Inser number of processes: ");
  scanf("%d", &n);

  int allocation[n][3], max[n][3], need[n][3];
  int available[3];
  int finish[n], safeSeq[n], ind = 0;

  printf("\nEnter the Allocation Matrix: (A B C): \n");
  for (int i = 0; i < n; i++) {
    printf("Process P%d: ", i);
    for (int j = 0; j < 3; j++)
      scanf("%d", &allocation[i][j]);
  }

  printf("\nEnter the Max Matrix: (A B C): \n");
  for (int i = 0; i < n; i++) {
    printf("Process P%d: ", i);
    for (int j = 0; j < 3; j++)
      scanf("%d", &max[i][j]);
  }

  printf("\nEnter the available Resources: (A B C): \n");
  for (int j = 0; j < 3; j++) {
    scanf("%d", &available[j]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      need[i][j] = max[i][j] - allocation[i][j];
    }
  }

  printf("\nNeed Matrix\n");
  printf("Process\t A B C\n");
  for (int i = 0; i < n; i++) {
    printf("P%d\t", i);
    for (int j = 0; j < 3; j++) {
      printf("%d ", need[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < n; i++) {
    finish[i] = 0;
  }

  int work[3];
  for (int i = 0; i < 3; i++) {
    work[i] = available[i];
  }

  int flag;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (finish[i] == 0) {
        flag = 0;
        for (int j = 0; j < 3; j++) {
          if (need[i][j] > work[j]) {
            flag = 1;
            break;
          }
        }

        if (flag == 0) {
          safeSeq[ind++] = i;
          for (int y = 0; y < 3; y++) {
            work[y] += allocation[i][y];
          }
          finish[i] = 1;
        }
      }
    }
  }

  int safe = 1;
  for (int i = 0; i < n; i++) {
    if (finish[i] == 0) {
      safe = 0;
      break;
    }
  }

  if (safe == 1) {
    printf("\nThe system is in a SAFE state.\n");
    printf("Safe Sequence: ");
    for (int i = 0; i < n - 1; i++) {
      printf("P%d ", safeSeq[i]);
    }
    printf("P%d\n", safeSeq[n - 1]);
  } else {
    printf("\nThe system is NOT in a safe state.\n");
  }

  return 0;
}
