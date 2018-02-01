#ifndef UTEST_H
/**
 * @file src/utest.h
 * Declares the functionality provided by the μTest framework 
 * 
 * @warning For microbit support, only include this file after you have included
 * pxt.h or microbit.h
*/

#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

/** @defgroup debug Debugging Utilities
 *  An assortment of debugging goodies such as more infomative prints, memory
 *  dumps.
 *  Debugging macros for development use when **DEBUG** is defined,
 *  compiled out when **DEBUG** is undefined. 
  */
//@{
#ifdef DEBUG

#define QUOTE(macro) #macro

void _debug_mem_dump(void *mptr, size_t len, size_t blk, const char *fname, int line);
#define DMEM_DUMP(ptr, size, blklen)\
    _debug_mem_dump(ptr, size, blklen, __func__, __LINE__)

#ifdef MICROBIT_H 
#define DPRINT(msg)\
    do { \
        MicroBit uBit;\
        uBit.serial.printf("DEBUG: %s: %d: %s\r\n",__func__,__LINE__,msg)\
    } while (0)

#define DPRINTF(...) \
    do { \
        MicroBit uBit;\
        uBit.serial.printf("DEBUG: " __VA_ARGS__)\
    } while (0)
#else
#define DPRINT(msg) printf("DEBUG: %s: %d: %s\n",__func__,__LINE__, msg)
#define DPRINTF(...) printf("DEBUG: " __VA_ARGS__)
#endif /* ifdef MICROBIT_H */

#else
/** @def DPRINT
 *  Debugging print - prints debugging message, with function name and line 
 *  number, appending a newline at the end. Debug print is only defined when
 *  DEBUG is defined. This allows the removal of debug prints by removing the 
 *  definition of DEBUG.
 *  If compiled for the MircoBit, would print to serial instead of standard 
 *  output.
 *  
 *  @param msg The debugging message to print
*/
#define DPRINT(msg)

/** @def DPRINTF
 *  Debugging print format - print printf format string with arguments, with 
 *  function name and line number.Debug print is only defined when
 *  DEBUG is defined. This allows the removal of debug prints by removing the 
 *  definition of DEBUG.
 *  If compiled for the MircoBit, would print to serial instead of standard 
 *  output.
 *  
 *  @param ... printf arguemnts for printing.
 *  @sa printf
*/
#define DPRINTF(...)

/** @def DMEM_DUMP
 *  Debugging memory dump - print the memory at **mptr** for **size** bytes,
 *  in hexadecimal blocks of the size **blklen**, with function name and line 
 *  number. Debug print also prepends the current memory address and appends 
 *  a newline for every 80 characters printed.
 *  Debug memory defined when DEBUG is defined. This allows the removal of 
 *  debug prints by removing the definition of DEBUG.
 *  If compiled for the MircoBit, would print to serial instead of standard 
 *  output.
 *  
 *  @param ptr Pointer to the memory to be dumped.
 *  @param size Size of the memory to be dumped in bytes.
 *  @param blklen Length of each space seperated block printed in bytes
*/
#define DMEM_DUMP(ptr, size, blklen)

#endif /* ifndef DEBUG */
//@}

/** @defgroup test Test Harness
 *  A small test harness for testing on the Microbit. The test harness enables
 * users to easily create test suites and generates test report at the end of 
 * testing.
 *
 * Each test is defined by the use as a function as shown the example below:
 *      void test_func()
 *      {
 *          int result = some_pther_func();
 *          ASSERT_TRUE(result
 *      }
 * The function should return void and take in no arguments.
 *  
  */
#endif /* ifndef UTEST_H */
