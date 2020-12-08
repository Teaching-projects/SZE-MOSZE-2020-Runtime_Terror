  
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
    /**
     * Constructor of the ObserverSVGRenderer
    */
    ObserverSVGRenderer(std::string filename) : SVGRenderer(filename) {};

    /**
     * Virtual render function to render the SVG image
    */
    virtual void render(const Game&) const;
};

#endif