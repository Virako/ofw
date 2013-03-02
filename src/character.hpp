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

#include "cte.hpp"
using namespace hw;


class Character {
    protected:
        unsigned int height;
        unsigned int width;
        unsigned int life;
        unsigned int total_life;

    public:
        /**
         * @brief Destructor default.
         */
        virtual ~Character() = 0;

        /**
         * @brief Get the current character's height.
         *
         * @return current character's height.
         */
        virtual unsigned int get_height(void);

        /**
         * @brief Get the current character's width.
         *
         * @return current character's width.
         */
        virtual unsigned int get_width(void);

        /**
         * @brief Set character's height checking if value is correct.
         *
         * @param height character's height
         */
        virtual void set_height(unsigned int height);

        /**
         * @brief Set character's width checking if value is correct.
         *
         * @param width character's width
         */
        virtual void set_width(unsigned int width);

        /**
         * @brief Get the current character's life.
         *
         * @return current character's life.
         */
        virtual unsigned int get_life(void);

        /**
         * @brief Get the current character's life.
         *
         * @return current character's life.
         */
        virtual unsigned int get_total_life(void);

        /**
         * @brief Set character's life checking if value is correct.
         *
         * @param life character's life
         */
        virtual void set_life(unsigned int life);

        /**
         * @brief Set character's life checking if value is correct.
         *
         * @param rel_life character's relative life. If negative sub life and if
         * positive add life.
         */
        virtual void set_rel_life(int rel_life);

};

inline unsigned int Character::get_height(void) {
    return this->height;
}

inline unsigned int Character::get_width(void) {
    return this->width;
}

inline unsigned int Character::get_life() {
    return this->life;
}

inline unsigned int Character::get_total_life() {
    return this->total_life;
}

#endif
