//
// Created by abondar on 23.01.16.
//
#include <stdio.h>
int main() {

    int c, nw, nc, nl, i, nwhite;

    int ndigit[10];
    int in_word = 0;

    nl = nwhite = nc = nw = 0;

    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        nc++;
        if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f') {
            in_word = 0;
        } else if (!in_word) {
            nw++;
            in_word = 1;
        }
        switch (c) {
            case '\n':
                nl++;
                nwhite++;
                break;

            case '\r':
            case '\v':
            case '\f':
            case '\t':
            case ' ':
                nwhite++;
                break;

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
                ndigit[c - '0']++;
                break;

            default:
                break;
        }


    }
    //quite wierd that in console it shows after ctrl-d but in cLion not
    //digits - shows the number of occurence of each digit
    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);

    }

    printf(",white space = %d\n", nwhite);
    printf("Number of lines %d Number of words %d Number of chars %d\n", nl, nw, nc);

    return 0;
}
