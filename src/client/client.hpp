/*************************************************************************
* Open Fantasy World is a MMORPG where the players will live in community.
* Copyright (C) 2012-2013 Alejandro Seguí Díaz <alesegdia@gmail.com>
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

#ifndef __CLIENT_HPP
#define __CLIENT_HPP

#include <enet/enet.h>

class player_msg;
namespace ofw {
    namespace scene {
        class Player;
    }
}


namespace ofw {
    namespace client {

        class Client {

            private:
                /**
                 * @brief Enet address, contains type host and port
                 */
                ENetAddress address;

                /**
                 * @brief Event for Conection, Desconection or Receive
                 */
                ENetEvent event;

                /**
                 * @brief enet peer
                 */
                ENetPeer *peer;

                /**
                 * @brief enet client
                 */
                ENetHost *client;


            public:
                /**
                 * @brief Default contructor. Init host and peer
                 */
                Client();

                /**
                 * @brief Default destructor
                 */
                ~Client();

                void create_host();

                /**
                 * @brief Send create player to server
                 *
                 * @param player class Player
                 * @param texture index texture
                 * @param type index type
                 *
                 * @return true if create player in server //TODO
                 */
                bool send_player(ofw::scene::Player *player, int texture, int type);
        };

    }
}
#endif
