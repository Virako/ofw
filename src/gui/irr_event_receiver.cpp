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

#include "irrlicht.h"
#include "irr_event_receiver.hpp"
#include <iostream>

namespace ofw {
    namespace gui {

        struct SMouseState
        {
            irr::core::position2di Position;
            bool LeftButtonDown;
            SMouseState() : LeftButtonDown(false) { }
        } MouseState;

        bool irrEventReceiver::OnEvent(const irr::SEvent& event) {
            if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
                switch(event.MouseInput.Event)
                {
                    case irr::EMIE_LMOUSE_PRESSED_DOWN:
                        MouseState.LeftButtonDown = true;
                        break;

                    case irr::EMIE_LMOUSE_LEFT_UP:
                        MouseState.LeftButtonDown = false;
                        break;

                    case irr::EMIE_MOUSE_MOVED:
                        MouseState.Position.X = event.MouseInput.X;
                        MouseState.Position.Y = event.MouseInput.Y;

                    default:
                        break;
                }
            }

            if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 0) {
                JoystickState = event.JoystickEvent;
            }

            return false;
        }

        const irr::SEvent::SJoystickEvent& irrEventReceiver::GetJoystickState(void) const {
            return JoystickState;
        }

        const SMouseState& irrEventReceiver::GetMouseState(void) const {
            return MouseState;
        }


        irrEventReceiver::irrEventReceiver() {
        }
    }
}
