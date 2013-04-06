/*************************************************************************
 * * Open Fantasy World is a MMORPG where the players will live in community.
 * * Copyright (C) 2012-2013 Javier Jaramago Fernández
 * * <jaramago.fernandez.javier@gmail.com>
 * *
 * * This program is free software: you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License as published by
 * * the Free Software Foundation, either version 3 of the License, or
 * * (at your option) any later version.
 * *
 * * Foobar is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 * */

#ifndef __SECTOR_H
#define __SECTOR_H

#include <utility>
#include "sectorobserver.hpp"

namespace ofw
{

namespace scene
{

/**
 * @brief Sectors are the areas in which the map is divided, their dimmesions
 * are not fixed, and obey to the terrain conditions.
 */
class Sector {
    private:
        std::pair<int, int> fc;
        std::pair<int, int> sc;
        SectorObserver observer;

    public:
        /**
         * @brief Constructor.
         */
        Sector(std::pair<int, int> fc, std::pair<int,int> sc, SectorObserver observer);

        /**
         * @brief Destructor.
         */
        ~Sector();

        /**
         * @brief Returns the sector observer.
         *
         * @return SectorObserver.
         */
        SectorObserver get_sector_observer() const;
};

inline SectorObserver Sector::get_sector_observer() const {
    return this->observer;
}

}

}

#endif
