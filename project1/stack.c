/*                                                                                                                  
* rr1185 - Rahulraj Rajesh                                                                       
* st1005 - Sibi Suriyanarayan Tiruchirapalli Venketaramani                                                                                                                  
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/* Part 1 - Step 1 and 2: Do your tricks here                                                                       
 * Your goal must be to change the stack frame of caller (main function)                                            
 * such that you get to the line after "r2 = *( (int *) 0 )"                                                        
 */
void signal_handle(int signalno) { //0xffffbfe0

    char* ninja = (char *) &signalno + 60;

    *ninja += 5;

    int i = 0;
    printf("handling segmentation fault!\n");
    i = i + 1; //just incrementing a variable.                                                                      

}

int main(int argc, char *argv[]) {

    int r2 = 0;

    /* Step 1: Register signal handler first*/
    signal(SIGSEGV, signal_handle);

    r2 = *( (int *) 0 ); // This will generate segmentation fault   

    r2 = r2 + 1 * 45;
    printf("result after handling seg fault %d!\n", r2);

    return 0;
}
