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


class QIrrlichtWidget : public QWidget {
    Q_OBJECT

    public:
        explicit QIrrlichtWidget(QWidget *parent = 0);
        ~QIrrlichtWidget();
        irr::IrrlichtDevice* getIrrlichtDevice();
        void init();

    signals:
        void updateIrrlichtQuery(irr::IrrlichtDevice* device);

    public slots:
        void updateIrrlicht(irr::IrrlichtDevice* device);

    protected:
        virtual void paintEvent(QPaintEvent* event);
        virtual void timerEvent(QTimerEvent* event);
        virtual void resizeEvent(QResizeEvent* event);
        irr::IrrlichtDevice *device;
        irr::scene::ICameraSceneNode* camera;
};

#endif
