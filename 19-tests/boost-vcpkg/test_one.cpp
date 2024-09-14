#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_one)
BOOST_AUTO_TEST_CASE(test_case1)
{
    BOOST_CHECK(1 + 1 == 2);
}
BOOST_AUTO_TEST_SUITE_END()