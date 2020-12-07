/**
 * \class CharacterSVGRenderer
 * 
 * \brief CharacterSVGRenderer class 
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/12/05 15:00
*/

#ifndef CHARACTERSVGRENDERER_HEADER
#define CHARACTERSVGRENDERER_HEADER

#include <string>
#include "SVGRenderer.h"
#include "Game.h"

class CharacterSVGRenderer : public SVGRenderer
{
    public:
    CharacterSVGRenderer(std::string filename) : SVGRenderer(filename) {}; ///< Constructor of the CharacterSVGRenderer
    virtual void render(const Game&) const; ///< Virtual render function to render the Character SVG
};

#endif