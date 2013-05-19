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

#ifndef IRRLICHT_EVENT_RECEIVER_HPP
#define IRRLICHT_EVENT_RECEIVER_HPP

#include "IEventReceiver.h"

namespace ofw {
    namespace gui {
        class SMouseState;
    }
}

namespace ofw {
    namespace gui {

        class irrEventReceiver : public irr::IEventReceiver {
            private:
                irr::SEvent::SJoystickEvent JoystickState;

            public:
                /**
                 * @brief Default constructor.
                 */
                irrEventReceiver();
                /**
                 * @brief Handles the events that Irrlicth recieves from the
                 * windows system.
                 *
                 * @param event Event that need to be handle.
                 *
                 * @return returns true when the events has been completely
                 * handled, if not return false.
                 */
                virtual bool OnEvent(const irr::SEvent& event);
                /**
                 * @brief Get the actual joystick state.
                 *
                 * @return Joystick state.
                 */
                const irr::SEvent::SJoystickEvent& GetJoystickState(void) const;
                /**
                 * @brief Get the actual mouse state.
                 *
                 * @return Mouse state.
                 */
                const SMouseState& GetMouseState(void) const;
        };
    }
}

#endif
