/*
 * src/utest.c 
 * Implmentation for μTest framework
*/

#include "utest.h"

//Debugging Utilities
#ifdef MICROBIT_H
#define PRINTF uBit.serial.printf
#else
#define PRINTF printf
#endif

#ifdef MICROBIT_H
    static MicroBit uBit;
#endif

void _debug_mem_dump(void *mptr, size_t len, size_t blk, const char *fname, int line)
{
    if(!mptr || !len || !blk) return;
    blk = (blk > sizeof(unsigned long)) ? sizeof(unsigned long) : blk;

    //Opening Header 
    PRINTF("DEBUG: %s: %d: %s",fname,line, "Memory Dump BEGIN");

    const char *ptr = mptr;
    
    //Dump Memory
    for(size_t pos = 0; pos < len; pos += blk)
    {
        if(pos % 20 == 0) 
        { PRINTF("\r\nDEBUG:%#08lx: ", (unsigned long) pos ); }

        if(blk <= sizeof(char)) PRINTF("%" "hh" "X",  *((unsigned char *) ptr + pos)); 
        else if(blk <= sizeof(short)) PRINTF("%" "h" "X",  *((unsigned short *) ptr + pos)); 
        else if(blk <= sizeof(int)) PRINTF("%" "" "X",  *((unsigned int *) ptr + pos)); 
        else if(blk <= sizeof(long)) PRINTF("%" "l" "X",  *((unsigned long *) ptr + pos)); 
        else if(blk <= sizeof(long long)) PRINTF("%" "ll" "X",  *((unsigned long long *) ptr + pos)); 
        
        PRINTF(" "); //Space between blocks
    }
    
    //Closing Marker
    PRINTF("\r\nDEBUG: %s: %d: %s\r\n",fname,line, "Memory Dump END");
}
