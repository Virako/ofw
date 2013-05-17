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

#define BOOST_TEST_MODULE playertests
#include <boost/test/included/unit_test.hpp>

#include "scene/character.hpp"
#include "scene/player.hpp"
#include "scene/picacode.hpp"
#include "scene/hacker.hpp"
#include "scene/cracker.hpp"
#include "scene/designer.hpp"
#include "scene/hunterbug.hpp"

// vim: avoid syntastic errors
// #include "../src/scene/character.hpp"
// #include "../src/scene/picacode.hpp"
// #include "../src/scene/hacker.hpp"
// #include "../src/scene/cracker.hpp"
// #include "../src/scene/designer.hpp"
// #include "../src/scene/hunterbug.hpp"
// #include "../src/scene/player.hpp"


struct StructPicacode {
    ofw::scene::Picacode *player;
    StructPicacode() { player = new ofw::scene::Picacode(); } // setUp
    ~StructPicacode() { delete player; }  // tearDown
};

struct StructHacker {
    ofw::scene::Hacker *player;
    StructHacker() { player = new ofw::scene::Hacker(); } // setUp
    ~StructHacker() { delete player; }  // tearDown
};

struct StructCracker {
    ofw::scene::Cracker *player;
    StructCracker() { player = new ofw::scene::Cracker(); } // setUp
    ~StructCracker() { delete player; }  // tearDown
};

struct StructDesigner {
    ofw::scene::Designer *player;
    StructDesigner() { player = new ofw::scene::Designer(); } // setUp
    ~StructDesigner() { delete player; }  // tearDown
};

struct StructHunterbug {
    ofw::scene::Hunterbug *player;
    StructHunterbug() { player = new ofw::scene::Hunterbug(); } // setUp
    ~StructHunterbug() { delete player; }  // tearDown
};

