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

#include <irrlicht.h>
#include <QtCore/QDebug>
#include <QtGui/QMessageBox>
#include <QtGui/QResizeEvent>
#include <iostream>

#include "irrlicht_widget.hpp"
#include "../core.hpp"


QIrrlichtWidget::QIrrlichtWidget(QWidget *parent) : QWidget(parent) {
    this->setFocusPolicy(Qt::StrongFocus);
    this->setAttribute(Qt::WA_PaintOnScreen, true);
    //this->setAttribute(Qt::WA_TranslucentBackground, true);
    device = 0;
}

QIrrlichtWidget::~QIrrlichtWidget() {
    if (device != 0) {
        device->closeDevice();
        device->drop();
    }
}

void QIrrlichtWidget::init() {
    if (device != 0)
        return;

    static ofw::core::Core &c = ofw::core::Core::get_instance(
            irr::core::dimension2d<irr::u32>(height(), width()),
            (void*)((QWidget *)this)->winId());
    device = c.get_device();
    if(device) {
        camera = device->getSceneManager()->addCameraSceneNode(0,
                irr::core::vector3df(0,15,20), irr::core::vector3df(0,5,0));
    }
    connect(this, SIGNAL(update_irrlicht_query(irr::IrrlichtDevice*)), this,
            SLOT(update_irrlicht(irr::IrrlichtDevice*)));
    startTimer(0);
}

irr::IrrlichtDevice* QIrrlichtWidget::get_device() {
    return device;
}

void QIrrlichtWidget::paintEvent(QPaintEvent* event) {
    if(device != 0) {
        emit update_irrlicht_query(device);
    }
}

void QIrrlichtWidget::timerEvent(QTimerEvent* event) {
    if (device != 0) {
        emit update_irrlicht_query(device);
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

void QIrrlichtWidget::update_irrlicht( irr::IrrlichtDevice* device ) {
    if(device != 0) {
        device->getTimer()->tick();
        irr::video::SColor color (255,128,128,128);
        device->getVideoDriver()->beginScene(true, true, color);
        device->getSceneManager()->drawAll();
        device->getVideoDriver()->endScene();
    }
}
