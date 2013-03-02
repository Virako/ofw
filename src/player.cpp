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

#include <stdexcept>

#include "player.hpp"
#include "cte.hpp"
using namespace hw;


Player::Player(unsigned int height, unsigned int width) : Character(height, width) {
}

Player::~Player() {
}

void Player::set_rel_height(int rel_height) {
    this->set_height(this->get_height() + rel_height);
}

void Player::set_rel_width(int rel_width) {
    this->set_width(this->get_width() + rel_width);
}
