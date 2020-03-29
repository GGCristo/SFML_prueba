#include <SFML/Graphics.hpp>

int main()
{
  unsigned int largo = 640;
  unsigned int ancho = 480;
  sf::RenderWindow window (sf::VideoMode(largo, ancho), "Hello World");
  window.setFramerateLimit(60);
  sf::RectangleShape shape(sf::Vector2f(100,50));
  shape.setFillColor(sf::Color::Magenta);
  shape.setPosition(largo/2.f, ancho/2.f);

  window.clear();
  window.draw(shape);
  window.display();
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed)
        window.close();
  }


  return 0;
}
