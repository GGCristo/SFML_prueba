#include <SFML/Graphics.hpp>

int main()
{
  unsigned int anchura = 640;
  unsigned int altura = 480;
  sf::RenderWindow window (sf::VideoMode(anchura, altura), "A ver si me sale la hitbox");
  window.setFramerateLimit(60);
  sf::RectangleShape shape(sf::Vector2f(100,50));
  shape.setFillColor(sf::Color::Magenta);
  unsigned int x = anchura/2, y = altura/2;

  sf::RectangleShape suelo(sf::Vector2f(anchura/3,altura/3));
  suelo.setPosition(anchura/2, altura/3);
  suelo.setFillColor(sf::Color(165, 42, 42));

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed)
        window.close();
  if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left))  x -= 10;
  if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right)) x += 10;
  if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up))    y -= 10;
  if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down))  y += 10;
  shape.setPosition(x, y);
  window.clear();
  window.draw(shape);
  window.draw(suelo);
  window.display();
  }


  return 0;
}
