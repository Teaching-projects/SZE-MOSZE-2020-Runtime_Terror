/**
 * \class HeroTextRenderer
 * 
 * \brief HeroTextRenderer class 
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/12/05 15:00
*/

#ifndef HEROTEXTRENDERER_HEADER
#define HEROTEXTRENDERER_HEADER

#include <iostream>
#include "TextRenderer.h"
#include "Game.h"

class HeroTextRenderer : public TextRenderer
{
public:
    /**
     * Virtual render function to render the text
    */
    virtual void render(const Game& game) const;
};

#endif