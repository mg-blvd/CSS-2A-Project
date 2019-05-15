// *******************************************************************************
// Name: Denize Ignacio
// Date: 5/15/19
// *******************************************************************************

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
// Here is a small helper for you! Have a look.

int main(int, char const**)
{
    // Create the main window
    RenderWindow window(VideoMode(1200, 1000), "Lego Runner");

    // Width and height
    Texture texture, character1, life;
    if (!texture.loadFromFile("My Post.png")) {
        return EXIT_FAILURE;
    }
    texture.loadFromFile("My Post.png");

    Sprite sprite(texture);
    sprite.scale(0.47, 0.8);

    character1.loadFromFile("guy.png");
    Sprite player(character1);
    player.scale(0.2, 0.2);
    player.setPosition(555, 860);

    life.loadFromFile("life.png");
    Sprite health(life);
    health.scale(1, 1);
    health.setPosition(550, 860);
    Vector2u size = character1.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;

    cout << width << endl << height;
    // Create a graphical text to display
    /*sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
//    sf::Text text("Hello", font, 100);
//    text.setFillColor(sf::Color::Black);
*/
    // Load a music to play
    Music music;
    if (!music.openFromFile("templeRunner.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();
    music.setLoop(true);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
		if (event.type == Event::Closed) {
			window.close();
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::Left)  && ) {
			player.move(-(555-416), 0);
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Right)) {
			//player.setPosition(player.position() +width/7 + (width + width/7)/2, 860);
			player.move(555-416, 0);
		}
       
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos = Mouse::getPosition(window);
            player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
            cout << mousePos.x << endl;
        }
	window.clear();
        // Draw the sprite
        window.draw(sprite);
        window.draw(player);
	window.draw(health);
        window.display();
    }
}
    return EXIT_SUCCESS;
}	
