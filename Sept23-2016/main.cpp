#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(int argc, char *argv)
{
  sf::RenderWindow window(sf::VideoMode(400, 400), "Template", sf::Style::Titlebar | sf::Style::Close);

  sf::Event evt;
  sf::Clock appTimer;

  // Loading textures
  sf::Texture dogeTexture;
  dogeTexture.loadFromFile("res/doge.jpg");

  sf::Texture astrocatTexture;
  astrocatTexture.loadFromFile("res/astrocat.jpg");

  //Loading sprites
  sf::Sprite dogeSprite;
  dogeSprite.setTexture(dogeTexture);
  dogeSprite.setScale(0.5f, 0.5f);

  sf::Sprite astrocatSprite;
  astrocatSprite.setTexture(astrocatTexture);

  //Loading Sound
  sf::SoundBuffer buffer;
  buffer.loadFromFile("res/pacman_dies_y.wav");

  //sf::Music music;
  //music.openFromFile("res/04 Sharks In Danger.flac");

  sf::Sound sound(buffer);

  while (window.isOpen()) {
    float deltaTime = appTimer.restart().asSeconds();

    while (window.pollEvent(evt)) {
      if (evt.type == sf::Event::Closed) {
        window.close();
      }
      else if(evt.type == sf::Event::KeyPressed) {
        //sound.play();
        sound.play();
      }
    }

    // Move our glorious sprite.
    dogeSprite.move(10.0f * deltaTime, 0);

    // do stuff.
    window.clear();

    //draw stuff
    window.draw(dogeSprite);

    window.draw(astrocatSprite);

    window.display();
  }

  return 0;
}