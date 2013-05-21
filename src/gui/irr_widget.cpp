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

#include "irrlicht.h"
#include <QtCore/QDebug>
#include <QtGui/QMessageBox>
#include <QtGui/QResizeEvent>

#include "irr_widget.hpp"
#include "irr_event_sender.hpp"
#include "../core/core.hpp"


namespace ofw {
    namespace gui {

        QIrrlichtWidget::QIrrlichtWidget(QWidget *parent) : QWidget(parent) {
            this->setFocusPolicy(Qt::StrongFocus);
            this->setAttribute(Qt::WA_PaintOnScreen, true);
            //Ask QT to leave this widget unitialized, with no default filled background
            setAttribute( Qt::WA_OpaquePaintEvent );
            //this->setAttribute(Qt::WA_TranslucentBackground, true);
            this->device = 0;
        }

        QIrrlichtWidget::~QIrrlichtWidget() {
            if (this->device != 0) {
                this->device->closeDevice();
                this->device->drop();
            }
        }

        void QIrrlichtWidget::init() {
            if (this->device != 0)
                return;
            static ofw::core::Core &c = ofw::core::Core::get_instance(
                    irr::core::dimension2d<irr::u32>(height(), width()),
                    (void*)((QWidget *)this)->winId());
            this->device = c.get_device();
            // Temporal
            if(device) {
                camera = device->getSceneManager()->addCameraSceneNode(0,
                        irr::core::vector3df(0,15,20), irr::core::vector3df(0,5,0));
            }
            startTimer(0);
        }

        irr::IrrlichtDevice* QIrrlichtWidget::get_device() {
            return this->device;
        }

        bool QIrrlichtWidget::event(QEvent* event) {
            if(this->device != 0) {
               IrrEventSender irrES(this->device);
               irrES.sendEvent(event);
               event->ignore();
            }
            QWidget::event(event);
            return true;
        }
    }
}
