#include <boost/test/unit_test.hpp>
#include "../src/math.hpp"

BOOST_AUTO_TEST_SUITE(math_tests)
/*
    It should return the sum of fatorial 5;
*/
BOOST_AUTO_TEST_CASE(test1)
{
    auto result = fatorial(5);
    BOOST_CHECK(result == 120);
}

BOOST_AUTO_TEST_SUITE_END()