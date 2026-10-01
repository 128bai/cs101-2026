#include <stdio.h>

int main()
{
    char grade='B';
    printf("your grade is %c\n",grade);
    switch(grade){
        case'A':
            printf("Excellent!\n");
            break;
        case 'B':
        case 'C';
            printf("Well done!\n");
        case'D':
        case'F':
            printf("Bettr try again!\n");
            break;
        default:
            printf("Invali grade\n");
    }
    return 0;
}
