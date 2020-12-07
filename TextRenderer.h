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

    std::ostream &stream; ///< The output stream of the renderer

    TextRenderer(std::ostream &stream = std::cout) : stream(stream) {}; ///< Constructor of the renderer

    void setOutputStream(std::ostream &stream) ///< Function to set the output stream
    {
        stream.copyfmt(stream);
    };

    virtual void render(const Game&) const = 0; ///< Virtual render function
};

#endif