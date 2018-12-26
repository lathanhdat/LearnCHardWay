#include "ex22.h"
#include "dbg.h"
const char *MY_NAME = "Zed A.Shaw";
void scope_demo(int *count)
{
    log_info("count is :%d",*count);
    if (*count > 10)
    {
        int count = 100;
        // This make a whole new count in a mini scope of if condition
        // This can make bug;
        log_info("count in this scope is %d",count);
    }
    log_info("count is at exit: %d",*count);
    *count = 3000;
    log_info("count after assign: %d",*count);
}

int main(int argc,char *argv[])
{
    //Test THE_AGE accessors
    //Avoid using too many globals(espicially if across multiple files)
    //If have to, use accessor function like this get_age(). scope of THE_AGE exist 
    //in ex22.c so that get age and set age can access this variable
    log_info("My name :%s, age: %d",MY_NAME,get_age());
    set_age(100);
    log_info("My age is now: %d",get_age());

    //Test THE_SIZE extern
    log_info("THE_SIZE is : %d",THE_SIZE);
    print_size();
    THE_SIZE = 9;
    log_info("THE_SIZE is now: %d",THE_SIZE);
    print_size();

    //Test radio function static
    log_info("Radio at first: %f",update_ratio(2.0));
    log_info("Radio again: %f",update_ratio(10.0));
    log_info("Radio once more: %f",update_ratio(300.0));

    //Test scope demo
    //We input count = 4 to scope_demo function to change it to 3000
    //but nothing changed. To change it we need to use pointer
    int count = 4;
    int *pcount = &count;
    scope_demo(pcount);
    //scope_demo(count*20);
    log_info("count after calling scope_demo: %d",count);
    return 0;

}
