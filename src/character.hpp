// Include guard
//* Para que compilador no compile dos veces lo mismo
#ifndef __CHARACTER_H
#define __CHARACTER_H

//include dependences
#include <string>
using namespace std;

class character
{
	private:
        int height;
        int width;
        string *model;
        string *texture;
        string *name;

	public:
		//CONSTRUCTORS
        character();

		//DESTRUCTOR
        ~character();

		//Getters
        int get_height(void) {return this->height;}
        int get_width(void) {return this->width;}
        string* get_model() {return this->model;}
        string* get_texture() {return this->texture;}
        string* get_name() {return this->name;}

		//Setters
        void set_height(int height);
        void set_width(int width);
        void set_model(string *model) {this->model = model;}
        void set_texture(string *texture) {this->texture = texture;}
        void set_name(string *name) {this->name = name;}

        // Others methods
        void height_inc();
        void height_dec();
        void width_inc();
        void width_dec();
};

#endif
