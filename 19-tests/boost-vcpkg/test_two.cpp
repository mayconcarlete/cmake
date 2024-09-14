#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_two)
BOOST_AUTO_TEST_CASE(test_case1)
{
    BOOST_CHECK(4 + 4 == 8);
}
BOOST_AUTO_TEST_SUITE_END()