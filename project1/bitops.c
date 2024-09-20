/*
* Add NetID and names of all project partners
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TOP_BITS 4 //top bits to extract
#define BITMAP_SIZE 4 //size of the bitmap array
#define SET_BIT_INDEX 17 //bit index to set 
#define GET_BIT_INDEX 17 //bit index to read

static unsigned int myaddress = 4026544704;   // Binary  would be 11110000000000000011001001000000

/* 
 * Function 1: EXTRACTING OUTER (TOP-ORDER) BITS
 */
static unsigned int get_top_bits(unsigned int value,  int num_bits)
{
    unsigned int cross = ((int) (2 << num_bits) - 1) << (8 * BITMAP_SIZE - num_bits);
    
    unsigned int gimme = value & cross; //Removing all but the top bits

    return gimme >> 8 * BITMAP_SIZE - num_bits; //moving bits to get top bit
}


/* 
 * Function 2: SETTING A BIT AT AN INDEX 
 * Function to set a bit at "index" bitmap
 */
static void set_bit_at_index(char *bitmap, int index)
{
    unsigned int manip = bitmap[index / 8]; //useless line cause empty but keep it anyway

    unsigned int bit = 1 << index % 8;

    manip = manip | bit;

    bitmap[index / 8] = manip;
}


/* 
 * Function 3: GETTING A BIT AT AN INDEX 
 * Function to get a bit at "index"
 */
static int get_bit_at_index(char *bitmap, int index) //wrong i think
{

    unsigned int manip = bitmap[index / 8];

    manip = manip >> (index % 8);

    return manip % 2;
    
}


int main () {

    /* 
     * Function 1: Finding value of top order (outer) bits Now let’s say we
     * need to extract just the top (outer) 4 bits (1111), which is decimal 15  
    */
    unsigned int outer_bits_value = get_top_bits (myaddress , NUM_TOP_BITS);
    printf("Function 1: Outer bits value %u \n", outer_bits_value); 
    printf("\n");

    /* 
     * Function 2 and 3: Checking if a bit is set or not
     */
    char *bitmap = (char *)malloc(BITMAP_SIZE);  //We can store 32 bits (4*8-bit per character)
    memset(bitmap,0, BITMAP_SIZE); //clear everything
    
    /* 
     * Let's try to set the bit 
     */
    set_bit_at_index(bitmap, SET_BIT_INDEX);
    
    /* 
     * Let's try to read bit)
     */
    printf("Function 3: The value at %dth location %d\n", 
            GET_BIT_INDEX, get_bit_at_index(bitmap, GET_BIT_INDEX));
            
    return 0;
}
