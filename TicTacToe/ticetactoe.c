#include <stdio.h>

char matrix[3][3];

int player1(void) {
    int x, y;
    do {
        printf("Enter value for X,Y coordinates Player 1 (0-2 for each): ");
        scanf("%d %d", &x, &y);
        if (x < 0 || x > 2 || y < 0 || y > 2 || matrix[x][y] != ' ') {
            printf("Invalid move! This slot is already filled or out of bounds.\n");
        } else {
            matrix[x][y] = 'X';
            break; 
        }
    } while (1);
    return matrix[x][y];
}

int player2(void) {
    int x, y;
    do {
        printf("Enter value for X,Y coordinates Player 2 (0-2 for each): ");
        scanf("%d %d", &x, &y);
        if (x < 0 || x > 2 || y < 0 || y > 2 || matrix[x][y] != ' ') {
            printf("Invalid move! This slot is already filled or out of bounds.\n");
        } else {
            matrix[x][y] = 'O';
            break; 
        }
    } while (1);
    return matrix[x][y];
}

char checkbox(void) {
    for(int i = 0; i < 3; i++) {
        if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] != ' ') {
            return matrix[i][0];
        }
    }
    for(int i = 0; i < 3; i++) {
        if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] != ' ') {
            return matrix[0][i];
        }
    }
    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] != ' ') {
        return matrix[0][0];
    }
    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] != ' ') {
        return matrix[0][2];
    }

    return ' '; 
}

int main() {
    char done = ' ';
    int i, j;
    printf("WELCOME TO TIC TAC TOE GAME!!\n");

    // Initializing the matrix
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            matrix[i][j] = ' ';
        }
    }

    do {
        // Displaying the matrix
        for(i = 0; i < 3; i++) {
            printf("[%c] [%c] [%c]\n", matrix[i][0], matrix[i][1], matrix[i][2]);
        }

        // Player 1 move
        player1();
        done = checkbox();
        if(done != ' ') {
            break;
        }

        // Player 2 move
        player2();
        done = checkbox();
        if(done != ' ') {
            break;
        }

    } while(done == ' ');

    if(done == 'X') {
        printf("Player 1 (X) wins!\n");
    } else if(done == 'O') {
        printf("Player 2 (O) wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
