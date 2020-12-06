/**
 * \class ObserverTextRenderer
 * 
 * \brief ObserverTextRenderer class 
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/12/05 15:00
*/

#ifndef OBSERVERTEXTRENDERER_HEADER
#define OBSERVERTEXTRENDERER_HEADER

#include "TextRenderer.h"
#include "Game.h"

class ObserverTextRenderer : public TextRenderer
{
    public:
    virtual void render(const Game&) const;
};

#endif