BOOST_FIXTURE_TEST_SUITE (picacode, StructPicacode)

    BOOST_AUTO_TEST_CASE (default_values_check) {
        BOOST_CHECK(player->get_height() >= player->get_height_min());
        BOOST_CHECK(player->get_height() <= player->get_height_max());
        BOOST_CHECK(player->get_width() >= player->get_width_min());
        BOOST_CHECK(player->get_width() <= player->get_width_max());
    }

    BOOST_AUTO_TEST_CASE(height_default) {
        unsigned int h = player->get_height_min() + (player->get_height_max() -
                player->get_height_min()) / 2;
        BOOST_CHECK(player->get_height() == h);
    }

    BOOST_AUTO_TEST_CASE(width_default) {
        unsigned int w = player->get_width_min() + (player->get_width_max() -
                player->get_width_min()) / 2;
        BOOST_CHECK(player->get_width() == w);
    }

    BOOST_AUTO_TEST_CASE (height_set_out_domain) {
        BOOST_CHECK_THROW(player->set_height(player->get_height_max() + 1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_set_out_domain) {
        BOOST_CHECK_THROW(player->set_width(player->get_width_max() + 1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (height_increment) {
        unsigned int h_default = player->get_height_min() +
                (player->get_height_max() - player->get_height_min()) / 2;
        player->set_rel_height(1);
        BOOST_CHECK(player->get_height() == h_default + 1);
    }

    BOOST_AUTO_TEST_CASE (height_decrement) {
        unsigned int h_default = player->get_height_min() +
                (player->get_height_max() - player->get_height_min()) / 2;
        player->set_rel_height(-1);
        BOOST_CHECK(player->get_height() == h_default - 1);
    }

    BOOST_AUTO_TEST_CASE (height_increment_out_domain) {
        player->set_height(player->get_height_max());
        BOOST_CHECK_THROW(player->set_rel_height(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (height_decrement_out_domain) {
        player->set_height(player->get_height_min());
        BOOST_CHECK_THROW(player->set_rel_height(-1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_increment) {
        unsigned int h_default = player->get_width_min() +
                (player->get_width_max() - player->get_width_min()) / 2;
        player->set_rel_width(1);
        BOOST_CHECK(player->get_width() == h_default + 1);
    }

    BOOST_AUTO_TEST_CASE (width_decrement) {
        unsigned int h_default = player->get_width_min() +
                (player->get_width_max() - player->get_width_min()) / 2;
        player->set_rel_width(-1);
        BOOST_CHECK(player->get_width() == h_default - 1);
    }

    BOOST_AUTO_TEST_CASE (width_increment_out_domain) {
        player->set_width(player->get_width_max());
        BOOST_CHECK_THROW(player->set_rel_width(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_decrement_out_domain) {
        player->set_width(player->get_width_min());
        BOOST_CHECK_THROW(player->set_rel_width(-1), std::domain_error);
    }

    // Life
    BOOST_AUTO_TEST_CASE (default_values) {
        BOOST_REQUIRE(player->get_life() == player->get_total_life());
    }

    BOOST_AUTO_TEST_CASE (valid_life) {
        unsigned int zero = 0;
        player->set_life(zero);
        BOOST_REQUIRE(player->get_life() <= player->get_total_life());
        player->set_life(player->get_total_life());
        BOOST_REQUIRE(player->get_life() <= player->get_total_life());
    }

    BOOST_AUTO_TEST_CASE (life_increment) {
        int increment = 1;
        unsigned int zero = 0;
        player->set_life(zero);
        player->set_rel_life(increment);
        BOOST_CHECK(player->get_life() == zero + increment);
    }

    BOOST_AUTO_TEST_CASE (life_decrement) {
        int decrement = 1;
        player->set_life(player->get_total_life());
        player->set_rel_life(-decrement);
        BOOST_CHECK(player->get_life() == player->get_total_life() - decrement);
    }

    BOOST_AUTO_TEST_CASE (life_increment_out_domain) {
        player->set_life(player->get_total_life());
        BOOST_CHECK_THROW(player->set_rel_life(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (life_decrement_out_domain) {
        unsigned int zero = 0;
        player->set_life(zero);
        BOOST_CHECK_THROW(player->set_rel_life(-1), std::domain_error);
    }

BOOST_AUTO_TEST_SUITE_END()



BOOST_FIXTURE_TEST_SUITE (hacker, StructHacker)

    BOOST_AUTO_TEST_CASE (default_values_check) {
        BOOST_CHECK(player->get_height() >= player->get_height_min());
        BOOST_CHECK(player->get_height() <= player->get_height_max());
        BOOST_CHECK(player->get_width() >= player->get_width_min());
        BOOST_CHECK(player->get_width() <= player->get_width_max());
    }

    BOOST_AUTO_TEST_CASE(height_default) {
        unsigned int h = player->get_height_min() + (player->get_height_max() -
                player->get_height_min()) / 2;
        BOOST_CHECK(player->get_height() == h);
    }

    BOOST_AUTO_TEST_CASE(width_default) {
        unsigned int w = player->get_width_min() + (player->get_width_max() -
                player->get_width_min()) / 2;
        BOOST_CHECK(player->get_width() == w);
    }

    BOOST_AUTO_TEST_CASE (height_set_out_domain) {
        BOOST_CHECK_THROW(player->set_height(player->get_height_max() + 1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_set_out_domain) {
        BOOST_CHECK_THROW(player->set_width(player->get_width_max() + 1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (height_increment) {
        unsigned int h_default = player->get_height_min() +
                (player->get_height_max() - player->get_height_min()) / 2;
        player->set_rel_height(1);
        BOOST_CHECK(player->get_height() == h_default + 1);
    }

    BOOST_AUTO_TEST_CASE (height_decrement) {
        unsigned int h_default = player->get_height_min() +
                (player->get_height_max() - player->get_height_min()) / 2;
        player->set_rel_height(-1);
        BOOST_CHECK(player->get_height() == h_default - 1);
    }

    BOOST_AUTO_TEST_CASE (height_increment_out_domain) {
        player->set_height(player->get_height_max());
        BOOST_CHECK_THROW(player->set_rel_height(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (height_decrement_out_domain) {
        player->set_height(player->get_height_min());
        BOOST_CHECK_THROW(player->set_rel_height(-1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_increment) {
        unsigned int h_default = player->get_width_min() +
                (player->get_width_max() - player->get_width_min()) / 2;
        player->set_rel_width(1);
        BOOST_CHECK(player->get_width() == h_default + 1);
    }

    BOOST_AUTO_TEST_CASE (width_decrement) {
        unsigned int h_default = player->get_width_min() +
                (player->get_width_max() - player->get_width_min()) / 2;
        player->set_rel_width(-1);
        BOOST_CHECK(player->get_width() == h_default - 1);
    }

    BOOST_AUTO_TEST_CASE (width_increment_out_domain) {
        player->set_width(player->get_width_max());
        BOOST_CHECK_THROW(player->set_rel_width(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_decrement_out_domain) {
        player->set_width(player->get_width_min());
        BOOST_CHECK_THROW(player->set_rel_width(-1), std::domain_error);
    }

    // Life
    BOOST_AUTO_TEST_CASE (default_values) {
        BOOST_REQUIRE(player->get_life() == player->get_total_life());
    }

    BOOST_AUTO_TEST_CASE (valid_life) {
        unsigned int zero = 0;
        player->set_life(zero);
        BOOST_REQUIRE(player->get_life() <= player->get_total_life());
        player->set_life(player->get_total_life());
        BOOST_REQUIRE(player->get_life() <= player->get_total_life());
    }

    BOOST_AUTO_TEST_CASE (life_increment) {
        int increment = 1;
        unsigned int zero = 0;
        player->set_life(zero);
        player->set_rel_life(increment);
        BOOST_CHECK(player->get_life() == zero + increment);
    }

    BOOST_AUTO_TEST_CASE (life_decrement) {
        int decrement = 1;
        player->set_life(player->get_total_life());
        player->set_rel_life(-decrement);
        BOOST_CHECK(player->get_life() == player->get_total_life() - decrement);
    }

    BOOST_AUTO_TEST_CASE (life_increment_out_domain) {
        player->set_life(player->get_total_life());
        BOOST_CHECK_THROW(player->set_rel_life(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (life_decrement_out_domain) {
        unsigned int zero = 0;
        player->set_life(zero);
        BOOST_CHECK_THROW(player->set_rel_life(-1), std::domain_error);
    }

BOOST_AUTO_TEST_SUITE_END()



BOOST_FIXTURE_TEST_SUITE (cracker, StructCracker)

    BOOST_AUTO_TEST_CASE (default_values_check) {
        BOOST_CHECK(player->get_height() >= player->get_height_min());
        BOOST_CHECK(player->get_height() <= player->get_height_max());
        BOOST_CHECK(player->get_width() >= player->get_width_min());
        BOOST_CHECK(player->get_width() <= player->get_width_max());
    }

    BOOST_AUTO_TEST_CASE(height_default) {
        unsigned int h = player->get_height_min() + (player->get_height_max() -
                player->get_height_min()) / 2;
        BOOST_CHECK(player->get_height() == h);
    }

    BOOST_AUTO_TEST_CASE(width_default) {
        unsigned int w = player->get_width_min() + (player->get_width_max() -
                player->get_width_min()) / 2;
        BOOST_CHECK(player->get_width() == w);
    }

    BOOST_AUTO_TEST_CASE (height_set_out_domain) {
        BOOST_CHECK_THROW(player->set_height(player->get_height_max() + 1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_set_out_domain) {
        BOOST_CHECK_THROW(player->set_width(player->get_width_max() + 1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (height_increment) {
        unsigned int h_default = player->get_height_min() +
                (player->get_height_max() - player->get_height_min()) / 2;
        player->set_rel_height(1);
        BOOST_CHECK(player->get_height() == h_default + 1);
    }

    BOOST_AUTO_TEST_CASE (height_decrement) {
        unsigned int h_default = player->get_height_min() +
                (player->get_height_max() - player->get_height_min()) / 2;
        player->set_rel_height(-1);
        BOOST_CHECK(player->get_height() == h_default - 1);
    }

    BOOST_AUTO_TEST_CASE (height_increment_out_domain) {
        player->set_height(player->get_height_max());
        BOOST_CHECK_THROW(player->set_rel_height(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (height_decrement_out_domain) {
        player->set_height(player->get_height_min());
        BOOST_CHECK_THROW(player->set_rel_height(-1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_increment) {
        unsigned int h_default = player->get_width_min() +
                (player->get_width_max() - player->get_width_min()) / 2;
        player->set_rel_width(1);
        BOOST_CHECK(player->get_width() == h_default + 1);
    }

    BOOST_AUTO_TEST_CASE (width_decrement) {
        unsigned int h_default = player->get_width_min() +
                (player->get_width_max() - player->get_width_min()) / 2;
        player->set_rel_width(-1);
        BOOST_CHECK(player->get_width() == h_default - 1);
    }

    BOOST_AUTO_TEST_CASE (width_increment_out_domain) {
        player->set_width(player->get_width_max());
        BOOST_CHECK_THROW(player->set_rel_width(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_decrement_out_domain) {
        player->set_width(player->get_width_min());
        BOOST_CHECK_THROW(player->set_rel_width(-1), std::domain_error);
    }

    // Life
    BOOST_AUTO_TEST_CASE (default_values) {
        BOOST_REQUIRE(player->get_life() == player->get_total_life());
    }

    BOOST_AUTO_TEST_CASE (valid_life) {
        unsigned int zero = 0;
        player->set_life(zero);
        BOOST_REQUIRE(player->get_life() <= player->get_total_life());
        player->set_life(player->get_total_life());
        BOOST_REQUIRE(player->get_life() <= player->get_total_life());
    }

    BOOST_AUTO_TEST_CASE (life_increment) {
        int increment = 1;
        unsigned int zero = 0;
        player->set_life(zero);
        player->set_rel_life(increment);
        BOOST_CHECK(player->get_life() == zero + increment);
    }

    BOOST_AUTO_TEST_CASE (life_decrement) {
        int decrement = 1;
        player->set_life(player->get_total_life());
        player->set_rel_life(-decrement);
        BOOST_CHECK(player->get_life() == player->get_total_life() - decrement);
    }

    BOOST_AUTO_TEST_CASE (life_increment_out_domain) {
        player->set_life(player->get_total_life());
        BOOST_CHECK_THROW(player->set_rel_life(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (life_decrement_out_domain) {
        unsigned int zero = 0;
        player->set_life(zero);
        BOOST_CHECK_THROW(player->set_rel_life(-1), std::domain_error);
    }

BOOST_AUTO_TEST_SUITE_END()



BOOST_FIXTURE_TEST_SUITE (designer, StructDesigner)

    BOOST_AUTO_TEST_CASE (default_values_check) {
        BOOST_CHECK(player->get_height() >= player->get_height_min());
        BOOST_CHECK(player->get_height() <= player->get_height_max());
        BOOST_CHECK(player->get_width() >= player->get_width_min());
        BOOST_CHECK(player->get_width() <= player->get_width_max());
    }

    BOOST_AUTO_TEST_CASE(height_default) {
        unsigned int h = player->get_height_min() + (player->get_height_max() -
                player->get_height_min()) / 2;
        BOOST_CHECK(player->get_height() == h);
    }

    BOOST_AUTO_TEST_CASE(width_default) {
        unsigned int w = player->get_width_min() + (player->get_width_max() -
                player->get_width_min()) / 2;
        BOOST_CHECK(player->get_width() == w);
    }

    BOOST_AUTO_TEST_CASE (height_set_out_domain) {
        BOOST_CHECK_THROW(player->set_height(player->get_height_max() + 1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_set_out_domain) {
        BOOST_CHECK_THROW(player->set_width(player->get_width_max() + 1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (height_increment) {
        unsigned int h_default = player->get_height_min() +
                (player->get_height_max() - player->get_height_min()) / 2;
        player->set_rel_height(1);
        BOOST_CHECK(player->get_height() == h_default + 1);
    }

    BOOST_AUTO_TEST_CASE (height_decrement) {
        unsigned int h_default = player->get_height_min() +
                (player->get_height_max() - player->get_height_min()) / 2;
        player->set_rel_height(-1);
        BOOST_CHECK(player->get_height() == h_default - 1);
    }

    BOOST_AUTO_TEST_CASE (height_increment_out_domain) {
        player->set_height(player->get_height_max());
        BOOST_CHECK_THROW(player->set_rel_height(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (height_decrement_out_domain) {
        player->set_height(player->get_height_min());
        BOOST_CHECK_THROW(player->set_rel_height(-1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_increment) {
        unsigned int h_default = player->get_width_min() +
                (player->get_width_max() - player->get_width_min()) / 2;
        player->set_rel_width(1);
        BOOST_CHECK(player->get_width() == h_default + 1);
    }

    BOOST_AUTO_TEST_CASE (width_decrement) {
        unsigned int h_default = player->get_width_min() +
                (player->get_width_max() - player->get_width_min()) / 2;
        player->set_rel_width(-1);
        BOOST_CHECK(player->get_width() == h_default - 1);
    }

    BOOST_AUTO_TEST_CASE (width_increment_out_domain) {
        player->set_width(player->get_width_max());
        BOOST_CHECK_THROW(player->set_rel_width(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_decrement_out_domain) {
        player->set_width(player->get_width_min());
        BOOST_CHECK_THROW(player->set_rel_width(-1), std::domain_error);
    }

    // Life
    BOOST_AUTO_TEST_CASE (default_values) {
        BOOST_REQUIRE(player->get_life() == player->get_total_life());
    }

    BOOST_AUTO_TEST_CASE (valid_life) {
        unsigned int zero = 0;
        player->set_life(zero);
        BOOST_REQUIRE(player->get_life() <= player->get_total_life());
        player->set_life(player->get_total_life());
        BOOST_REQUIRE(player->get_life() <= player->get_total_life());
    }

    BOOST_AUTO_TEST_CASE (life_increment) {
        int increment = 1;
        unsigned int zero = 0;
        player->set_life(zero);
        player->set_rel_life(increment);
        BOOST_CHECK(player->get_life() == zero + increment);
    }

    BOOST_AUTO_TEST_CASE (life_decrement) {
        int decrement = 1;
        player->set_life(player->get_total_life());
        player->set_rel_life(-decrement);
        BOOST_CHECK(player->get_life() == player->get_total_life() - decrement);
    }

    BOOST_AUTO_TEST_CASE (life_increment_out_domain) {
        player->set_life(player->get_total_life());
        BOOST_CHECK_THROW(player->set_rel_life(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (life_decrement_out_domain) {
        unsigned int zero = 0;
        player->set_life(zero);
        BOOST_CHECK_THROW(player->set_rel_life(-1), std::domain_error);
    }

BOOST_AUTO_TEST_SUITE_END()



BOOST_FIXTURE_TEST_SUITE (hunterbug, StructHunterbug)

    BOOST_AUTO_TEST_CASE (default_values_check) {
        BOOST_CHECK(player->get_height() >= player->get_height_min());
        BOOST_CHECK(player->get_height() <= player->get_height_max());
        BOOST_CHECK(player->get_width() >= player->get_width_min());
        BOOST_CHECK(player->get_width() <= player->get_width_max());
    }

    BOOST_AUTO_TEST_CASE(height_default) {
        unsigned int h = player->get_height_min() + (player->get_height_max() -
                player->get_height_min()) / 2;
        BOOST_CHECK(player->get_height() == h);
    }

    BOOST_AUTO_TEST_CASE(width_default) {
        unsigned int w = player->get_width_min() + (player->get_width_max() -
                player->get_width_min()) / 2;
        BOOST_CHECK(player->get_width() == w);
    }

    BOOST_AUTO_TEST_CASE (height_set_out_domain) {
        BOOST_CHECK_THROW(player->set_height(player->get_height_max() + 1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_set_out_domain) {
        BOOST_CHECK_THROW(player->set_width(player->get_width_max() + 1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (height_increment) {
        unsigned int h_default = player->get_height_min() +
                (player->get_height_max() - player->get_height_min()) / 2;
        player->set_rel_height(1);
        BOOST_CHECK(player->get_height() == h_default + 1);
    }

    BOOST_AUTO_TEST_CASE (height_decrement) {
        unsigned int h_default = player->get_height_min() +
                (player->get_height_max() - player->get_height_min()) / 2;
        player->set_rel_height(-1);
        BOOST_CHECK(player->get_height() == h_default - 1);
    }

    BOOST_AUTO_TEST_CASE (height_increment_out_domain) {
        player->set_height(player->get_height_max());
        BOOST_CHECK_THROW(player->set_rel_height(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (height_decrement_out_domain) {
        player->set_height(player->get_height_min());
        BOOST_CHECK_THROW(player->set_rel_height(-1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_increment) {
        unsigned int h_default = player->get_width_min() +
                (player->get_width_max() - player->get_width_min()) / 2;
        player->set_rel_width(1);
        BOOST_CHECK(player->get_width() == h_default + 1);
    }

    BOOST_AUTO_TEST_CASE (width_decrement) {
        unsigned int h_default = player->get_width_min() +
                (player->get_width_max() - player->get_width_min()) / 2;
        player->set_rel_width(-1);
        BOOST_CHECK(player->get_width() == h_default - 1);
    }

    BOOST_AUTO_TEST_CASE (width_increment_out_domain) {
        player->set_width(player->get_width_max());
        BOOST_CHECK_THROW(player->set_rel_width(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (width_decrement_out_domain) {
        player->set_width(player->get_width_min());
        BOOST_CHECK_THROW(player->set_rel_width(-1), std::domain_error);
    }

    // Life
    BOOST_AUTO_TEST_CASE (default_values) {
        BOOST_REQUIRE(player->get_life() == player->get_total_life());
    }

    BOOST_AUTO_TEST_CASE (valid_life) {
        unsigned int zero = 0;
        player->set_life(zero);
        BOOST_REQUIRE(player->get_life() <= player->get_total_life());
        player->set_life(player->get_total_life());
        BOOST_REQUIRE(player->get_life() <= player->get_total_life());
    }

    BOOST_AUTO_TEST_CASE (life_increment) {
        int increment = 1;
        unsigned int zero = 0;
        player->set_life(zero);
        player->set_rel_life(increment);
        BOOST_CHECK(player->get_life() == zero + increment);
    }

    BOOST_AUTO_TEST_CASE (life_decrement) {
        int decrement = 1;
        player->set_life(player->get_total_life());
        player->set_rel_life(-decrement);
        BOOST_CHECK(player->get_life() == player->get_total_life() - decrement);
    }

    BOOST_AUTO_TEST_CASE (life_increment_out_domain) {
        player->set_life(player->get_total_life());
        BOOST_CHECK_THROW(player->set_rel_life(1), std::domain_error);
    }

    BOOST_AUTO_TEST_CASE (life_decrement_out_domain) {
        unsigned int zero = 0;
        player->set_life(zero);
        BOOST_CHECK_THROW(player->set_rel_life(-1), std::domain_error);
    }

BOOST_AUTO_TEST_SUITE_END()
