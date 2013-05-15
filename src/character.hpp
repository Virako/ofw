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

#ifndef __CHARACTER_H
#define __CHARACTER_H

#include <vector>
#include <string>

namespace irr {
    class IrrlichtDevice;
    namespace scene {
        class IAnimatedMeshSceneNode;
    }
}


namespace ofw {
    namespace scene {

        class Character {
            protected:
                unsigned int HEIGHT_MIN;
                unsigned int HEIGHT_MAX;
                unsigned int WIDTH_MIN;
                unsigned int WIDTH_MAX;
                unsigned int height;
                unsigned int width;
                unsigned int life;
                unsigned int total_life;
                int num_mesh;
                int num_texture;
                std::string name;
                std::string mesh;
                std::string texture;
                irr::scene::IAnimatedMeshSceneNode *character;
                std::string *DESCRIPTION;
                std::vector<std::string> MESHES;
                std::vector<std::string> TEXTURES;

            public:
                /**
                 * @brief Destructor default.
                 */
                virtual ~Character();

                /**
                 * @brief Set character's height.
                 *
                 * @param height character's height
                 */
                virtual void set_height(unsigned int height);

                /**
                 * @brief Set character's width.
                 *
                 * @param width character's width
                 */
                virtual void set_width(unsigned int width);

                /**
                 * @brief Set character's life checking if value is correct.
                 *
                 * @param rel_height character's relative height. If negative sub height and if
                 * positive add height.
                 */
                virtual void set_rel_height(int rel_height);

                /**
                 * @brief Set character's width checking if value is correct.
                 *
                 * @param rel_width character's relative width. If negative sub width and if
                 * positive add width.
                 */
                virtual void set_rel_width(int rel_width);

                /**
                 * @brief Get the current character's height.
                 *
                 * @return current character's height.
                 */
                virtual unsigned int get_height(void);

                /**
                 * @brief Get the current character's height_min.
                 *
                 * @return current character's height_min.
                 */
                virtual unsigned int get_height_min(void);

                /**
                 * @brief Get the current character's height_max.
                 *
                 * @return current character's height_max.
                 */
                virtual unsigned int get_height_max(void);

                /**
                 * @brief Get the current character's width.
                 *
                 * @return current character's width.
                 */
                virtual unsigned int get_width(void);

                /**
                 * @brief Get the current character's width_min.
                 *
                 * @return current character's width_min.
                 */
                virtual unsigned int get_width_min(void);

                /**
                 * @brief Get the current character's width_max.
                 *
                 * @return current character's width_max.
                 */
                virtual unsigned int get_width_max(void);

                /**
                 * @brief Get the current character's name.
                 *
                 * @return current character's name.
                 */
                virtual std::string get_name();

                /**
                 * @brief Set character's life.
                 *
                 * @param name std::string
                 */
                virtual void set_name(std::string name);

                /**
                 * @brief Get the current character's life.
                 *
                 * @return current character's life.
                 */
                virtual unsigned int get_life(void);

                /**
                 * @brief Get the current character's life.
                 *
                 * @return current character's life.
                 */
                virtual unsigned int get_total_life(void);

                /**
                 * @brief Set character's life checking if value is correct.
                 *
                 * @param life character's life
                 */
                virtual void set_life(unsigned int life);

                /**
                 * @brief Set character's life checking if value is correct.
                 *
                 * @param rel_life character's relative life. If negative sub life and if
                 * positive add life.
                 */
                virtual void set_rel_life(int rel_life);

                /**
                 * @brief Get the current character's description.
                 *
                 * @return current character's description.
                 */
                virtual std::string* get_description();

                virtual irr::scene::IAnimatedMeshSceneNode* render(irr::IrrlichtDevice *device);
                virtual void set_animation(unsigned int init_frame, unsigned int end_frame,
                        unsigned int speed);
                virtual void refresh_character();
                virtual void change_mesh(bool sig=true);
                virtual void change_texture(bool sig=true);
        };

        inline unsigned int Character::get_height(void) {
            return this->height;
        }

        inline unsigned int Character::get_height_min(void) {
            return this->HEIGHT_MIN;
        }

        inline unsigned int Character::get_height_max(void) {
            return this->HEIGHT_MAX;
        }

        inline unsigned int Character::get_width(void) {
            return this->width;
        }

        inline unsigned int Character::get_width_min(void) {
            return this->WIDTH_MIN;
        }

        inline unsigned int Character::get_width_max(void) {
            return this->WIDTH_MAX;
        }

        inline unsigned int Character::get_life() {
            return this->life;
        }

        inline unsigned int Character::get_total_life() {
            return this->total_life;
        }

        inline std::string* Character::get_description() {
            return this->DESCRIPTION;
        }

        inline std::string Character::get_name() {
            return this->name;
        }

        inline void Character::set_name(std::string name) { //TODO check size
            this->name = name;
        }

    }
}
#endif
