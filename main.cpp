#include <iostream>
#include "JSON.h"
#include "PreparedGame.h"
#include "HeroTextRenderer.h"
#include "ObserverTextRenderer.h"
#include "CharacterSVGRenderer.h"
#include "ObserverSVGRenderer.h"

int main(int argc, char **argv)
{
    try
    {
        PreparedGame game = PreparedGame("preparedgame.json");

        game.registerRenderer(new HeroTextRenderer());

        auto observerStream = std::ofstream("log.txt");
        game.registerRenderer(new ObserverTextRenderer(observerStream));
        
        game.registerRenderer(new CharacterSVGRenderer("character.svg"));

        game.registerRenderer(new ObserverSVGRenderer("observer.svg"));

        game.run();
    }
    catch (const JSON::ParseException &e)
    {
        std::cerr << "Unknown error" << std::endl;
        return 1;
    }
    return 0;
}