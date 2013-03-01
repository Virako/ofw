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

#ifndef __CHARACTER_H
#define __CHARACTER_H

#include <string>
using namespace std;


class Character {
	private:
        int height;
        int width;

	public:
        /**
         * @brief Default constructor creating character with height and width
         * per default.
         */
        Character();

        /**
         * @brief Destructor default.
         */
        ~Character();

        /**
         * @brief Get the current character's height.
         *
         * @return current character's height.
         */
        int get_height(void);

        /**
         * @brief Get the current character's width.
         *
         * @return current character's width.
         */
        int get_width(void);

        /**
         * @brief Set character's height checking if value is correct.
         *
         * @param height character's height
         */
        void set_height(int height);

        /**
         * @brief Set character's width checking if value is correct.
         *
         * @param width character's width
         */
        void set_width(int width);

};

inline int Character::get_height(void) {
    return this->height;
}

inline int Character::get_width(void) {
    return this->width;
}

#endif
