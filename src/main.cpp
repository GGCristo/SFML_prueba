#include <SFML/Graphics.hpp>

int main()
{
  const unsigned int anchura = 500;
  const unsigned int altura = 500;
  sf::RenderWindow window (sf::VideoMode(anchura, altura), "A ver si me sale la hitbox");
  window.setFramerateLimit(30);

  sf::RectangleShape suelo(sf::Vector2f(anchura, altura/3));
  suelo.setPosition(0, altura - suelo.getSize().y);
  suelo.setFillColor(sf::Color(165, 42, 42));

  const unsigned int h_entidad = 100;
  const unsigned int w_entidad = 50;
  sf::RectangleShape entidad(sf::Vector2f(h_entidad, w_entidad));
  entidad.setFillColor(sf::Color::Magenta);
  entidad.setPosition(0, altura - suelo.getSize().y - 50);


  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed)
        window.close();

  if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) && entidad.getPosition().x >= 10)  entidad.move(-10, 0);
  else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right) && entidad.getPosition().x <= anchura - 100 - 10) entidad.move(10, 0);
  // if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up) && entidad.getPosition().y == altura - suelo.getSize().y - 50) entidad.move(0, -80);

  window.clear();
  window.draw(entidad);
  window.draw(suelo);
  window.display();
  }


  return 0;
}
