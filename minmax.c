#include<stdio.h>
#include<stdlib.h>

int max2(int a, int b){

    if (a > b) {return a;}
    else       {return b;}
}

int maximum(int a, int b, int c){
    if (a > b)
    {
        if (a > c) {return a;}
        else       {return c;}
    }
    else 
    {
        if (b > c) {return b;}
        else       {return c;}
    }
}

int min2(int a, int b){
    
    if (a < b) {return a;}
    else       {return b;}

}

int minimum(int a, int b, int c){
    return min2(min2(a, b), c);
}

int main(int argc, char *argv[]){
    if (argc != 5){
        printf("please enter three integers, such as: %s g 1 2 3 or %s l 1 2 3\n", argv[0], argv[0]);
        return 1;
    }
    
    if (argv[1][0] == 'g'){
        printf("the greatest integer is, %d\n", maximum(atoi(argv[2]),atoi(argv[3]),atoi(argv[4])));
        return 0;
}
    else if (argv[1][0] == 'l'){
        printf("the least integer is, %d\n", minimum(atoi(argv[2]), atoi(argv[3]), atoi(argv[4])));
        return 0;

}   else{printf("the flags are l and g\n");}}
