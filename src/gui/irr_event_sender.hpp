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

#ifndef IRR_EVENT_SENDER__HPP
#define IRR_EVENT_SENDER__HPP

class QEvent;
class QMouseEvent;
class QPaintEvent;
class QResizeEvent;
class QTimerEvent;
namespace irr {
    class IrrlichtDevice;
}

namespace ofw {
    namespace gui {

        class irrEventSender {

            private:
                irr::IrrlichtDevice* device;
                /**
                 * @brief Sends the QMouseEvent to Irrlicht.
                 *
                 * @param event Event to be sended to Irrlicht.
                 */
                void sendMouseEvent(QMouseEvent* event);
                /**
                 * @brief Handles the QTimerEvent.
                 *
                 * @param event QTimerEvent.
                 */
                void sendTimeEvent(QTimerEvent* event);
                /**
                 * @brief Handles the QPaintEvent.
                 *
                 * @param event QPaintEvent.
                 */
                void sendPaintEvent(QPaintEvent* event);
                /**
                 * @brief Handles the QResizeEvent.
                 *
                 * @param event QResizeEvent.
                 */
                void sendResizeEvent(QResizeEvent* event);
                /**
                 * @brief Updates the irrlicht widget.
                 *
                 * @param device Device that rules the widget.
                 */
                void update_irrlicht(irr::IrrlichtDevice* device);

            public:
                /**
                 * @brief Constructor.
                 *
                 * @param device Device that handle the window that is going to
                 * recieve the event.
                 */
                irrEventSender(irr::IrrlichtDevice* device);
                /**
                 * @brief General sender, that handle the event, and calls the
                 * specific sender.
                 *
                 * @param event Event to be send to Irrlicht.
                 */
                bool sendEvent(QEvent* event);
        };
    }
}

#endif
