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

#include "irrlicht.h"
#include <iostream>
#include <stdexcept>
#include <QtGui/QMessageBox>
#include <QtCore/QString>
#include <libintl.h>
#define _(x) gettext(x)

#include "select_player.hpp"
#include "ui_select_player.h"
#include "irrlicht_widget.hpp"
#include "../picacode.hpp"
#include "../hacker.hpp"
#include "../cracker.hpp"
#include "../designer.hpp"
#include "../hunterbug.hpp"


SelectPlayer::SelectPlayer(QWidget *parent) : QMainWindow(parent), ui(new Ui::SelectPlayer) {
    irr_widget = new QIrrlichtWidget(parent);
    ui->setupUi(this);
    irr_widget->setParent(ui->centralWidget);
    irr_widget->setGeometry(0, 0, 800, 600);
    this->resize(800, 600);
}

SelectPlayer::~SelectPlayer() {
    delete ui;
    delete player;
}

void SelectPlayer::init_default() {
    player = NULL;
    QString l_h = QString(_("height"));
    QString l_w = QString(_("width"));
    QString l_t = QString(_("texture"));
    QString b_c = QString(_("CREATE"));
    QString b_q = QString(_("Quit"));
    ui->l_height->setText(l_h);
    ui->l_width->setText(l_w);
    ui->l_texture->setText(l_t);
    ui->b_create->setText(b_c);
    ui->b_quit->setText(b_q);
    emit on_cb_name_textEdited(_("name"));
    emit on_comboBox_currentIndexChanged(0);
}

QIrrlichtWidget* SelectPlayer::get_irr_widget() {
    return irr_widget;
}

void SelectPlayer::on_b_create_clicked() {
    std::cout << "H: " << this->player->get_height() << " W:" << this->player->get_width()
            << " Name: " << this->player->get_name() << std::endl;
    QMessageBox messageBox;
    messageBox.critical(0,"Error","Not Yet implemented!");
    messageBox.setFixedSize(500,200);
}

void SelectPlayer::on_slider_height_valueChanged(int value) {
    if (player != NULL) {
        this->player->set_height(value);
    }
}

void SelectPlayer::on_slider_width_valueChanged(int value) {
    if (player != NULL) {
        this->player->set_width(value);
    }
}

void SelectPlayer::change_players_values() {
        ui->slider_height->setMinimum(this->player->get_height_min());
        ui->slider_height->setMaximum(this->player->get_height_max());
        ui->slider_width->setMinimum (this->player->get_width_min());
        ui->slider_width->setMaximum (this->player->get_width_max());
        //TODO put sliders in h and w per default
        QString descr = QString(this->player->get_description()->c_str());
        ui->text_description->setPlainText(descr);
}

void SelectPlayer::on_comboBox_currentIndexChanged(int index) {
    if (this->player != NULL) {
        delete this->player;
    }
    if (index == 0) {
        this->player = new ofw::scene::Picacode();
    }
    else if (index == 1) {
        this->player = new ofw::scene::Hacker();
    }
    else if (index == 2) {
        this->player = new ofw::scene::Cracker();
    }
    else if (index == 3) {
        this->player = new ofw::scene::Designer();
    }
    else if (index == 4) {
        this->player = new ofw::scene::Hunterbug();
    }
    else {
        throw std::domain_error("");
    }
    change_players_values();
    this->player->render(this->device);
}

void SelectPlayer::on_cb_name_textEdited(QString text) {
    if (player != NULL) {
        this->player->set_name(text.toStdString());
    }
    ui->cb_name->setPlaceholderText(text);
}
