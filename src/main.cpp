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

#include <irrlicht.h>
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif
#include <QtGui/QApplication>

#include "gui/select_player.hpp"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SelectPlayer sp;
    sp.show();
    sp.get_irr_widget()->init();
    if (sp.get_irr_widget()->get_device()) {
        irr::video::IVideoDriver* driver = sp.get_irr_widget()->get_device()->getVideoDriver();
        irr::scene::ISceneManager* smgr = sp.get_irr_widget()->get_device()->getSceneManager();
        irr::scene::IAnimatedMesh* player = smgr->getMesh("../media/ninja.b3d");
        if (!player) {
            sp.get_irr_widget()->get_device()->drop();
            return 1;
        }
        irr::scene::IAnimatedMeshSceneNode* player_ani = smgr->addAnimatedMeshSceneNode(player);
        if (player_ani) {
            player_ani->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            player_ani->setFrameLoop(0, 13);  // nº frame
            player_ani->setAnimationSpeed(10); // fps
            player_ani->setMaterialTexture(0, driver->getTexture("../media/ninja.jpg"));
            player_ani->setScale(irr::core::vector3df(1,1,1));
            player_ani->setPosition(irr::core::vector3df(0,0,0));
            player_ani->setRotation(irr::core::vector3df(0,0,0));
        }
    }
    return app.exec();

    // SCENE: insert camera
    //irr::scene::ICameraSceneNode* camera = smgr->addCameraSceneNode(player_ani);
    //camera->setPosition(irr::core::vector3df(0, 15, 20));
    //camera->setTarget(player_ani->getPosition());

}
