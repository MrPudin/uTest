#define DEBUG
#include "utest.h"

double norm_pow(double x, int exp)
{
    if(exp <= 1) return x;
    else return x * norm_pow(x, exp - 1);
}

double log_pow(double x, int exp)
{
    if(exp <= 1) return x;
    else if(exp % 2 == 0) 
    {
        double hf_pow = log_pow(x, exp / 2);
        return hf_pow * hf_pow;
    }
    else return x * log_pow(x , exp - 1);
}

double sigint_pow(double x, int exp)
{
    raise(SIGINT);
    return 0.0;
}

double wrong_pow(double x, int exp)
{
    if(x < exp) return -125;
    return exp * wrong_pow(x - 15, exp - 2);
}

void test_norm_pow()
{
    TEST_EQUAL(norm_pow(2, 100), 1267650600228229401496703205376.0);
}

void test_log_pow()
{
    TEST_EQUAL(log_pow(2, 100), 1267650600228229401496703205376.0);
}

void test_sigint_pow()
{
    TEST_EQUAL(sigint_pow(2, 100), 1267650600228229401496703205376.0);
}
void test_wrong_pow()
{
    TEST_EQUAL(wrong_pow(2, 100), 1267650600228229401496703205376.0);
}

void test_mem()
{
    TEST_MEM_EQUAL("hello", "hello", 5);
    TEST_NOT_MEM_EQUAL("hello", "linux", 5);
}

int main()
{
    DPRINT("Testing Debugging Utilities");

    char *data = "dfagasfadasgkjsakgjaskldgjsgkldsjadgkasjdglkasjdgksladjglkasdgjksgja;djgkasdjglasdjkgsa;";
    DMEM_DUMP(data, 88, 1);
    DMEM_DUMP(data, 88, 2);
    DMEM_DUMP(data, 88, 4);
    
    DPRINT("HACKS");
    DPRINTF("I have %d toes\r\n", 10);
    
    DPRINT("Testing Test Harness");
    

    TEST_BEGIN;
    TEST(test_norm_pow);
    TEST(test_log_pow);
    TEST(test_sigint_pow);
    TEST(test_wrong_pow);
    TEST(test_mem);
    TEST_END;

    DPRINTF("Test result: %d\n", memcmp((void *)"hello", (void *)"hello", (size_t)5));
}
