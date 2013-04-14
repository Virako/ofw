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

#include <iostream>
using namespace std;
#include <QtGui/QMessageBox>

#include "select_player.hpp"
#include "ui_select_player.h"

SelectPlayer::SelectPlayer(QWidget *parent) : QMainWindow(parent), ui(new Ui::SelectPlayer) {
    ui->setupUi(this);
    irr_widget.setParent(ui->centralWidget);
    irr_widget.setGeometry(0, 0, 800, 600);
    this->resize(800, 600);
}

SelectPlayer::~SelectPlayer() {
    delete ui;
}

QIrrlichtWidget* SelectPlayer::get_irr_widget() {
    return &irr_widget;
}

void SelectPlayer::on_b_create_clicked() {
    QMessageBox messageBox;
    messageBox.critical(0,"Error","Not Yet implemented!");
    messageBox.setFixedSize(500,200);
}

void SelectPlayer::on_height_valueChanged() {
    cout << "aro" << endl;
}

void SelectPlayer::on_width_valueChanged() {
    cout << "no aro" << endl;
}

void SelectPlayer::on_height_sliderMoved(int value) {
    cout << "V: " << value << endl;
}

void SelectPlayer::on_width_sliderMoved(int value) {
    cout << "V2: " << value << endl;
}

void SelectPlayer::on_comboBox_currentIndexChanged(int index) {
    cout << "index = " << index << endl;
    if (index == 0) {
        ui->height->setMinimum(80);
        ui->height->setMaximum(120);
    }
    else if (index == 1) {
        ui->height->setMinimum(80);
        ui->height->setMaximum(120);
    }
    else if (index == 2) {
        ui->height->setMinimum(80);
        ui->height->setMaximum(120);
    }
    else if (index == 3) {
        ui->height->setMinimum(80);
        ui->height->setMaximum(120);
    }
    else if (index == 4) {
        ui->height->setMinimum(80);
        ui->height->setMaximum(120);
    }
    else {
        cout << "Indice en: " << index << endl;
    }

}
