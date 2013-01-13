#define BOOST_TEST_MODULE charactertests
#include <boost/test/included/unit_test.hpp>

#include "character.hpp"
#include "cte.hpp"

using namespace hw;

// Height
BOOST_AUTO_TEST_SUITE (character_height)

BOOST_AUTO_TEST_CASE (height_set)
{
    character c;
    c.set_height(HEIGHT_CTE);
    BOOST_CHECK( HEIGHT_CTE == c.get_height() );
}

BOOST_AUTO_TEST_CASE (height_set_out_domain)
{
    character c;
    BOOST_CHECK_THROW( c.set_height(HEIGHT_MAX + 1), domain_error );
}

BOOST_AUTO_TEST_CASE (height_increment)
{
    character c;
    c.set_height(HEIGHT_CTE);
    c.height_inc();
    BOOST_CHECK( HEIGHT_CTE + HEIGHT_INC == c.get_height() );
}

BOOST_AUTO_TEST_CASE (height_decrement)
{
    character c;
    c.set_height(HEIGHT_CTE);
    c.height_dec();
    BOOST_CHECK( HEIGHT_CTE - HEIGHT_INC == c.get_height() );
}

BOOST_AUTO_TEST_CASE (height_increment_out_domain)
{
    character c;
    c.set_height(HEIGHT_MAX);
    BOOST_CHECK_THROW( c.height_inc(), domain_error);
}

BOOST_AUTO_TEST_CASE (height_decrement_out_domain)
{
    character c;
    c.set_height(HEIGHT_MIN);
    BOOST_CHECK_THROW( c.height_dec(), domain_error);
}

BOOST_AUTO_TEST_SUITE_END( )


// Width
BOOST_AUTO_TEST_SUITE (character_width)

BOOST_AUTO_TEST_CASE (width_set)
{
    character c;
    c.set_width(WIDTH_CTE);
    BOOST_CHECK( WIDTH_CTE == c.get_width() );
}

BOOST_AUTO_TEST_CASE (width_set_out_domain)
{
    character c;
    BOOST_CHECK_THROW( c.set_width(WIDTH_MAX + 1), domain_error );
}

BOOST_AUTO_TEST_CASE (width_increment)
{
    character c;
    c.set_width(WIDTH_CTE);
    c.width_inc();
    BOOST_CHECK( WIDTH_CTE + WIDTH_INC == c.get_width() );
}

BOOST_AUTO_TEST_CASE (width_decrement)
{
    character c;
    c.set_width(WIDTH_CTE);
    c.width_dec();
    BOOST_CHECK( WIDTH_CTE - WIDTH_INC == c.get_width() );
}

BOOST_AUTO_TEST_CASE (width_increment_out_domain)
{
    character c;
    c.set_width(WIDTH_MAX);
    BOOST_CHECK_THROW( c.width_inc(), domain_error);
}

BOOST_AUTO_TEST_CASE (width_decrement_out_domain)
{
    character c;
    c.set_width(WIDTH_MIN);
    BOOST_CHECK_THROW( c.width_dec(), domain_error);
}

BOOST_AUTO_TEST_SUITE_END( )
