#include <stdio.h>
#include <string.h>
#include "unittests.h"
#include "enum.pb.h"

int main()
{
    int status = 0;
    MyEnum result1;
    MyShortNameEnum result2;

    /* Test MyEnum_from_string */
    TEST(MyEnum_from_string("VALUE1", &result1) == true);
    TEST(result1 == MyEnum_VALUE1);

    TEST(MyEnum_from_string("VALUE2", &result1) == true);
    TEST(result1 == MyEnum_VALUE2);

    TEST(MyEnum_from_string("VALUE15", &result1) == true);
    TEST(result1 == MyEnum_VALUE15);

    /* Test invalid string returns false */
    TEST(MyEnum_from_string("INVALID", &result1) == false);
    TEST(MyEnum_from_string("", &result1) == false);

    /* Test MyShortNameEnum_from_string */
    TEST(MyShortNameEnum_from_string("MSNE_VALUE256", &result2) == true);
    TEST(result2 == MSNE_VALUE256);

    /* Test invalid string for MyShortNameEnum */
    TEST(MyShortNameEnum_from_string("INVALID", &result2) == false);

    /* Test that the X-macro is defined and can be used directly */
    {
        int count = 0;
        #define COUNT_X(val, name) count++;
        MyEnum_XMACRO_VALS(COUNT_X)
        #undef COUNT_X
        TEST(count == 3); /* VALUE1, VALUE2, VALUE15 */
    }

    if (status != 0)
        fprintf(stdout, "\n\nSome tests FAILED!\n");

    return status;
}

