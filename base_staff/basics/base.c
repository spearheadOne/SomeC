//
// Created by abondar on 21.01.16.
//

#include <stdio.h>
#include <string.h>
#include "base.h"
#include <stdlib.h>

#define LOWER 0
#define UPPER 300
#define STEP 20


int main(int argc, char *argv[]) {


    if (argc < 2 ||
        ((strcmp(argv[1], "bc") == 0 || strcmp(argv[1], "mn") == 0) && argc != 3) ||
        (strcmp(argv[1], "dy") == 0 && argc != 5)) {
        fprintf(stderr, "Usage: %s hw|fc|bc number|dy year month day|mn month|fac|ec words\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "hw") && strcmp(argv[1], "fc") &&
        strcmp(argv[1], "bc") && strcmp(argv[1], "dy") &&
        strcmp(argv[1], "mn") && strcmp(argv[1], "fac") && strcmp(argv[1], "ec")) {
        fprintf(stderr, "Unknown demo: %s\n", argv[1]);
        return 1;
    }

    if (strcmp(argv[1],"hw")==0){
        printf("hello world\n");
    }

    if (strcmp(argv[1],"fc")==0){
        farCel();
    }

    if (strcmp(argv[1],"bc")==0){
        long num = strtol(argv[2],NULL,10);

        int a = bitCount(num);
        printf("Number of 1-bits in %ld is: %2d\n",num, a);
    }

    if (strcmp(argv[1],"dy")==0){
        long year = strtol(argv[2],NULL,10);
        int y = (int)year;

        long month = strtol(argv[3],NULL,10);
        int m = (int)month;

        long  day = strtol(argv[4],NULL,10);
        int d = (int)day;

        int day_of_year = dayOfYear(y, m, d);
        if (day_of_year < 0) {
            fprintf(stderr, "Invalid date\n");
            return 1;
        }
        printf("%d %d %d is %d day of year\n",d,m,y, day_of_year);
    }

    if (strcmp(argv[1],"mn")==0){

        long mon= strtol(argv[2],NULL,10);
        int m = (int)mon;

        char *month = month_name(m);
        printf("%s\n", month);
    }

    if (strcmp(argv[1],"ec")==0){
        echo(argc - 1, argv + 1);
    }

    if (strcmp(argv[1],"fac")==0){
        for (int i=0;i< 10;i++){
            printf("Factorial of %d is %2d\n",i,fact(i));

        }

        for (int i=10;i<= 12;i++){
            printf("Factorial of %d is %2d\n",i,factTail(i,1));

        }
    }

    return 0;
}

//print farenheit-celc
void farCel() {
    float cels = 0;

    printf("Farenheit-Celsius table\n");
    for (float fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        cels = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, cels);

    }

}

int bitCount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }
    return b;

}


//set day of year from month and da
int dayOfYear(int year, int month, int day) {
    int i, leap;
    static char dayTab[2][13] = {
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    //non-leap number of days
            {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    //leap number of days

    };
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if (month < 1 || month > 12 || day < 1 || day > dayTab[leap][month])
        return -1;

    for (i = 1; i < month; i++) {
        day += dayTab[leap][i];
    }
    return day;

}

char *month_name(int n) {

    static char *name[] = {
            "Bad month", "January", "February", "March",
            "April", "May", "June", "July", "August", "September",
            "October", "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}

void echo(int argc, char *argv[]) {

    printf("arguments ");
    while (--argc > 0) {
        printf("%s%s", *++argv,(argc>1)? " ":"");
    }
    printf("\n");


}

int fact(int n){
    if (n<0){
        return 0;
    } else if(n==0){
        return 1;
    } else if(n==1){
        return 1;
    } else {
        return n*fact(n-1);
    }

}

int factTail(int n,int a){
    if (n<0){
        return 0;
    } else if(n==0){
        return a;
    } else if(n==1){
        return a;
    } else {
        return factTail(n-1,n*a);
    }
}
