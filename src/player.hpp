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

#ifndef __PLAYER_H
#define __PLAYER_H

#include "character.hpp"


class Player : public Character {
	private:
        int life;
        int total_life;

	public:
        /**
         * @brief Default constructor creating player with height and
         * width per default.
         */
        Player();

        /**
         * @brief Destructor default.
         */
        ~Player();

        /**
         * @brief Get the current player's life.
         *
         * @return current player's life.
         */
        int get_life(void);

        /**
         * @brief Get the current player's life.
         *
         * @return current player's life.
         */
        int get_total_life(void);

        /**
         * @brief Set player's life checking if value is correct.
         *
         * @param life player's life
         */
        void set_life(int life);

        /**
         * @brief Set player's life checking if value is correct.
         *
         * @param rel_life player's relative life. If negative sub life and if
         * positive add life.
         */
        void set_rel_life(int rel_life);

        /**
         * @brief Set player's relative height.
         *
         * @param rel_height player's relative height. If negative sub height
         * and if positive add height.
         */
        void set_rel_height(int rel_height);

        /**
         * @brief Set player's relative width.
         *
         * @param rel_width player's relative width. If negative sub width
         * and if positive add width.
         */
        void set_rel_width(int rel_width);

};

inline int Player::get_life() {
    return this->life;
}

inline int Player::get_total_life() {
    return this->total_life;
}

#endif
