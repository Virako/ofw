/*************************************************************************
* Open Fantasy World is a MMORPG where the players will live in community.
* Copyright (C) 2012-2013 Javier Jaramago Fernández
* <jaramago.fernandez.javier@gmail.com>
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

#ifndef __SectorObserver_H
#define __SectorObserver_H

//External libraries.
#include <list>

//OFW dependences.
#include "characterobserver.hpp"
#include "objectobserver.hpp"


namespace ofw {
    namespace scene {

        enum ElementType {
            CHARACTER, PLAYER, NPC, CRACKER, HACKER, HUNTERBUG,
            DESIGNER, PICACODE, ENVIROMENT_OBJECT, GENERAL_ITEM
        };

        class SectorObserver : public OFWObserver {
            private:
                std::list<CharacterObserver> characters_observers;
                std::list<ObjectObserver> objects_observers;

            public:
                void update();
        };

    }
}
#endif
