
#include<stdio.h>

int     main(void)
{

        char    * test = "coucou je suis un test";

        printf("result: %s", test);
        bzero(test[0], 7);
        printf("result: %s", test);
}