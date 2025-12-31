#include<stdio.h>
#include<stdlib.h>

double compound(int amount, double rate, int years)
{
    double year_total = 0;
    for (int i = 0; i < years; ++i)
    {
        year_total += amount;
        year_total *= (1 + rate);
    }
    return year_total;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Please input parameters like this: \n");
        printf("%s 100, 0.04, 10\n", argv[0]);
        printf("%s <deposit_amount> <interest_rate> <years>\n", argv[0]);
        return 1;
    }

    int amount = atoi(argv[1]);
    double rate = atof(argv[2]);
    int years = atoi(argv[3]);
    
    double total = compound(amount, rate, years);
    printf("Total: $%f\n", total);    

    return 0;
}
