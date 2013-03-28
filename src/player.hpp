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

namespace ofw
{

namespace scene
{

class Player : public Character {
	public:
        /**
         * @brief Default constructor creating player with height and
         * width per default.
         */
        Player(unsigned int height=HEIGHT_DEFAULT, unsigned int width=HEIGHT_DEFAULT);

        /**
         * @brief Destructor default.
         */
        ~Player();

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

}

}
#endif
