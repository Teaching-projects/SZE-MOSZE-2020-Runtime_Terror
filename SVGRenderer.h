/**
 * \class SVGRenderer
 * 
 * \brief SVGRenderer abstract class 
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/12/05 15:00
*/

#ifndef SVGRENDERER_HEADER
#define SVGRENDERER_HEADER

#include <string>
#include <regex>
#include "Renderer.h"
#include "Game.h"

class SVGRenderer : public Renderer
{
    public:

    std::string filename; ///< The name of the SVG file

    SVGRenderer(std::string filename) : filename(filename) {}; ///< Constructor of the SVGRenderer

    virtual void render(const Game&) const = 0; ///< Virtual render function
};

#endif