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
        IAnimatedMesh* get_animated_mesh();

        /**
         * @brief Adds a character to a especific sector in the map.
         *
         * @param character Character to be added to the map.
         *
         * @param sector Sector in which the character is going to be added.
         */
        void add_character(Character character, Sector sector);

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
         * @brief Gives a list with all the characters in the map.
         *
         * @return List of characters, contains all the characters that are in the map.
         */
        list<Character> get_all_characters();

        /**
         * @brief Looks for all the characters present in a specific sector.
         *
         * @param sector Sector from which the characters will be retrieved.
         *
         * @return List of characters.
         */
       list<Character> get_sector_characters(Sector sector);

        /**
         * @brief Gives a list with all the objects in the map.
         *
         * @return List of objects, contains all the objects that are in the map.
         */
        list<Object> get_all_objects();

        /**
         * @brief Looks for all the objects present in a specific sector.
         *
         * @param sector Sector from which the objects will be retrieved.
         *
         * @return List of objects.
         */
       list<Character> get_sector_objects(Sector sector);

       /**
        * @brief This method assigns sectors to the map.
        */
       void calculate_sectors();
};

}

}

#endif

