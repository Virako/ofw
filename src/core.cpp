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

#include "driverChoice.h"
#include <iostream>

#include "core.hpp"


namespace ofw {

    namespace core {

        Core::Core(irr::core::dimension2d<irr::u32> window_size, void* window_id) {
            irr::SIrrlichtCreationParameters params;
            params.AntiAlias = 0;
            params.Bits = 32;
            params.DeviceType = irr::EIDT_BEST;
            //params.DriverMultithreaded = true;
            params.DriverType = irr::driverChoiceConsole();
            params.EventReceiver = 0;
            params.Fullscreen = false;
            params.HighPrecisionFPU = false;
            params.IgnoreInput = false;
            //params.LoggingLevel = irr::ELL_DEBUG;
            params.Stencilbuffer = true;
            params.Stereobuffer = false;
            params.Vsync = false;
            //params.WindowId = reinterpret_cast<void*>(this->winId());
            params.WindowId = window_id;
            params.WindowSize = window_size;
            params.WithAlphaChannel = true;
            this->device = irr::createDeviceEx(params);
        }

        Core& Core::get_instance(irr::core::dimension2d<irr::u32> window_size, void* window_id) {
            static Core core(window_size, window_id);
            return core;
        }

        irr::IrrlichtDevice* Core::get_device() {
            return device;
        }

    }
}
