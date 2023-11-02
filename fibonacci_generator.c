#include <stdio.h>
#include <stdlib.h>

typedef long int LONG;

LONG fibonacci_generator(int, int);
void showUsage(char*);

int main(int argc, char *argv[]){
    int n, verbose;

    if(argc >= 2){
        n = atoi(argv[1]);
        verbose = argv[2] ? atoi(argv[2]) : 0;
        printf("\nThe n-th Fibonacci Number is: %ld\n\n", fibonacci_generator(n, verbose));
    }
    else{
        printf("\nError: too few parameters\n");
        showUsage(argv[0]);
    }

    return 0;
}

/* Prints to terminal the correct usage of the program when interacting from the CLI */
void showUsage(char *progname) {
    printf("\n ============== Usage of \"%s\": ==============\n", progname);
    printf("\n\t ./a.out [nth_number] [verbose]\n\n");
    printf("\n* [nth_number] = Represents the nth Fibonacci number that you want to generate.");
    printf("\n* [verbose] = Lets you choose between verbose (== 1) and default (!= 1) behaviour:");
    printf("\n      - [verbose = 1] = Prints out to terminal the whole sequence up to the nth Fibonacci number requested.");
    printf("\n      - [verbose != 1] = Only returns the nth Fibonacci number requested.\n\n");
}

/* (Default) (if verbose != 1) Returns the n-th Fibonacci number */
/* (if verbose == 1) Returns the n-th Fibonacci number AND prints to terminal the whole sequence from 1 to the n-th number */
LONG fibonacci_generator(int n, int verbose) {
    LONG fib1, fib2, ris;
    int i;

    ris = 0;
        
    if(n > 0) {
        fib1 = 1;
        fib2 = 0;

        if(verbose) {
            printf("\n===== Generating First %d Fibonacci Numbers =====\n", n);
            printf("1\n");

            for(i=1; i < n; i++){
                ris = fib1 + fib2;
                fib2 = fib1;
                fib1 = ris;

                printf("%ld\n", ris);
            }
        }
        else{
            for(i=1; i < n; i++){
                ris = fib1 + fib2;
                fib2 = fib1;
                fib1 = ris;
            }
        }
    }
    else{
        printf("\nError: quantity must be greater than 0\n");
    }

    return ris;
}
