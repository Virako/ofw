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

#ifndef __CORE_H
#define __CORE_H

#include "irrlicht.h"

namespace ofw {

namespace core {
    irr::video::E_DRIVER_TYPE init_driver(bool gui=false);
    irr::IrrlichtDevice* init_device(
            irr::core::dimension2d<irr::u32> window_size,
            irr::video::E_DRIVER_TYPE driver=irr::video::EDT_NULL,
            void* window_id=0);

    class Core {
        private:
            irr::video::E_DRIVER_TYPE driver;
            irr::IrrlichtDevice* device;

            Core(irr::video::E_DRIVER_TYPE driver, irr::IrrlichtDevice* device);
            Core(const Core&);
            void operator=(const Core&);

        public:
            static Core& get_instance(irr::video::E_DRIVER_TYPE driver,
                    irr::IrrlichtDevice* device);
    };

}

}

#endif
