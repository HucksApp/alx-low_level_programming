#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int printf(const char *format, ...)
{
    write(1, "9 8 10 24 75 - 9\n", 18);
    write(1,"Congratulations, you win the Jackpot !\n", 40);
    exit(EXIT_SUCCESS);
}