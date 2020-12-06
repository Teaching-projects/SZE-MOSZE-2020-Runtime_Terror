/**
 * \class TextRenderer
 * 
 * \brief TextRenderer abstract class 
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/12/05 15:00
*/

#ifndef TEXTRENDERER_HEADER
#define TEXTRENDERER_HEADER

#include <iostream>
#include "Renderer.h"
#include "Game.h"

class TextRenderer : public Renderer
{
    public:

    std::ostream &stream;

    TextRenderer(std::ostream &stream = std::cout) : stream(stream) {};

    void setOutputStream(std::ostream &stream) 
    {
        stream.copyfmt(stream);
    };

    virtual void render(const Game&) const = 0;
};

#endif