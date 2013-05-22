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

#include <iostream>
#include "client.hpp"
#include "playermsg.pb.h"
#include "../scene/player.hpp"


namespace ofw {
    namespace client {

        Client::Client() {
            if (enet_initialize() != 0)
                exit(EXIT_FAILURE);

            this->client = enet_host_create(NULL, 1, 2, 57600/8, 14400/8);
            if (this->client == NULL)
                exit(EXIT_FAILURE);

            enet_address_set_host(&this->address, "localhost"); //TODO add to configuration
            this->address.port = 1234;

            this->peer = enet_host_connect(this->client, &this->address, 2, 0);
            if(peer == NULL)
                exit(EXIT_FAILURE);
        }

        Client::~Client() {
            enet_host_destroy(this->client);
            enet_deinitialize();
        }

        bool Client::send_player(ofw::scene::Player *player, int texture, int type) {
            // Create player with protobuf
            int height = player->get_height();
            int width = player->get_width();
            int life = player->get_life();
            player_msg pmsg;
            //TODO check values with 0, DANGER
            pmsg.set_name(player->get_name());
            pmsg.set_pos_x(1);
            pmsg.set_pos_y(1);
            pmsg.set_pos_z(1);
            pmsg.set_height(height);
            pmsg.set_width(width);
            //pmsg.set_mesh(0);
            if (texture != 0)
                pmsg.set_texture(texture);
            pmsg.set_life(life);
            if (type == 0)
                pmsg.set_type(PICACODE);
            else if (type == 1)
                pmsg.set_type(HACKER);
            else if (type == 2)
                pmsg.set_type(CRACKER);
            else if (type == 3)
                pmsg.set_type(DESIGNER);
            else if (type == 4)
                pmsg.set_type(HUNTERBUG);

            std::string *serialized = new std::string("");
            pmsg.SerializeToString(serialized);

            ENetPacket *packetresp = enet_packet_create(serialized->c_str(),
                    strlen(serialized->c_str())+1, ENET_PACKET_FLAG_RELIABLE);

            if (enet_host_service(this->client, &this->event, 1000) > 0 &&
                    this->event.type == ENET_EVENT_TYPE_CONNECT) {
                enet_peer_send(this->peer, 0, packetresp);
                enet_host_flush(this->client);
                std::cout << "Paquete enviado" << std::endl;
            }
            else {
                enet_peer_reset(this->peer);
            }

            // Wait response
            while (enet_host_service(this->client, &this->event, 2000) > 0) {
                std::cout << "while" << std::endl;
                if (this->event.type == ENET_EVENT_TYPE_RECEIVE) {
                    std::cout << "receive" << std::endl;
                    break;
                }
                else if (this->event.type == ENET_EVENT_TYPE_DISCONNECT) {
                    return false;
                }
            }
            return true;
        }

    }
}
