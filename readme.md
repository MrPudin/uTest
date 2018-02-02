# μTest - C/C++ Test Harnesss / Debugging Utilities
---
### Intro 
A small test harness for testing on the embeded devices such as the Microbit,
plus debugging Utilities to facilitate the development of reliable solutions 
on these devices. The test harness also generates reports on the test run:

```
Run test_norm_pow()...PASS
Run test_log_pow()...PASS
Run test_sigint_pow()...FAIL
Run test_wrong_pow()...FAIL
---===TEST REPORT===---
Test test_norm_pow() - PASS [32.000 us]

Test test_log_pow() - PASS [8.000 us]

Test test_sigint_pow() - FAIL [49.000 us]
        Caught Signal: SIGINT
Test test_wrong_pow() - FAIL@49 [10.000 us]
        TEST_EQUAL: Arguments not equal: wrong_pow(2, 100) NOT EQUAL 1267650600228229401496703205376.0
============================
 2 Tests Failed / 4 Tests Run
 Overall: FAIL
---===TEST END===---
```

On the MicroBit, μTest automatically redicts output to MicroBit serial output.

### Usage
An example test program using μTest's test harness would look something like 
this:
```c
#include "utest.h"
void test_func(TestState* _state_){
    TEST_TRUE(1 == 1); // assert true or fail test
    TEST_EQUAL(1, 1); // assert equal or fail test
    TEST_FALSE(1 == 2); // assert false or fail test
    TEST_NOT_EQUAL(1, 2); // assert not equal or fail test.
} // a test.

int main()
{
    //Setup Code
    //....

    //Testing
    TEST_BEGIN; // setup test enviroment
    TEST(test_func); // run test 'test_func'
    TEST_END; // test cleanup and print test report.

    //Cleanup Code
    //....
}
```


μTest also provides debug prints, which print addtional infomation such as the
the line number and function name when printing. These debug prints can be 
compiled in for debug builds when **DEBUG** is defined, and easily out by
undefining **DEBUG**. μTest also can produce hexadecimal memory dumps like 
`hexdump`

```c
DPRINT("debugging infomation"); //Print with newline, func name and line number
DMEM_DUMP(data, 88, 1); //Dump 80 bytes of data
```

### Installation
Run `make docs` for documentation at `build/docs`

Just include `src/utest.h` for the defintions. When compiling link against 
`src/utest.c`

### Misc
Roses are red.
Violets are blue.
But Im bleeding on the inside,
When I see you with him.
I see you in my dreams,
but they always end too soon.
Come back home,
Please.
Im bleeding out.
Do you even care?
