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
#include <stdexcept>
#include <iostream>
#include <string>

#include "character.hpp"
#include "ofw_config.hpp"


namespace ofw {
    namespace scene {

        Character::~Character() {
            delete this->character;
            delete this->DESCRIPTION;
        }

        void Character::set_height(unsigned int height) {
            if (get_height_min() <= height && height <= get_height_max()) {
                this->height = height;
            }
            else {
                throw std::domain_error("");
            }
        }

        void Character::set_width(unsigned int width) {
            if (get_width_min() <= width && width <= get_width_max()) {
                this->width = width;
            }
            else {
                throw std::domain_error("");
            }
        }

        void Character::set_life(unsigned int life) {
            if ((0 <= life) && life <= get_total_life()) {
                this->life = life;
            }
            else {
                throw std::domain_error("");
            }
        }

        void Character::set_rel_height(int rel_height) {
            if (get_height_min() <= (get_height() + rel_height) &&
                    (get_height() + rel_height) <= get_height_max()) {
                this->height = height + rel_height;
            }
            else {
                throw std::domain_error("");
            }
        }

        void Character::set_rel_width(int rel_width) {
            if (get_width_min() <= (get_width() + rel_width) &&
                    (get_width() + rel_width) <= get_width_max()) {
                this->width = width + rel_width;
            }
            else {
                throw std::domain_error("");
            }
        }

        void Character::set_rel_life(int rel_life) {
            if ((0 <= (get_life() + rel_life)) && ((get_life() + rel_life) <= get_total_life())) {
                this->life += rel_life;
            }
            else {
                throw std::domain_error("");
            }
        }

        irr::scene::IAnimatedMeshSceneNode* Character::render(irr::IrrlichtDevice *device) {
            irr::video::IVideoDriver* driver = device->getVideoDriver();
            irr::scene::ISceneManager* smgr = device->getSceneManager();
            irr::scene::IAnimatedMesh *player = smgr->getMesh(
                    (ofw::datadir + "/" + this->mesh).c_str());
            if (!player)
                throw "Exit";
            this->character = smgr->addAnimatedMeshSceneNode(player);
            if (!this->character)
                throw "Exit";
            this->character->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            this->character->setMaterialTexture(0, driver->getTexture((ofw::datadir +
                            "/" + this->texture).c_str()));
            float percent = 100;
            character->setScale(irr::core::vector3df(width/percent, height/percent, width/percent));
            return character;
        }


        void Character::refresh_character() {
            float percent = 100;
            if (!this->character)
                return;
            this->character->setScale(irr::core::vector3df(
                        this->width/percent, this->height/percent, this->width/percent));
        }

        void Character::set_animation(unsigned int init_frame, unsigned int end_frame,
                unsigned int speed) {
            character->setFrameLoop(0, 13);  // nº frame
            character->setAnimationSpeed(10); // fps
        }

        void Character::change_mesh(bool sig) {
            int tam = MESHES.size();
            if (sig)
                num_mesh = (num_mesh + 1) % tam;
            else
                num_mesh = (num_mesh - 1) % tam;
            this->mesh = MESHES.at(num_mesh);
        }

        void Character::change_texture(bool sig) {
            int tam = TEXTURES.size();
            if (sig)
                num_texture = (num_texture + 1) % tam;
            else
                num_texture = (num_texture - 1) % tam;
            this->texture = TEXTURES.at(num_texture);
        }

    }
}
