#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_0_8()
{

    static int seed_set = 0;
    if(!seed_set)
    {
        srand(time(NULL)); // Seed the random number generator with the current time
        seed_set = 1;
    }
    int random_number = rand() % 9; // Generate a random number from 1 to 9
    return random_number;
}

void printSudoku(int sudoku[9][9],int protection[9][9])
{
    printf("-------------------------\n");
    for (int i = 0; i < 9; i++)
    {
        printf("| ");
        for (int j = 0; j < 9; j++)
        {
            if(protection[i][j]==0)
            {
                if(sudoku[i][j]==0)
                {
                    printf("\033[1;34m");
                    printf("%d ", sudoku[i][j]);
                    printf("\033[1;37m");
                }
                else
                {
                    printf("\033[1;31m");
                    printf("%d ", sudoku[i][j]);
                    printf("\033[1;37m");
                }
            }
            else
            {
                printf("%d ", sudoku[i][j]);

            }

            if ((j + 1) % 3 == 0)
            {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
        {
            printf("-------------------------\n");
        }
    }
}

int findEmptyCell(int sudoku[9][9], int *row, int *col)
{
    for (*row = 0; *row < 9; (*row)++)
    {
        for (*col = 0; *col < 9; (*col)++)
        {
            if (sudoku[*row][*col] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

int solveSudoku(int sudoku[9][9])
{
    int row, col;
    int possibleValues[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Shuffle the possible values array
    for (int i = 0; i < 9; i++)
    {
        int j = random_0_8();
        int temp = possibleValues[i];
        possibleValues[i] = possibleValues[j];
        possibleValues[j] = temp;
    }

    if (!findEmptyCell(sudoku, &row, &col))
    {
        return 1;
    }

    for (int i = 0; i < 9; i++)
    {
        int num = possibleValues[i];

        if (isValid(sudoku, row, col, num))
        {
            sudoku[row][col] = num;

            if (solveSudoku(sudoku))
            {
                return 1;
            }

            sudoku[row][col] = 0;
        }
    }

    return 0;
}

void clear_cells (int sudoku[9][9],int num)
{
    int i=0;

    while (i<num)
    {
        int x=random_0_8();
        int y=random_0_8();
        if (sudoku[x][y]!=0)
        {
            sudoku[x][y]=0;
            i++;
        }
    }
}

void copy_sudoku(int sudoku[9][9],int protection[9][9])
{
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            protection[i][j]=sudoku[i][j];
        }
    }
}

int isValid(int sudoku[9][9], int row, int col, int num)
{

    // Check if the number exists in the same row
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == num)
        {
            return 0;
        }
    }
    // Check if the number exists in the same column
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == num)
        {
            return 0;
        }
    }
    // Check if the number exists in the same 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++)
    {
        for (int j = boxCol; j < boxCol + 3; j++)
        {
            if (sudoku[i][j] == num)
            {
                return 0;
            }
        }
    }
    // If the number is valid, return 1
    return 1;
}

void play (int sudoku[9][9],int protection[9][9])
{
    int x,y,num;
    printf("\nRow number ( from 1 to 9 ) = ");
    scanf("%d",&x);
    fflush(stdin);
    x--;
    printf("\nColumn number ( from 1 to 9 ) = ");
    scanf("%d",&y);
    fflush(stdin);
    y--;
    printf("\nYour solution ( from 1 to 9 ) = ");
    scanf("%d",&num);
    fflush(stdin);
    if (x<0 || x>8 || y<0 || y>8)
    {
        printf("\nInvalid row or column number\n");
        printf("==========================================================\n");
        printSudoku(sudoku,protection);
        return;
    }
    if(num <1 || num>9)
    {
        printf("\nInvalid number\n");
        printf("==========================================================\n");
        printSudoku(sudoku,protection);
        return;
    }
    if (protection[x][y]!=0)
    {
        printf("\nYou can't edit this cell\n");
        printf("==========================================================\n");
        printSudoku(sudoku,protection);
        return;
    }
    if (sudoku[x][y]==num)
    {
        system("cls");
        printSudoku(sudoku,protection);
        return;
    }
    if (isValid(sudoku,x,y,num))
    {
        sudoku[x][y]=num;
        system("cls");
        printSudoku(sudoku,protection);
    }
    else
    {
        printf("\nThis number is repeated in same row or column or 3*3 grid\n");
        printf("==========================================================\n");
        printSudoku(sudoku,protection);
    }
}

int checkSudoku(int sudoku[9][9])
{
    int row, col, num;
    int rowStart, colStart;

    // Check rows
    for (row = 0; row < 9; row++)
    {
        int used[9] = { 0 };
        for (col = 0; col < 9; col++)
        {
            num = sudoku[row][col];
            if (num < 1 || num > 9 || used[num - 1])
            {
                return 0;
            }
            used[num - 1] = 1;
        }
    }

    // Check columns
    for (col = 0; col < 9; col++)
    {
        int used[9] = { 0 };
        for (row = 0; row < 9; row++)
        {
            num = sudoku[row][col];
            if (num < 1 || num > 9 || used[num - 1])
            {
                return 0;
            }
            used[num - 1] = 1;
        }
    }

    // Check squares
    for (rowStart = 0; rowStart < 9; rowStart += 3)
    {
        for (colStart = 0; colStart < 9; colStart += 3)
        {
            int used[9] = { 0 };
            for (row = rowStart; row < rowStart + 3; row++)
            {
                for (col = colStart; col < colStart + 3; col++)
                {
                    num = sudoku[row][col];
                    if (num < 1 || num > 9 || used[num - 1])
                    {
                        return 0;
                    }
                    used[num - 1] = 1;
                }
            }
        }
    }

    return 1;
}

int main()
{
    while (1)
    {
        int sudoku [9][9]= {0};
        int protection [9][9]= {0};
        int num,flag=0;
        system("cls");
start:
        printf("how many numbers to be filled in sudoku gird? (1-80)\n");
        int check=scanf("%d",&num);
        fflush(stdin);
        if(num>80 || num<1 || check==0)
        {
            printf("Invalid input!\n");
            goto start;
        }
        system("cls");
        solveSudoku(sudoku);
        clear_cells(sudoku,(81-num));
        copy_sudoku(sudoku,protection);
        printSudoku(sudoku,protection);
        printf("\ntime to play\n");
        while (flag==0)
        {
            char ans;
            play(sudoku,protection);
            if(checkSudoku(sudoku))
            {
                printf("Congratulations\n");
option:
                printf("\nTo continue press y. To exit press n\n");
                fflush(stdin);
                scanf("%c",&ans);
                fflush(stdin);
                if (ans=='y')
                {
                    flag=1;
                }
                else if(ans=='n')
                {
                    return 0;
                }
                else
                {
                    printf("Invalid choice\n");
                    goto option;
                }
            }
        }
    }
}
