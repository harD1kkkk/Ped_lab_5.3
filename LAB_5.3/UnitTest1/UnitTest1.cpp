#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_5.3/lab_5.3.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            double p_start = 0.0;
            double p_end = 0.5;
            int n = 5;
            double dp = (p_end - p_start) / n;
            double p = p_start;

            double expected_results[] = {
                4.0000000000,
                4.0247000230,
                4.2282417325,
                4.9136018743,
                6.8875452584,
                2.3479336479
            };

            for (int i = 0; i <= n; ++i)
            {
                double result = z(p * p) + 2 * z(2 * p + p * p) + 1;
                Assert::AreEqual(expected_results[i], result, 0.0001);
                p += dp;
            }
        }
    };
}
