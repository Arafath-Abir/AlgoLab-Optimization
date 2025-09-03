
#include <stdlib.h>
#include "knapsack.h"
static int cmp_ratio_desc(const void *a,const void *b){
    const Item *x=(const Item*)a, *y=(const Item*)b;
    double rx=x->value/x->weight, ry=y->value/y->weight;
    if(rx<ry) return 1; if(rx>ry) return -1; return 0;
}
double fractional_knapsack(Item *items, int n, double capacity){
    qsort(items,n,sizeof(Item),cmp_ratio_desc);
    double left=capacity, total=0.0;
    for(int i=0;i<n && left>1e-12;++i){
        if(items[i].weight<=left){ total+=items[i].value; left-=items[i].weight; }
        else { double f=left/items[i].weight; total+=items[i].value*f; left=0.0; }
    }
    return total;
}