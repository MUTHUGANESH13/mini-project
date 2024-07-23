#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 36

int solved_sudoku(int board[MAX_SIZE][MAX_SIZE], int solutions);
int is_invalid_number(int board[MAX_SIZE][MAX_SIZE], int row, int col);
void print_board(int board[MAX_SIZE][MAX_SIZE]);

int dataTables[MAX_SIZE][MAX_SIZE];
int backupBoard[MAX_SIZE][MAX_SIZE];
int sudoku_board_size = 9, block_size = 3;

void reset_board() {
    sudoku_board_size = 9;
    block_size = 3;
    for (int row = 0; row < MAX_SIZE; row++)
        for (int col = 0; col < MAX_SIZE; col++)
            dataTables[row][col] = 0;
}

void handle_command(char* command) {
    if (strcmp(command, "quit") == 0) {
        printf("Thank you\n\n");
        exit(0);
    } else if (strcmp(command, "help") == 0) {
        printf("\nThis is the help menu. Available commands:\n\n");
        printf("Enter number,number,number - to mark that square with the final number.\n");
        printf("reset - resets the board\n");
        printf("rows number - sets the number of rows\n");
        printf("columns number - sets the number of columns\n");
        printf("solve - solves the entered sudoku problem\n");
        printf("unsolve - restores the recently solved sudoku problem\n");
        printf("quit - exits the program\n");
    } else if (strcmp(command, "reset") == 0) {
        printf("Board has been reset\n");
        reset_board();
        print_board(dataTables);
    } else if (strncmp(command, "solve", 5) == 0) {
        int solutions = solved_sudoku(dataTables, 0);
        if (solutions == -1) {
            printf("\nBroken board.\n");
        } else if (solutions == 0) {
            printf("\nNo solution.\n");
        } else {
            printf("\n%d solution(s).\n", solutions);
        }
    } else if (strncmp(command, "unsolve", 7) == 0) {
        memcpy(dataTables, backupBoard, sizeof(dataTables));
        print_board(dataTables);
    } else if (strncmp(command, "rows", 4) == 0 || strncmp(command, "columns", 7) == 0) {
        int newSize = atoi(command + (command[0] == 'r' ? 5 : 8));
        int tempSize = sudoku_board_size;
        sudoku_board_size = newSize;
        switch (sudoku_board_size) {
            case 4: block_size = 2; break;
            case 9: block_size = 3; break;
            case 16: block_size = 4; break;
            case 25: block_size = 5; break;
            case 36: block_size = 6; break;
            default:
                printf("Rows/columns number must be the square of an integer.\n");
                sudoku_board_size = tempSize;
        }
        print_board(dataTables);
    } else {
        int row, col, val;
        if (sscanf(command, "%d,%d,%d", &row, &col, &val) == 3) {
            if (row <= 0 || col <= 0 || val < 0 || row > MAX_SIZE || col > MAX_SIZE) {
                printf("ERROR, the board is only a max of 36x36.\n");
            } else if (row > sudoku_board_size || col > sudoku_board_size || val > sudoku_board_size) {
                printf("\nOff the board. Input not accepted.\n");
            } else {
                dataTables[row - 1][col - 1] = val; // user not counting from 0
                print_board(dataTables);
            }
        } else {
            printf("Invalid input.\n");
        }
    }
}

int main() {
    char command[80];
    reset_board();
    printf("\n\nWELCOME TO SUDOKU SOLVER\n");
    print_board(dataTables);

    while (1) {
        printf("\nEnter your command: ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';
        handle_command(command);
    }

    return 0;
}

int solved_sudoku(int board[MAX_SIZE][MAX_SIZE], int solutions) {
    int copy[MAX_SIZE][MAX_SIZE];
    memcpy(copy, board, sizeof(copy));

    for (int row = 0; row < sudoku_board_size; row++) {
        for (int col = 0; col < sudoku_board_size; col++) {
            if (copy[row][col] != 0) {
                if (is_invalid_number(copy, row, col)) return -1;
            } else {
                for (int num = 1; num <= sudoku_board_size; num++) {
                    copy[row][col] = num;
                    if (!is_invalid_number(copy, row, col)) {
                        if (solved_sudoku(copy, solutions)) {
                            return solutions;
                        }
                    }
                }
                return 0;
            }
        }
    }

    solutions++;
    if (solutions == 1) {
        memcpy(backupBoard, dataTables, sizeof(dataTables));
        memcpy(dataTables, copy, sizeof(copy));
        print_board(dataTables);
    }
    return solutions;
}

int is_invalid_number(int board[MAX_SIZE][MAX_SIZE], int row, int col) {
    int num = board[row][col];
    for (int i = 0; i < sudoku_board_size; i++) {
        if (i != row && board[i][col] == num) return 1;
        if (i != col && board[row][i] == num) return 1;
    }

    int startRow = (row / block_size) * block_size;
    int startCol = (col / block_size) * block_size;
    for (int i = startRow; i < startRow + block_size; i++) {
        for (int j = startCol; j < startCol + block_size; j++) {
            if ((i != row || j != col) && board[i][j] == num) return 1;
        }
    }

    return 0;
}

void print_board(int board[MAX_SIZE][MAX_SIZE]) {
    for (int row = 0; row <= sudoku_board_size; row++) {
        if (row == 0) {
            printf("\n");
            for (int col = 1; col <= sudoku_board_size; col++) {
                printf(" %2d", col);
            }
        } else {
            printf("\n ");
            for (int col = 1; col <= sudoku_board_size; col++) {
                printf("+---");
            }
            printf("+");
            printf("\n%2d", row);
            for (int col = 1; col <= sudoku_board_size; col++) {
                printf("|");
                if (board[row - 1][col - 1] != 0) {
                    printf(" %2d", board[row - 1][col - 1]);
                } else {
                    printf("   ");
                }
            }
            printf("|");
        }
    }
    printf("\n ");
    for (int col = 1; col <= sudoku_board_size; col++) {
        printf("+---");
    }
    printf("+\n");
}
