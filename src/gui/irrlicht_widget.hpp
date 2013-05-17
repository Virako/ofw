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

#ifndef IRRLICHT_WIDGET_HPP
#define IRRLICHT_WIDGET_HPP

#include <QtGui/QWidget>

namespace irr {
    class IrrlichtDevice;
    namespace scene {
        class ICameraSceneNode;
    }
    namespace video {
        class IVideoDriver;
    }
}


namespace ofw {
    namespace gui {

        /**
         * @brief QWidget for integrate Irrlicht
         */
        class QIrrlichtWidget : public QWidget {
            Q_OBJECT

            protected:
                /**
                 * @brief Device
                 */
                irr::IrrlichtDevice *device;

                /**
                 * @brief irrlicht driver
                 */
                irr::video::IVideoDriver *driver;

                /**
                 * @brief Camera
                 */
                irr::scene::ICameraSceneNode* camera;

                /**
                 * @brief Update the QIrrlichtWidget
                 *
                 * @param event
                 */
                virtual void paintEvent(QPaintEvent* event);

                /**
                 * @brief Update the QIrrlichtWidget
                 *
                 * @param event
                 */
                virtual void timerEvent(QTimerEvent* event);

                /**
                 * @brief Resize the widget with the window
                 *
                 * @param event
                 */
                virtual void resizeEvent(QResizeEvent* event);

            public:
                /**
                 * @brief Constructor QIrrlichtWidget. Select way of painting.
                 *
                 * @param parent
                 */
                QIrrlichtWidget(QWidget *parent = 0);

                /**
                 * @brief Destructor
                 */
                ~QIrrlichtWidget();

                /**
                 * @brief Get IrrlichtDevice
                 *
                 * @return IrrlichtDevice
                 */
                irr::IrrlichtDevice* get_device();

                /**
                 * @brief Init the core
                 */
                void init();

            signals:
                /**
                 * @brief Emit the signal that connects with the slot update_irrlicth.
                 *
                 * @param device IrrlichtDevice
                 */
                void update_irrlicht_query(irr::IrrlichtDevice* device);

            public slots:
                /**
                 * @brief Refresh the irrlicht widget.
                 *
                 * @param device IrrlichtDevice
                 */
                void update_irrlicht(irr::IrrlichtDevice* device);
        };

    }
}
#endif
