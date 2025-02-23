#include <stdio.h>
#include <stdlib.h>
#define len 10

int * myFunction(){
    static int array[len] = {0};
    return array;
}

void init(){
     int * array = myFunction();
     int idx;
     for(idx = 0; idx < len; idx++) array[idx] = len - idx;
     return;
     }
     
     int main() {
         int * x = myFunction();
         int idx;
         init();
         for(idx = 0; idx < len; idx++) printf("%d\n",x[idx]);
         
         system("pause");
         return 0;
         }
