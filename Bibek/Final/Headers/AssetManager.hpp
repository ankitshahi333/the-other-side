#pragma once        //prevents multiple declaration of a function from different files

#include <map>
#include <SFML/Graphics.hpp>

class AssetManager
{
    public:
        AssetManager ( ) { }
        ~AssetManager ( ) { }

        void LoadTexture ( std::string name, std::string filename );
        sf::Texture &GetTexture ( std::string name );       //for collision detection

        void LoadFont ( std::string name, std::string filename );
        sf::Font &GetFont ( std::string name );             

    private:
        std::map< std::string , sf::Texture > _textures;    //maps name and texture file
        std::map< std::string , sf::Font > _fonts;          //maps name and font file
};