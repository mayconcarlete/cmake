#define BOOST_TEST_MODULE MyTestSuite
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(MyTestCase)
{
    BOOST_CHECK(1 + 1 == 2);
}