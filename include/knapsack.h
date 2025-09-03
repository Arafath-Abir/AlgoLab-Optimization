
#ifndef KNAPSACK_H
#define KNAPSACK_H
typedef struct { double weight; double value; } Item;
double fractional_knapsack(Item *items, int n, double capacity);
#endif
