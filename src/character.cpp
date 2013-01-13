#include <iostream>
#include <stdexcept>

#include "character.hpp"
#include "cte.hpp"

using namespace hw;

character::character()
{
    this->height = HEIGHT_CTE;
    this->width = WIDTH_CTE;
    this->model = new string("");
    this->texture = new string("");
    this->name = new string("");
}

character::~character()
{
}

void character::height_inc()
{
    if (this->height + HEIGHT_INC > HEIGHT_MAX)
        throw domain_error("");
    else
        this->height += HEIGHT_INC;
}

void character::height_dec()
{
    if (this->height - HEIGHT_INC < HEIGHT_MIN)
        throw domain_error("");
    else
        this->height -= HEIGHT_INC;
}

void character::set_height(int height)
{
    if (height < HEIGHT_MIN || height > HEIGHT_MAX)
        throw domain_error("");
    else
        this->height = height;
}

void character::width_inc()
{
    if (this->width + WIDTH_INC > WIDTH_MAX)
        throw domain_error("");
    else
        this->width += WIDTH_INC;
}

void character::width_dec()
{
    if (this->width - WIDTH_INC < WIDTH_MIN)
        throw domain_error("");
    else
        this->width -= WIDTH_INC;
}

void character::set_width(int width)
{
    if (width < WIDTH_MIN || width > WIDTH_MAX)
        throw domain_error("");
    else
        this->width = width;
}
