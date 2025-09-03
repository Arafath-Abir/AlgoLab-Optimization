#include <stdio.h>
#include "utils.h"
void print_array(const int *a,int n){
    for(int i=0;i<n;++i){ if(i) printf(" "); printf("%d", a[i]); }
    printf("\n");
}
