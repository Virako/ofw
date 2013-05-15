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

#include <libintl.h>
#define _(x) gettext(x)

#include "designer.hpp"


namespace ofw {
    namespace scene {

        Designer::Designer() {
            this->HEIGHT_MIN = 80;
            this->HEIGHT_MAX = 120;
            this->WIDTH_MIN = 90;
            this->WIDTH_MAX = 110;
            this->height = HEIGHT_MIN + (HEIGHT_MAX - HEIGHT_MIN)/2;
            this->width = WIDTH_MIN + (WIDTH_MAX - WIDTH_MIN)/2;
            this->life = 100;
            this->total_life = 100;
            this->character = NULL;
            this->num_mesh = 0;
            this->num_texture = 0;
            this->DESCRIPTION = new std::string(_("Designer: wizard. "));
            this->MESHES.push_back(std::string("/media/sydney.md2"));
            this->mesh = this->MESHES.front();
            this->TEXTURES.push_back(std::string("/media/sydney.png"));
            this->texture = this->TEXTURES.front();
        }

        Designer::~Designer() {
        }

    }
}
