#include <stdio.h>
#include <stdlib.h>

int table[81];

void printTable() {
    int table_row, table_col;

    for (table_row = 0; table_row < 9; table_row++) {
        for (table_col = 0; table_col < 9; table_col++) {
            printf("%d ", table[table_row * 9 + table_col]);
        }
        printf("\n");   
    }
}

void solve(int table_loc) {
    for (; table_loc < 81; table_loc++) {
        if (table[table_loc] == 0) {
            int i, j;
            int num, remain[9] = {0};

            for (i = 0; i < 9; i++) {
                num = table[table_loc / 9 * 9 + i];
                if (num > 0) {
                    remain[num - 1] = 1;
                }
                
                num = table[table_loc % 9 + i * 9];
                if (num > 0) {
                    remain[num - 1] = 1;
                }
            }
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    num = table[table_loc / 27 * 27 + table_loc % 9 / 3 * 3 + i * 9 + j];
                    if (num > 0) {
                        remain[num - 1] = 1;
                    }
                }
            }
            
            for (i = 0; i < 9; i++) {
                if (!(remain[i])) {
                    table[table_loc] = i + 1;

                    if (table_loc == 80) {
                        printTable();
                        exit(0);
                    } else {
                        solve(table_loc + 1);

                        table[table_loc] = 0;
                    }
                }
            }

            return;
        }
    }
    
    if (table_loc == 81) {
        printTable();
    }
}

int main(void) {
    int table_loc;    
    for (table_loc = 0; table_loc < 81; table_loc++) {
        scanf("%d", &table[table_loc]);
    }

    solve(0);

    return 0;
}