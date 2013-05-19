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

#include "irr_event_sender.hpp"
#include "irrlicht.h"
#include <QtGui/QMouseEvent>
#include <QtGui/QResizeEvent>
#include <QtGui/QPaintEvent>
#include <QtCore/QTimerEvent>

namespace ofw {
    namespace gui {

        irrEventSender::irrEventSender(irr::IrrlichtDevice* device) {
            this->device = device;
        }

        bool irrEventSender::sendEvent(QEvent* event) {
            bool event_taked = false;
            if (event != NULL) {

                QMouseEvent* mouseEvent = dynamic_cast<QMouseEvent*>(event);
                if(mouseEvent != NULL && event_taked != true) {
                    sendMouseEvent(mouseEvent);
                    event_taked = true;
                }
                QPaintEvent* paintEvent = dynamic_cast<QPaintEvent*>(event);
                if(paintEvent != NULL && event_taked != true) {
                    sendPaintEvent(paintEvent);
                    event_taked = true;
                }
                QTimerEvent* timeEvent = dynamic_cast<QTimerEvent*>(event);
                if(timeEvent != NULL && event_taked != true) {
                    sendTimeEvent(timeEvent);
                    event_taked = true;
                }
                QResizeEvent* resizeEvent = dynamic_cast<QResizeEvent*>(event);
                if(resizeEvent != NULL && event_taked != true) {
                    sendResizeEvent(resizeEvent);
                    event_taked = true;
                }
            }
            return event_taked;
        }

        void irrEventSender::sendMouseEvent(QMouseEvent* event) {
            if(event->type() == QEvent::Type::MouseButtonRelease)
                return;

            irr::SEvent irrEvent;

            irrEvent.EventType = irr::EET_MOUSE_INPUT_EVENT;

            if (event->button() == Qt::LeftButton) {
                irrEvent.MouseInput.Event = irr::EMIE_LMOUSE_PRESSED_DOWN;
            }else {
                irrEvent.MouseInput.Event = irr::EMIE_RMOUSE_PRESSED_DOWN;
            }

            irrEvent.MouseInput.X = event->x();
            irrEvent.MouseInput.Y = event->y();
            irrEvent.MouseInput.Wheel = 0.0f;

            this->device->postEventFromUser(irrEvent);
        }

        void irrEventSender::sendPaintEvent(QPaintEvent* event) {
            update_irrlicht(device);
        }

        void irrEventSender::sendTimeEvent(QTimerEvent* event) {
            update_irrlicht(device);
            event->accept();
        }

        void irrEventSender::sendResizeEvent(QResizeEvent* event) {
            irr::core::dimension2d<irr::u32> widgetSize;
            widgetSize.Width = event->size().width();
            widgetSize.Height = event->size().height();
            device->getVideoDriver()->OnResize(widgetSize);
            irr::scene::ICameraSceneNode *cam = device->getSceneManager()->getActiveCamera();
            if (cam != 0) {
                cam->setAspectRatio((irr::f32)widgetSize.Height / (irr::f32)widgetSize.Width);
            }
        }

        void irrEventSender::update_irrlicht(irr::IrrlichtDevice* device) {
            if(device != 0) {
                device->getTimer()->tick();
                irr::video::SColor color (255,128,128,128);
                device->getVideoDriver()->beginScene(true, true, color);
                device->getSceneManager()->drawAll();
                device->getGUIEnvironment()->drawAll();
                device->getVideoDriver()->endScene();
            }
        }
    }
}
