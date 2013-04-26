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


namespace irr {
    class IrrlichtDevice;
    typedef unsigned int u32;
    namespace core {
        template <class T>
        class dimension2d;
    }
}


namespace ofw {

    namespace core {

        /**
         * @brief Init the i18n.
         */
        void init_i18n();

        /**
         * @brief Singleton class
         */
        class Core {
            private:
                irr::IrrlichtDevice* device;

                Core(irr::core::dimension2d<irr::u32> window_size, void* window_id=0);
                Core(const Core&);
                void operator=(const Core&);

            public:

                /**
                 * @brief Static method that get a instance of core.
                 *
                 * @param window_size windows size. (800x600)
                 * @param window_id if 0, irrlicht execute in a separate windows, else, irrlicht
                 * execute inside window.
                 *
                 * @return Core object
                 */
                static Core& get_instance(irr::core::dimension2d<irr::u32> window_size,
                        void* window_id=0);

                /**
                 * @brief Get irrlicht device
                 *
                 * @return irrlicht device
                 */
                irr::IrrlichtDevice* get_device();
        };
    }
}

#endif
