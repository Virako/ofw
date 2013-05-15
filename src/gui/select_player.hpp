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

#ifndef __SELECT_PLAYER_HPP
#define __SELECT_PLAYER_HPP

#include <QtGui/QMainWindow>

namespace Ui {
    class SelectPlayer;
}

namespace irr {
    class IrrlichtDevice;
}

namespace ofw {
    namespace scene {
        class Player;
    }
}

class QIrrlichtWidget;
class QString;


/**
 * @brief Handler SelectPlayer gui
 */
class SelectPlayer : public QMainWindow {
    Q_OBJECT

    private:
        Ui::SelectPlayer *ui;
        QIrrlichtWidget *irr_widget;
        std::string name;
        ofw::scene::Player *player;
        irr::IrrlichtDevice *device;

    public:
        /**
         * @brief Create default values in the gui.
         *
         * @param parent
         */
        SelectPlayer(QWidget *parent=0);

        /**
         * @brief Desctructor
         */
        ~SelectPlayer();

        /**
         * @brief Get irr_widget
         *
         * @return irr_widget
         */
        QIrrlichtWidget* get_irr_widget();

        /**
         * @brief Changes values of sliders from player's values.
         *
         * @param p Player
         */
        void change_players_values();

        void set_device(irr::IrrlichtDevice *device);
        void init_default();

    private slots:
        /**
         * @brief Button b_create is pressed
         */
        void on_b_create_clicked();

        /**
         * @brief Value of QSlider slider_height has changed
         *
         * @param value value of height
         */
        void on_slider_height_valueChanged(int value);

        /**
         * @brief Value of QSlider slider_width has changed
         *
         * @param value value of width
         */
        void on_slider_width_valueChanged(int value);

        /**
         * @brief Value ofcomboBox has changed
         *
         * @param index index of combobox
         */
        void on_comboBox_currentIndexChanged(int index);

        /**
         * @brief TextBox is changed
         *
         * @param text New text in the textBox
         */
        void on_cb_name_textEdited(QString text);
};

inline void SelectPlayer::set_device(irr::IrrlichtDevice *device) {
    this->device = device;
}

#endif
