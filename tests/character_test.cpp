/*************************************************************************
* Open Fantasy World is a MMORPG where the players will live in community.
* Copyright (C) 2012-2013 Víctor Ramirez de la Corte <virako.9@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Foobar is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#define BOOST_TEST_MODULE charactertests
#include <boost/test/included/unit_test.hpp>

#include "character.hpp"
#include "cte.hpp"

using namespace hw;


struct Character {
    character *c;
    Character() { c = new character(); } // setUp
    ~Character() { delete(c); }  // tearDown
};


// Height
BOOST_FIXTURE_TEST_SUITE (character_height, Character)

BOOST_AUTO_TEST_CASE (height_set)
{
    c->set_height(HEIGHT_CTE);
    BOOST_CHECK( HEIGHT_CTE == c->get_height() );
}

BOOST_AUTO_TEST_CASE (height_set_out_domain)
{
    BOOST_CHECK_THROW( c->set_height(HEIGHT_MAX + 1), domain_error );
}

BOOST_AUTO_TEST_CASE (height_increment)
{
    c->set_height(HEIGHT_CTE);
    c->height_inc();
    BOOST_CHECK( HEIGHT_CTE + HEIGHT_INC == c->get_height() );
}

BOOST_AUTO_TEST_CASE (height_decrement)
{
    c->set_height(HEIGHT_CTE);
    c->height_dec();
    BOOST_CHECK( HEIGHT_CTE - HEIGHT_INC == c->get_height() );
}

BOOST_AUTO_TEST_CASE (height_increment_out_domain)
{
    c->set_height(HEIGHT_MAX);
    BOOST_CHECK_THROW( c->height_inc(), domain_error);
}

BOOST_AUTO_TEST_CASE (height_decrement_out_domain)
{
    c->set_height(HEIGHT_MIN);
    BOOST_CHECK_THROW( c->height_dec(), domain_error);
}

BOOST_AUTO_TEST_SUITE_END( )


// Width
BOOST_FIXTURE_TEST_SUITE (character_width, Character)

BOOST_AUTO_TEST_CASE (width_set)
{
    c->set_width(WIDTH_CTE);
    BOOST_CHECK( WIDTH_CTE == c->get_width() );
}

BOOST_AUTO_TEST_CASE (width_set_out_domain)
{
    BOOST_CHECK_THROW( c->set_width(WIDTH_MAX + 1), domain_error );
}

BOOST_AUTO_TEST_CASE (width_increment)
{
    c->set_width(WIDTH_CTE);
    c->width_inc();
    BOOST_CHECK( WIDTH_CTE + WIDTH_INC == c->get_width() );
}

BOOST_AUTO_TEST_CASE (width_decrement)
{
    c->set_width(WIDTH_CTE);
    c->width_dec();
    BOOST_CHECK( WIDTH_CTE - WIDTH_INC == c->get_width() );
}

BOOST_AUTO_TEST_CASE (width_increment_out_domain)
{
    c->set_width(WIDTH_MAX);
    BOOST_CHECK_THROW( c->width_inc(), domain_error);
}

BOOST_AUTO_TEST_CASE (width_decrement_out_domain)
{
    c->set_width(WIDTH_MIN);
    BOOST_CHECK_THROW( c->width_dec(), domain_error);
}

BOOST_AUTO_TEST_SUITE_END( )
