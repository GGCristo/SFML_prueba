#include <SFML/Graphics.hpp>

int main()
{
  const unsigned int anchura = 500;
  const unsigned int altura = 500;
  sf::RenderWindow window (sf::VideoMode(anchura, altura), "A ver si me sale la hitbox");
  window.setFramerateLimit(30);

  unsigned int x = 0, y = altura - altura/3 - 50;
  sf::RectangleShape shape(sf::Vector2f(100,50));
  shape.setFillColor(sf::Color::Magenta);

  sf::RectangleShape suelo(sf::Vector2f(anchura, altura/3));
  suelo.setPosition(0, altura - altura/3);
  suelo.setFillColor(sf::Color(165, 42, 42));

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed)
        window.close();
  if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) && x >= 10)  x -= 10;
  if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right) && x <= anchura - 100 - 10) x += 10;
  // if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up))    y -= 10; // why? Esta a la inversa
  // if (sf::Keyboard::isKeyPressed (sf::Keyboard::Down))  y += 10;
  shape.setPosition(x, y);
  window.clear();
  window.draw(shape);
  window.draw(suelo);
  window.display();
  }


  return 0;
}
