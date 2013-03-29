/*************************************************************************
 * * Open Fantasy World is a MMORPG where the players will live in community.
 * * Copyright (C) 2012-2013 Javier Jaramago Fernández
 * * <jaramago.fernandez.javier@gmail.com>
 * *
 * * This program is free software: you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License as published by
 * * the Free Software Foundation, either version 3 of the License, or
 * * (at your option) any later version.
 * *
 * * Foobar is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 * */

#ifndef __M__MAP_H
#define __M__MAP_H

#include <string>
#include "mapobserver.hpp"
#include "sector.hpp"
#include "core.hpp"

namespace irr
{
    namespace scene
    {
        class ISceneManager;
        class IAnimatedMesh;
    }
}

namespace ofw
{

namespace scene
{

/**
 * @brief Class that represent the scenarie in which the objects and characters
 * will be placed.
 */
class Map {
    private:
        irr::scene::IAnimatedMesh* animated_mesh;
        irr::scene::ISceneNode* scene_frame;
        irr::scene::ISceneManager* smgr;
        std::string model_path;
        MapObserver observer;

    public:
        /**
         * @brief Constructor.
         */
        Map(irr::scene::ISceneManager* smgr, std::string model_path, MapObserver observer);

        /**
         * @brief Default destructor.
         */
        ~Map();

        /**
         * @brief Get the static scene frame.
         *
         * @return current scene frame.
         */
        irr::scene::IAnimatedMesh* get_animated_mesh();

        /**
         * @brief Add a new element to a map sector.
         *
         * @param element The element to be added.
         *
         * @param sector The sector in which the new element is going to be
         * added.
         */
        template <class T>
        void add_element(T element, Sector sector);

        /**
         * @brief Remove a character from the map.
         */
        void remove_character();

        /**
         * @brief Remove a character from a specified sector of the map.
         *
         * @param sector Sector from which the character is going to be removed.
         */
        void remove_character(Sector sector);

        /**
         * @brief Returns all the elements of an specific type present on the
         * map.
         *
         *
         * @return A list with the elements.
         */
        template <class T>
        std::list<T> get_all_elements(ElementType type);

        /**
         * @brief Returns all the elements of an specific type present in one
         * specific sector of the map.
         *
         * @param sector Sector from which the elements are going to be
         * retrieved.
         *
         * @return A list with the elements.
         */
        template <class T>
        std::list<T> get_sector_elements(Sector sector);

       /**
        * @brief This method assigns sectors to the map.
        */
       void calculate_sectors();
};

}

}

#endif
