/**
 * \class Renderer
 * 
 * \brief Renderer abstract class 
 * 
 * \author Tömördi Tamás
 * 
 * Created on: 2020/12/05 15:00
*/

#ifndef RENDERER_HEADER
#define RENDERER_HEADER

class Game;
class Renderer
{
public:
    /**
     * Virtual render function
    */
    virtual void render(const Game&) const = 0;

    /**
     * Virtual destructor of the Renderer
    */
    virtual ~Renderer() {};
};

#endif