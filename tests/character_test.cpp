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


struct StructCharacter {
    Character *c;
    StructCharacter() { c = new Character(); } // setUp
    ~StructCharacter() { delete(c); }  // tearDown
};


// Height
BOOST_FIXTURE_TEST_SUITE (character_height, StructCharacter)

BOOST_AUTO_TEST_CASE (height_valid) {
    // defaults values
    BOOST_CHECK( c->get_height() >= HEIGHT_MIN );
    BOOST_CHECK( c->get_height() <= HEIGHT_MAX );

    c->set_height(HEIGHT_MAX);
    BOOST_CHECK( c->get_height() >= HEIGHT_MIN );
    BOOST_CHECK( c->get_height() <= HEIGHT_MAX );

    c->set_height(HEIGHT_MIN);
    BOOST_CHECK( c->get_height() >= HEIGHT_MIN );
    BOOST_CHECK( c->get_height() <= HEIGHT_MAX );
}

BOOST_AUTO_TEST_CASE (height_set_out_domain) {
    BOOST_CHECK_THROW( c->set_height(HEIGHT_MAX + 1), domain_error );
}

BOOST_AUTO_TEST_SUITE_END( )


// Width
BOOST_FIXTURE_TEST_SUITE (character_width, StructCharacter)

BOOST_AUTO_TEST_CASE (width_valid) {
    // defaults values
    BOOST_CHECK( c->get_width() >= WIDTH_MIN );
    BOOST_CHECK( c->get_width() <= WIDTH_MAX );

    c->set_width(WIDTH_MAX);
    BOOST_CHECK( c->get_width() >= WIDTH_MIN );
    BOOST_CHECK( c->get_width() <= WIDTH_MAX );

    c->set_width(WIDTH_MIN);
    BOOST_CHECK( c->get_width() >= WIDTH_MIN );
    BOOST_CHECK( c->get_width() <= WIDTH_MAX );
}

BOOST_AUTO_TEST_CASE (width_set_out_domain) {
    BOOST_CHECK_THROW( c->set_width(WIDTH_MAX + 1), domain_error );
}

BOOST_AUTO_TEST_SUITE_END( )

// Life
BOOST_FIXTURE_TEST_SUITE (character_life, StructCharacter)

BOOST_AUTO_TEST_CASE (valid_life) {
    unsigned int zero = 0;
    c->set_life(zero);
    BOOST_REQUIRE( c->get_life() <= c->get_total_life() );
    c->set_life( c->get_total_life() );
    BOOST_REQUIRE( c->get_life() <= c->get_total_life() );
}

BOOST_AUTO_TEST_CASE (life_increment) {
    int increment = 1;
    unsigned int zero = 0;
    c->set_life(zero);
    c->set_rel_life(increment);
    BOOST_CHECK( c->get_life() == zero + increment );
}

BOOST_AUTO_TEST_CASE (life_decrement) {
    int decrement = 1;
    c->set_life(c->get_total_life());
    c->set_rel_life(-decrement);
    BOOST_CHECK( c->get_life() == c->get_total_life() - decrement );
}

BOOST_AUTO_TEST_CASE (life_increment_out_domain) {
    c->set_life(c->get_total_life());
    BOOST_CHECK_THROW( c->set_rel_life(1), domain_error );
}

BOOST_AUTO_TEST_CASE (life_decrement_out_domain) {
    unsigned int zero = 0;
    c->set_life(zero);
    BOOST_CHECK_THROW( c->set_rel_life(-1), domain_error );
}

BOOST_AUTO_TEST_SUITE_END( )
