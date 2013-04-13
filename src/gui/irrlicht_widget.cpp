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


#include <QtCore/QDebug>
#include <QMessageBox>
#include "driverChoice.h"

#include "irrlicht_widget.hpp"


QIrrlichtWidget::QIrrlichtWidget(QWidget *parent) : QWidget(parent) {
    this->setFocusPolicy(Qt::StrongFocus);
    this->setAttribute(Qt::WA_PaintOnScreen, true);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    device = 0;
}

QIrrlichtWidget::~QIrrlichtWidget() {
    if(device != 0) {
        device->closeDevice();
        device->drop();
    }
}

void QIrrlichtWidget::init() {
    if(device != 0)
        return;
    irr::video::E_DRIVER_TYPE driverType = irr::driverChoiceConsole();
    if (driverType == irr::video::EDT_COUNT)
        return;

    irr::SIrrlichtCreationParameters params;
    params.AntiAlias = 0;
    params.Bits = 32;
    params.DeviceType = irr::EIDT_X11;
    params.DriverMultithreaded = true;
    params.DriverType = driverType;
    params.EventReceiver = 0;
    params.Fullscreen = false;
    params.HighPrecisionFPU = false;
    params.IgnoreInput = false;
    params.LoggingLevel = irr::ELL_DEBUG;
    params.Stencilbuffer = true;
    params.Stereobuffer = false;
    params.Vsync = false;
    //params.WindowId = reinterpret_cast<void*>(this->winId());
    params.WindowId = (void*)((QWidget *)this)->winId();
    params.WindowSize.Width = width();
    params.WindowSize.Height = height();
    params.WithAlphaChannel = true;

    device = irr::createDeviceEx(params);

    if(device) {
        camera = device->getSceneManager()->addCameraSceneNode(0,
                irr::core::vector3df(0,30,-40), irr::core::vector3df(0,5,0));
    }

    connect(this, SIGNAL(updateIrrlichtQuery(irr::IrrlichtDevice*)), this,
            SLOT(updateIrrlicht(irr::IrrlichtDevice*)));

    // Start a timer. A timer with setting 0 will update as often as possible.
    startTimer(0);
}

irr::IrrlichtDevice* QIrrlichtWidget::getIrrlichtDevice() {
    return device;
}

void QIrrlichtWidget::paintEvent(QPaintEvent* event) {
    if(device != 0) {
        emit updateIrrlichtQuery(device);
    }
}

void QIrrlichtWidget::timerEvent(QTimerEvent* event) {
    if (device != 0) {
        emit updateIrrlichtQuery(device);
    }
    event->accept();
}

void QIrrlichtWidget::resizeEvent(QResizeEvent* event) {
    if(device != 0) {
        irr::core::dimension2d<irr::u32> widgetSize;
        widgetSize.Width = event->size().width();
        widgetSize.Height = event->size().height();
        device->getVideoDriver()->OnResize(widgetSize);
        irr::scene::ICameraSceneNode *cam = device->getSceneManager()->getActiveCamera();
        if (cam != 0) {
            cam->setAspectRatio((irr::f32)widgetSize.Height / (irr::f32)widgetSize.Width);
        }
    }
    QWidget::resizeEvent(event);
}

void QIrrlichtWidget::updateIrrlicht( irr::IrrlichtDevice* device ) {
    if(device != 0) {
        device->getTimer()->tick();
        irr::video::SColor color (255,128,128,128);
        device->getVideoDriver()->beginScene(true, true, color);
        device->getSceneManager()->drawAll();
        device->getVideoDriver()->endScene();
    }
}
