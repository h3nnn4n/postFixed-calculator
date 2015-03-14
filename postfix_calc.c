#include <stdio.h>
#include <stdlib.h>

int isSane(int top){
    if( top ==0 )
    {
        printf(" Syntax Error!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int size = argc - 1;
    int i,j;
    int top=-1;

    double *stack = (double*) malloc(sizeof(double) * size);

    for(i=1 ; i<=size ; i++)
    {
        if( argv[i][0] == '+' )
        {
            if(isSane(top) == EXIT_FAILURE ){ return EXIT_FAILURE; }
            stack[top - 1] = stack[top - 1] + stack[top];
            top--;
        }
        else if( argv[i][0] == '-' )
        {
            if(isSane(top) == EXIT_FAILURE ){ return EXIT_FAILURE; }
            stack[top - 1] = stack[top - 1] - stack[top];
            top--;
        }
        else if( argv[i][0] == '/' )
        {
            if(isSane(top) == EXIT_FAILURE ){ return EXIT_FAILURE; }
            stack[top - 1] = stack[top - 1] / stack[top];
            top--;
        }
        else if( argv[i][0] == '*')
        {
            if(isSane(top) == EXIT_FAILURE ){ return EXIT_FAILURE; }
            stack[top - 1] = stack[top - 1] * stack[top];
            top--;
        }
        else
        {
            top++;
            stack[top] = atof(argv[i]);
        }
    }

    if( top != 0 )
    {
        printf(" Syntax Error !\n");
    }
    else
    {
        printf("%f\n",stack[0]);
    }

    return EXIT_SUCCESS;
}
