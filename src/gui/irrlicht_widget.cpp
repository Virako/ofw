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


#include "driverChoice.h"
#include "irrlicht_widget.hpp"
#include <QtCore/QDebug>
#include <QMessageBox>
#include "ui_select_player.h"


QIrrlichtWidget::QIrrlichtWidget(QWidget *parent) : QWidget(parent) {
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setFocusPolicy(Qt::StrongFocus);
    setAutoFillBackground(false);
    device = 0;
}

QIrrlichtWidget::~QIrrlichtWidget() {
    if(device != 0) {
        device->closeDevice();
        device->drop();
    }
}

// Create the Irrlicht device and connect the signals and slots
void QIrrlichtWidget::init() {
    // Make sure we can't create the device twice
    if(device != 0)
        return;

    irr::video::E_DRIVER_TYPE driverType = irr::driverChoiceConsole();
    if (driverType == irr::video::EDT_COUNT)
        return;

    // Set all the device creation parameters
    SIrrlichtCreationParameters params;
    params.AntiAlias = 0;
    params.Bits = 32;
    params.DeviceType = EIDT_X11;
    params.Doublebuffer = true;
    params.DriverType = driverType;
    params.EventReceiver = 0;
    params.Fullscreen = false;
    params.HighPrecisionFPU = false;
    params.IgnoreInput = false;
    params.LoggingLevel = ELL_INFORMATION;
    params.Stencilbuffer = true;
    params.Stereobuffer = false;
    params.Vsync = false;
    // Specify which window/widget to render to
    params.WindowId = reinterpret_cast<void*>(this->winId());
    std::cout << params.WindowId << std::endl;
    //params.WindowId = (void*)ui->centralWidget->winId();
    params.WindowId = (void*)((QWidget *)this)->winId();
    std::cout << params.WindowId << std::endl;
    //params.WindowSize.Width = width();
    //params.WindowSize.Height = height();
    params.WithAlphaChannel = false;
    params.ZBufferBits = 16;

    // Create the Irrlicht Device with the previously specified parameters
    device = createDeviceEx(params);

    if(device) { // Create a camera so we can view the scene
        camera = device->getSceneManager()->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
    }

    // Connect the update signal (updateIrrlichtQuery) to the update slot (updateIrrlicht)
    connect(this, SIGNAL(updateIrrlichtQuery(IrrlichtDevice*)), this, SLOT(updateIrrlicht(IrrlichtDevice*)));

    // Start a timer. A timer with setting 0 will update as often as possible.
    startTimer(0);
}

IrrlichtDevice* QIrrlichtWidget::getIrrlichtDevice() {
    return device;
}

void QIrrlichtWidget::on_b_create_clicked() {
    QMessageBox messageBox;
    messageBox.critical(0,"Error","Not Yet implemented!");
    messageBox.setFixedSize(500,200);
}

void QIrrlichtWidget::paintEvent(QPaintEvent* event) {
    if(device != 0) {
        emit updateIrrlichtQuery(device);
    }
}

void QIrrlichtWidget::timerEvent(QTimerEvent* event) {
    // Emit the render signal each time the timer goes off
    if (device != 0) {
        emit updateIrrlichtQuery(device);
    }
    event->accept();
}

void QIrrlichtWidget::resizeEvent(QResizeEvent* event) {
    if(device != 0) {
        dimension2d<u32> widgetSize;
        widgetSize.Width = event->size().width();
        widgetSize.Height = event->size().height();
        device->getVideoDriver()->OnResize(widgetSize);
        ICameraSceneNode *cam = device->getSceneManager()->getActiveCamera();
        if (cam != 0) {
            cam->setAspectRatio((f32)widgetSize.Height / (f32)widgetSize.Width);
        }
    }
    QWidget::resizeEvent(event);
}

void QIrrlichtWidget::updateIrrlicht( irr::IrrlichtDevice* device ) {
    if(device != 0) {
        device->getTimer()->tick();
        SColor color (255,100,100,140);
        device->getVideoDriver()->beginScene(true, true, color);
        device->getSceneManager()->drawAll();
        device->getVideoDriver()->endScene();
    }
}
