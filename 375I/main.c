/////////////////////////////////////
// File: main.c
// Author: Shaun Rasmusen
// Email: shaunrasmusen@gmail.com
// Date: 2020/04/22
//
// Daily Programmer Challenge #375
//  A Card Flipping Game
//
//  https://old.reddit.com/r/dailyprogrammer/comments/aq6gfy/20190213_challenge_375_intermediate_a_card/
//

#include <stdlib.h>
#include <stdio.h>

int getLength(char* arr);
int solve(int* arr, int len, int* solution);

int main( int argc, char** argv )
{
    char* input = NULL;
    int input_len = 0, i = 0;
    int* input_arr = NULL, *solution = NULL;

    if (argc < 2)
    {
        printf("Usage: %s 011011100\n", argv[0]);
        return 0;
    }

    input = argv[1];
    input_len = getLength(input);
    input_arr = (int*)malloc(sizeof(int) * input_len);
    solution = (int*)malloc(sizeof(int) * input_len);

    i = 0;
    while (*input != 0)
    {
        input_arr[i] = *input - 48;

        input++;
        i++;
    }

    if (solve(input_arr, input_len, solution))
    {
        i = 0;
        for (; i < input_len; i++)
            printf("%d ", solution[i]);
        printf("\n");
    }
    else
        printf("no solution\n");

    free(input_arr);

    return 0;
}

int getLength(char* arr)
{
    int length = 0;
    while (*arr++) length++;
    return length;
}

int solve(int* arr, int len, int* solution)
{
    int i = 0, not_solved = 1;

    for (; i < len; i++)
        printf("%c ", (char)(arr[i] + 48));
    printf("\n");

    i = 0;
    for (; i < len; i++)
    {
        if (arr[i] == 1)
        {
            not_solved = 1;
            arr[i] = -2;
            if (i - 1 >= 0 && arr[i - 1] != -2)
                arr[i - 1] = (arr[i - 1] + 1) % 2;
            if (i + 1 < len && arr[i + 1] != -2)
                arr[i + 1] = (arr[i + 1] + 1) % 2;

            *solution = i;
            solution++;

            not_solved = solve(arr, len, solution);
        }
        else if (arr[i] == 0)
            not_solved = 0;
    }

    return not_solved;
}
