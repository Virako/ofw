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

#include "select_player.hpp"
#include "ui_select_player.h"
#include <QMessageBox>

SelectPlayer::SelectPlayer(QWidget *parent) : QMainWindow(parent), ui(new Ui::SelectPlayer) {
    ui->setupUi(this);
}

void SelectPlayer::on_b_create_clicked() {
    QMessageBox messageBox;
    messageBox.critical(0,"Error","Not Yet implemented!");
    messageBox.setFixedSize(500,200);
}

SelectPlayer::~SelectPlayer() {
    delete ui;
}
