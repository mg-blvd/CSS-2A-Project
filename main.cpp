
// Date: 5/15/19
// *******************************************************************************

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
// Here is a small helper for you! Have a look.

int main(int, char const**)
{
    // Create the main window
    RenderWindow window(VideoMode(1200, 1000), "Lego Runner");

    // Width and height
    Texture texture, 
	    character1, 
	    life1,
	    life2,
	    life3, 
	    obstacle, 
	    obstacle2;
    int counter = 3;
    if (!texture.loadFromFile("My Post.png")) {
        return EXIT_FAILURE;
    }
    texture.loadFromFile("My Post.png");

    Sprite sprite(texture);
    sprite.scale(0.47, 0.8);

    character1.loadFromFile("guy.png");
    Sprite player(character1);
    player.scale(0.2, 0.2);
    player.setOrigin(.1, .1);
    player.setPosition(555, 860);
    

    life1.loadFromFile("life.png");
    Sprite health(life1);
    health.scale(3, 3);
    health.setPosition(0, 30);
    Vector2u size = character1.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;

    cout << width << endl << height;

    life2.loadFromFile("life.png");
    Sprite health2(life2);
    health2.scale(3, 3);
    health2.setPosition(0, 130);

    life3.loadFromFile("life.png");
    Sprite health3(life3);
    health3.scale(3, 3);
    health3.setPosition(0, 230);


    obstacle.loadFromFile("anthony.png");
    Sprite obs(obstacle);
    obs.scale(0.05, 0.05);
    obs.setPosition(360, 50);

    obstacle2.loadFromFile("anthony.png");
    Sprite obs2(obstacle2);
    obs2.scale(0.05, 0.05);
    obs2.setPosition(660, 50);

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
	if(obs.getPosition().y < player.getPosition().y) {
		obs.move(0, 0.01);
	}

	if(obs.getPosition().y > player.getPosition().y)
	       obs.setPosition(360, 50);	
	    if(player.getGlobalBounds().intersects(obs.getGlobalBounds())){
		    counter--;
		if(counter == 2) {
			health.setColor(Color::Transparent); 
		}
		else if(counter == 1) {
			health2.setColor(Color::Transparent);
		}
		else {
			health3.setColor(Color::Transparent);
		}
	}
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
			window.close();
		}
		if(Keyboard::isKeyPressed(Keyboard::Key::Left)) {
			player.move(-(555-416), 0);
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Right)) {
			player.move(139, 0);
		}
		
       
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos = Mouse::getPosition(window);
            player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
            cout << mousePos.x << endl;
        }
	window.clear();
        //Draw the sprite
	window.draw(sprite);
        window.draw(player);
	window.draw(health);
	window.draw(health2);
	window.draw(health3);
	window.draw(obs);
	window.draw(obs2);
        window.display();
    }
}
    return EXIT_SUCCESS;
}	
