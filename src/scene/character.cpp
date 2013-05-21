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
#include <iostream>

#include "character.hpp"
#include "../ofw_config.hpp"


namespace ofw {
    namespace scene {

        Character::~Character() {
            if (this->scene_node != NULL)
                this->scene_node->remove();
            delete this->DESCRIPTION;
        }

        void Character::set_height(unsigned int height) {
            if (get_height_min() <= height && height <= get_height_max()) {
                this->height = height;
            }
            else {
                throw std::domain_error("");
            }
            this->scale();
        }

        void Character::set_width(unsigned int width) {
            if (get_width_min() <= width && width <= get_width_max()) {
                this->width = width;
            }
            else {
                throw std::domain_error("");
            }
            this->scale();
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
                this->height += rel_height;
            }
            else {
                throw std::domain_error("");
            }
        }

        void Character::set_rel_width(int rel_width) {
            if (get_width_min() <= (get_width() + rel_width) &&
                    (get_width() + rel_width) <= get_width_max()) {
                this->width += rel_width;
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

        void Character::scale() {
            if (this->scene_node != NULL) {
                float percent = 100;
                this->scene_node->setScale(irr::core::vector3df(
                        this->width/percent, this->height/percent, this->width/percent));
            }
        }

        void Character::set_animation(unsigned int init_frame, unsigned int end_frame,
                unsigned int speed) {
            this->scene_node->setFrameLoop(0, 13);  // nº frame
            this->scene_node->setAnimationSpeed(10); // fps
        }

        void Character::set_texture(int index) {
            if (0 <= index && index < this->TEXTURES.size()) {
                this->texture = TEXTURES.at(index);
            }
            if (this->scene_node != NULL) {
                this->scene_node->setMaterialTexture(0, this->device->getVideoDriver()->getTexture(
                        (ofw::datadir + "/" + this->texture).c_str()));
            }
        }

        irr::scene::IAnimatedMesh* Character::set_mesh() {
            return this->device->getSceneManager()->getMesh(
                    (ofw::datadir + "/" + this->mesh).c_str());
        }

        void Character::create_scene_node(irr::IrrlichtDevice *device) {
            this->set_device(device);
            irr::scene::IAnimatedMesh* mesh = this->set_mesh();
            if (!mesh)
                throw "Exit";
            this->scene_node = this->device->getSceneManager()->addAnimatedMeshSceneNode(mesh);
            // TODO Temporal. It is neccesary to see the textures. Isolate it.
            if (this->scene_node != NULL) {
                this->scene_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            }
        }

    }
}
