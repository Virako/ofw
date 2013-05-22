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
#include <stdexcept>
#include <QtGui/QMessageBox>
#include <QtCore/QString>
#include <libintl.h>
#define _(x) gettext(x)

#include "select_player.hpp"
#include "ui_select_player.h"
#include "irr_widget.hpp"
#include "../ofw_config.hpp"
#include "../scene/picacode.hpp"
#include "../scene/hacker.hpp"
#include "../scene/cracker.hpp"
#include "../scene/designer.hpp"
#include "../scene/hunterbug.hpp"
#include "../client/client.hpp"


namespace ofw {
    namespace gui {

        SelectPlayer::SelectPlayer(QWidget *parent) :
                QMainWindow(parent), ui(new Ui::SelectPlayer) {
            this->irr_widget = new ofw::gui::QIrrlichtWidget(parent);
            this->ui->setupUi(this);
            this->irr_widget->setParent(this->ui->centralWidget);
            this->irr_widget->setGeometry(0, 0, 800, 600);
            this->resize(800, 600);
        }

        SelectPlayer::~SelectPlayer() {
            delete this->ui;
            delete this->player;
        }

        void SelectPlayer::init_default() {
            this->player = NULL;
            this->put_logo();
            QString l_h = QString(_("height"));
            QString l_w = QString(_("width"));
            QString l_t = QString(_("texture"));
            QString b_c = QString(_("CREATE"));
            QString b_q = QString(_("Quit"));
            this->ui->l_height->setText(l_h);
            this->ui->l_width->setText(l_w);
            this->ui->l_texture->setText(l_t);
            ui->b_create->setText(b_c);
            ui->b_quit->setText(b_q);
            emit on_cb_name_textEdited(_("name"));
            emit on_comboBox_currentIndexChanged(0);
        }

        ofw::gui::QIrrlichtWidget* SelectPlayer::get_irr_widget() {
            return this->irr_widget;
        }

        void SelectPlayer::on_b_create_clicked() {
            ofw::client::Client *cli = new ofw::client::Client();
            cli->send_player(this->player, this->ui->slider_texture->value(),
                    this->ui->comboBox->currentIndex());
        }

        void SelectPlayer::on_slider_height_valueChanged(int value) {
            if (this->player != NULL) {
                this->player->set_height(value);
            }
        }

        void SelectPlayer::on_slider_width_valueChanged(int value) {
            if (this->player != NULL) {
                this->player->set_width(value);
            }
        }

        void SelectPlayer::on_slider_texture_valueChanged(int value) {
            if (this->player != NULL) {
                this->player->set_texture(value);
            }
        }

        void SelectPlayer::change_players_values() {
            this->ui->slider_height->setRange(this->player->get_height_min(),
                    this->player->get_height_max());
            this->ui->slider_height->setValue(this->player->get_height());
            this->ui->slider_width->setRange(this->player->get_width_min(),
                    this->player->get_width_max());
            this->ui->slider_width->setValue(this->player->get_width());
            this->ui->slider_texture->setRange(0, this->player->get_texture_lenght() - 1);
            this->ui->slider_texture->setValue(0);
            emit on_slider_texture_valueChanged(0);
            QString descr = QString(this->player->get_description()->c_str());
            this->ui->text_description->setPlainText(descr);
            emit on_cb_name_textEdited(this->ui->cb_name->text());
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
            this->player->create_scene_node(this->device);
            change_players_values();
        }

        void SelectPlayer::on_cb_name_textEdited(QString text) {
            if (this->player != NULL) {
                this->player->set_name(text.toStdString());
            }
            ui->cb_name->setText(text);
        }

        void SelectPlayer::put_logo() {
            irr::gui::IGUIImage *img = this->device->getGUIEnvironment()->addImage(
                    this->device->getVideoDriver()->getTexture(
                    (ofw::datadir + "/" + "media/logo.png").c_str()),
                    irr::core::position2d<irr::s32>(this->height() - 10, 10));
            img->setAlignment(irr::gui::EGUIA_LOWERRIGHT, irr::gui::EGUIA_LOWERRIGHT,
                    irr::gui::EGUIA_UPPERLEFT, irr::gui::EGUIA_UPPERLEFT);
        }

        void SelectPlayer::resizeEvent(QResizeEvent* event) {
            this->ui->centralWidget->resize(this->width(), this->height());
            this->irr_widget->resize(this->width(), this->height());

            this->ui->b_quit->resize(this->width()/10, this->height()/20);
            this->ui->b_quit->move(60, this->height()*0.88);

            this->ui->b_create->resize(this->width()/10, this->height()/20);
            this->ui->b_create->move(this->width()*0.83, this->height()*0.88);

            this->ui->cb_name->resize(this->width()/3, this->height()/20);
            this->ui->cb_name->move(this->width()*0.37, this->height()*0.88);

            this->ui->l_height->resize(this->width()/10, this->height()/30);
            this->ui->l_height->move(this->width()*0.83, this->height()*0.26);

            this->ui->l_width->resize(this->width()/10, this->height()/30);
            this->ui->l_width->move(this->width()*0.83, this->height()*0.40);

            this->ui->l_texture->resize(this->width()/10, this->height()/30);
            this->ui->l_texture->move(this->width()*0.83, this->height()*0.54);

            this->ui->slider_height->resize(this->width()/10, this->height()/20);
            this->ui->slider_height->move(this->width()*0.83, this->height()*0.33);

            this->ui->slider_width->resize(this->width()/10, this->height()/20);
            this->ui->slider_width->move(this->width()*0.83, this->height()*0.47);

            this->ui->slider_texture->resize(this->width()/10, this->height()/20);
            this->ui->slider_texture->move(this->width()*0.83, this->height()*0.61);

            this->ui->comboBox->resize(this->width()/3, this->height()/20);
            this->ui->comboBox->move(this->width()*0.37, this->height()*0.03);

            this->ui->text_description->resize(this->width()*0.265, this->height()*0.82);
            this->ui->text_description->move(this->width()*0.03, this->height()*0.03);
        }

        void SelectPlayer::focusInEvent(QFocusEvent* event) {
        }

        void SelectPlayer::focusOutEvent(QFocusEvent* event) {
        }

    }
}
