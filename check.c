#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "stack.h"

int check_valid_char(char C) {
    char a, b;
    switch (C) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
            break;
        default: {
            printf("Illegal character\n");
            /*printf("Press esc to quit or any other key to continue.\n");
            scanf("%c", &a);
            system("stty -icanon");
            system("stty -echo");
            b = getchar();
            system("stty icanon");
            system("stty echo");
            if (b == 27) exit(0);
            system("clear");*/
            return 1;
        }
    }
    return 0;
}

int check_valid_express(char input[], int len) {
    int stat = 0;
    stack s;
    bool balanced = true;
    init_stack(&s);
    char a, b;
    for (int i = 0; i < len; i++) {
        switch (input[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (i > 0) {
                    /*if (input[i - 1] == '0' || input[i - 1] == '1' || input[i - 1] == '2' ||
                        input[i - 1] == '3' || input[i - 1] == '4' || input[i - 1] == '5' ||
                        input[i - 1] == '6' || input[i - 1] == '7' || input[i - 1] == '8' ||
                        input[i - 1] == '9') {
                        printf("Illegal operand(多位數)\n");
                        stat = 1;
                        printf("Press esc to quit or any other key to continue.\n");
                        scanf("%c", &a);
                        system("stty -icanon");
                        system("stty -echo");
                        b = getchar();
                        system("stty icanon");
                        system("stty echo");
                        if (b == 27) exit(0);
                        system("clear");
                    //continue;
                    }*/
                    if (input[i - 1] == ')') {
                        printf("Right parenthesis followed by an identifier\n");
                        stat = 1;
                        /*printf("Press esc to quit or any other key to continue.\n");
                        scanf("%c", &a);
                        system("stty -icanon");
                        system("stty -echo");
                        b = getchar();
                        system("stty icanon");
                        system("stty echo");
                        if (b == 27) exit(0);
                        system("clear");*/
                        //continue;
                    }
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (i == 0) {
                    printf("First character an operator\n");
                    stat = 1;
                    /*printf("Press esc to quit or any other key to continue.\n");
                    scanf("%c", &a);
                    system("stty -icanon");
                    system("stty -echo");
                    b = getchar();
                    system("stty icanon");
                    system("stty echo");
                    if (b == 27) exit(0);
                    system("clear");*/
                    //continue;
                }
                if (i > 0) {
                    if (i == len - 1) {
                        printf("Last character an operator\n");
                        stat = 1;
                        /*printf("Press esc to quit or any other key to continue.\n");
                    scanf("%c", &a);
                    system("stty -icanon");
                    system("stty -echo");
                    b = getchar();
                    system("stty icanon");
                    system("stty echo");
                    if (b == 27) exit(0);
                    system("clear");*/
                        //continue;
                    }
                    if (input[i - 1] == '+' || input[i - 1] == '-' || input[i - 1] == '*' ||
                        input[i - 1] == '/') {
                        printf("Operator followed by an operator\n");
                        stat = 1;
                        /*printf("Press esc to quit or any other key to continue.\n");
                    scanf("%c", &a);
                    system("stty -icanon");
                    system("stty -echo");
                    b = getchar();
                    system("stty icanon");
                    system("stty echo");
                    if (b == 27) exit(0);
                    system("clear");*/
                        //continue;
                    }
                    if (input[i - 1] == '(') {
                        /*if (input[i + 1] = '0' || input[i + 1] == '1' || input[i + 1] == '2' ||
                            input[i + 1] == '3' || input[i + 1] == '4' || input[i + 1] == '5' ||
                            input[i + 1] == '6' || input[i + 1] == '7' || input[i + 1] == '8' ||
                            input[i + 1] == '9')*/
                        printf("Left parenthesis followed by an operator\n");
                        stat = 1;
                        /*printf("Press esc to quit or any other key to continue.\n");
                    scanf("%c", &a);
                    system("stty -icanon");
                    system("stty -echo");
                    b = getchar();
                    system("stty icanon");
                    system("stty echo");
                    if (b == 27) exit(0);
                    system("clear");*/
                        //continue;
                    }
                }
                break;
            case '(':
                if (i > 0) {
                    if (input[i - 1] == '0' || input[i - 1] == '1' || input[i - 1] == '2' ||
                        input[i - 1] == '3' || input[i - 1] == '4' || input[i - 1] == '5' ||
                        input[i - 1] == '6' || input[i - 1] == '7' || input[i - 1] == '8' ||
                        input[i - 1] == '9') {
                        printf("Identifier followed by a left parenthesis\n");
                        stat = 1;
                        /* printf("Press esc to quit or any other key to continue.\n");
                    scanf("%c", &a);
                    system("stty -icanon");
                    system("stty -echo");
                    b = getchar();
                    system("stty icanon");
                    system("stty echo");
                    if (b == 27) exit(0);
                    system("clear");*/
                        //continue;
                    }
                    if (input[i - 1] == ')') {
                        printf("Right parenthesis followed by a left parenthesis\n");
                        stat = 1;
                        /*printf("Press esc to quit or any other key to continue.\n");
                    scanf("%c", &a);
                    system("stty -icanon");
                    system("stty -echo");
                    b = getchar();
                    system("stty icanon");
                    system("stty echo");
                    if (b == 27) exit(0);
                    system("clear");*/
                        //continue;
                    }
                }

                if (balanced == true)
                    push(&s, input[i]);
                break;
            case ')':
                if (i > 0) {
                    if (input[i - 1] == '+' || input[i - 1] == '-' || input[i - 1] == '*' || input[i - 1] == '/') {
                        printf("Operator followed by a right parenthesis\n");
                        stat = 1;
                        /*printf("Press esc to quit or any other key to continue.\n");
                        scanf("%c", &a);
                        system("stty -icanon");
                        system("stty -echo");
                        b = getchar();
                        system("stty icanon");
                        system("stty echo");
                        if (b == 27) exit(0);
                        system("clear");*/
                        //continue;
                    }
                    if (input[i - 1] == '(') {
                        printf("Left parenthesis followed by a right parenthesis\n");
                        stat = 1;
                        /*printf("Press esc to quit or any other key to continue.\n");
                    scanf("%c", &a);
                    system("stty -icanon");
                    system("stty -echo");
                    b = getchar();
                    system("stty icanon");
                    system("stty echo");
                    if (b == 27) exit(0);
                    system("clear");*/
                        //continue;
                    }
                }

                if (pop(&s) != '(')
                    balanced = false;
                break;
        }
    }
    if (stack_empty(&s) == false)
        balanced = false;

    if (balanced == false) {
        //printf("NOT BALANCED\n");
        if (stack_empty(&s) == true) {
            printf("Unmatched right parenthesis\n");
            stat = 1;
            /*printf("Press esc to quit or any other key to continue.\n");
            scanf("%c", &a);
            system("stty -icanon");
            system("stty -echo");
            b = getchar();
            system("stty icanon");
            system("stty echo");
            if (b == 27) exit(0);
            system("clear");*/
        } else {
            printf("Unmatched left parenthesis\n");
            stat = 1;
            /*printf("Press esc to quit or any other key to continue.\n");
            scanf("%c", &a);
            system("stty -icanon");
            system("stty -echo");
            b = getchar();
            system("stty icanon");
            system("stty echo");
            if (b == 27) exit(0);
            system("clear");*/
        }
    }
    if (stat == 1)
        return 1;
    else
        return 0;
}