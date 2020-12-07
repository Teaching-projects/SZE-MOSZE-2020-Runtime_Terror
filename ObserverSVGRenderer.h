  
/**
 * \class ObserverSVGRenderer
 * 
 * \brief ObserverSVGRenderer class
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/12/05 15:00
*/

#ifndef OBSERVERSVGRENDERER_HEADER
#define OBSERVERSVGRENDERER_HEADER

#include "SVGRenderer.h"
#include "Game.h"

class ObserverSVGRenderer : public SVGRenderer {
    
    public:
    ObserverSVGRenderer(std::string filename) : SVGRenderer(filename) {}; ///< Constructor of the ObserverSVGRenderer
    virtual void render(const Game&) const; ///< Virtual render function to render the SVG image
};

#endif