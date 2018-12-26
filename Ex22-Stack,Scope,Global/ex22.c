#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000;
static int THE_AGE = 37;

int get_age()
{
    return THE_AGE;
}

void set_age(int age)
{
    THE_AGE = age;
}

double update_ratio(double new_ratio)
{
    //Print old ratio and save new_ratio to ratio
    static double ratio = 1.0; 
    //We don't usually use this static variable in function
    //because it won't accessable if we use a thread to handle function.
    double old_ratio = ratio;
    ratio = new_ratio;
    return old_ratio;
}

void print_size()
{
    log_info("I think size is : %d",THE_SIZE);
}