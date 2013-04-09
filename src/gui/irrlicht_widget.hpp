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


#ifndef QIRRLICHTWIDGET_HPP
#define QIRRLICHTWIDGET_HPP

#include <QWidget>
#include <QResizeEvent>
#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;

// Our Irrlicht rendering widget
// To have everything compile, we need to run MOC on this file
class QIrrlichtWidget : public QWidget {
    // Macro for the meta-object compiler MOC
    Q_OBJECT

    public:
        explicit QIrrlichtWidget(QWidget *parent = 0);
        ~QIrrlichtWidget();

        // Returns a pointer to the Irrlicht Device
        IrrlichtDevice* getIrrlichtDevice();

        // Create the Irrlicht device and connect the signals and slots
        void init();

    signals:
        // Signal that its time to update the frame
        void updateIrrlichtQuery(IrrlichtDevice* device);

    private slots:
        void on_b_create_clicked();

    public slots:
        // Function called in response to updateIrrlichtQuery. Renders the scene in the widget
        void updateIrrlicht(IrrlichtDevice* device);

    protected:
        virtual void paintEvent(QPaintEvent* event);
        virtual void timerEvent(QTimerEvent* event);
        virtual void resizeEvent(QResizeEvent* event);

        IrrlichtDevice *device;
        // We keep the camera inside this widget so we can resize the window dynamically
        ICameraSceneNode* camera;
};

#endif
