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
    /**
     * Constructor of the CharacterSVGRenderer
    */
    CharacterSVGRenderer(std::string filename) : SVGRenderer(filename) {};

    /**
     * Virtual render function to render the Character SVG
    */
    virtual void render(const Game&) const;
};

#endif