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

#ifndef SELECT_PLAYER_HPP
#define SELECT_PLAYER_HPP

#include <QtGui/QMainWindow>
#include <QtGui/QResizeEvent>

#include "irrlicht_widget.hpp"

namespace Ui {
    class SelectPlayer;
}

class SelectPlayer : public QMainWindow {
    Q_OBJECT

    public:
        explicit SelectPlayer(QWidget *parent=0);
        ~SelectPlayer();
        QIrrlichtWidget* get_irr_widget();

    private slots:
        void on_b_create_clicked();
        void on_height_valueChanged();
        void on_width_valueChanged();
        void on_height_sliderMoved(int value);
        void on_width_sliderMoved(int value);
        void on_comboBox_currentIndexChanged(int index);

    private:
        Ui::SelectPlayer *ui;
        QIrrlichtWidget irr_widget;
};

#endif
