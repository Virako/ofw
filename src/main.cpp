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
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif
#include <QtGui/QApplication>
#include <iostream>
#include <libintl.h>
#define _(x) gettext(x)

#include "ofw_config.hpp"
#include "core/core.hpp"
#include "gui/select_player.hpp"
#include "gui/irr_widget.hpp"
#include "scene/picacode.hpp"


int main(int argc, char *argv[]) {
    ofw::core::init_i18n();
    std::cout << _("Welcome to ofw") << std::endl;

    QApplication app(argc, argv);
    ofw::gui::SelectPlayer sp;
    sp.show();
    sp.get_irr_widget()->init();
    irr::IrrlichtDevice *device = sp.get_irr_widget()->get_device();
    sp.set_device(device);
    sp.init_default();
    if (device) {
    }
    return app.exec();
}
