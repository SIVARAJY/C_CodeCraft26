
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rcount = 0;
int critical_count = 0;
int normal_count = 0;
int assigning = 0;
int team_assigned=0;

char rid[10] = "ER000";

struct rescue {
    char Request_id[10];
    char Location[20];
    int people;
    char Emergency[10];
    char Resources[20];
    char status[15];
};

struct rescue records[100];

int compareMulti(const void *a, const void *b) {
    const struct rescue *recordA = (const struct rescue *)a;
    const struct rescue *recordB = (const struct rescue *)b;

    int result = strcmp(recordA->Emergency, recordB->Emergency);

    if (result != 0) {
        return result;
    }

    if (recordA->people > recordB->people)
        return -1;

    if (recordA->people < recordB->people)
        return 1;

    return 0;
}

void increment_string(char *str) {
    int len = strlen(str);

    for (int i = len - 1; i >= 0; i--) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (str[i] < '9') {
                str[i]++;
                return;
            } else {
                str[i] = '0';
            }
        } else {
            break;
        }
    }
}

void registerRequest() {
    if (rcount >= 100) {
        printf("Maximum requests reached!\n");
        return;
    }

    increment_string(rid);

    strcpy(records[rcount].Request_id, rid);

    printf("Enter Location: ");
    scanf("%19s", records[rcount].Location);

    printf("Enter people count: ");
    scanf("%d", &records[rcount].people);

    printf("Emergency Level (critical/normal): ");
    scanf("%9s", records[rcount].Emergency);

    printf("Needed resources: ");
    scanf("%19s", records[rcount].Resources);

    strcpy(records[rcount].status, "Pending");

    if (strcmp(records[rcount].Emergency, "normal") == 0) {
        normal_count++;
    } else if (strcmp(records[rcount].Emergency, "critical") == 0) {
        critical_count++;
    }

    rcount++;

    qsort(records, rcount, sizeof(struct rescue), compareMulti);

    printf("Request registered successfully!\n");
}

void display() {
    if (rcount == 0) {
        printf("No records available.\n");
        return;
    }

    for (int i = 0; i < rcount; i++) {
        printf("\nRequest ID : %s\n", records[i].Request_id);
        printf("Location   : %s\n", records[i].Location);
        printf("People     : %d\n", records[i].people);
        printf("Emergency  : %s\n", records[i].Emergency);
        printf("Resources  : %s\n", records[i].Resources);
        printf("Status     : %s\n", records[i].status);
    }
}

void search() {
    char searchId[10];

    printf("Enter Request ID: ");
    scanf("%9s", searchId);

    for (int i = 0; i < rcount; i++) {
        if (strcmp(records[i].Request_id, searchId) == 0) {
            printf("\nRequest ID : %s\n", records[i].Request_id);
            printf("Location   : %s\n", records[i].Location);
            printf("People     : %d\n", records[i].people);
            printf("Emergency  : %s\n", records[i].Emergency);
            printf("Resources  : %s\n", records[i].Resources);
            printf("Status     : %s\n", records[i].status);
            return;
        }
    }

    printf("Request not found.\n");
}

void summary() {
    printf("\nEmergency Summary\n");
    printf("Critical Pending: %d\n", critical_count);
    printf("Normal Pending  : %d\n", normal_count);
    printf("Team Assigned : %d\n",team_assigned);
}

void assign(){
  
  if (strcmp(records[assigning].Emergency, "normal") == 0) {
        normal_count--;
    } else if (strcmp(records[assigning].Emergency, "critical") == 0) {
        critical_count--;
    }
strcpy(records[assigning].status, "Team send");
  team_assigned++;  

}
int main() {
    int action;
    printf("\n\n--- Emergency Rescue System ---\n");
        printf("1. Register Emergency Request\n");
        printf("2. Display Records\n");
        printf("3. Assign Rescue Team (not implemented)\n");
        printf("4. Search a Request\n");
        printf("5. Generate Emergency Summary\n");
        printf("6. Exit\n");

    while (1) {
        
        printf("Enter your choice: ");

        if (scanf("%d", &action) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (action) {
            case 1:
                registerRequest();
                break;

            case 2:
                display();
                break;

            case 3:
                assign();
                break;

            case 4:
                search();
                break;

            case 5:
                summary();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
