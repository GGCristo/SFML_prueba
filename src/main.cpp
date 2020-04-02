#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

void jumping (sf::RectangleShape&, const unsigned int&, sf::RenderWindow&, sf::RectangleShape&);

int main()
{
  const unsigned int anchura = 500;
  const unsigned int altura = 500;
  sf::RenderWindow window (sf::VideoMode(anchura, altura), "A ver si me sale el salto");
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
  if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up) && entidad.getPosition().y == altura - suelo.getSize().y - 50) jumping(entidad, suelo.getSize().y, window, suelo);

  window.clear();
  window.draw(entidad);
  window.draw(suelo);
  window.display();
  }


  return 0;
}

  void jumping (sf::RectangleShape& entidad, const unsigned int& sz_suelo, sf::RenderWindow& window, sf::RectangleShape& suelo)
  {
    unsigned int aceleracion = 0;
    int x = 0;
    while(entidad.getPosition().y >= 500 - (sz_suelo + 150))
    {

      if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) && entidad.getPosition().x >= 10)
      {
        x -= 1;
      }

      else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right) && entidad.getPosition().x <= window.getSize().y - 100 - 10)  
      {
        x += 1;
      }

      entidad.move(x, - (++aceleracion - 1/2 * 9.807));
      std::cout << "Subiendo" << "\n";
      std::cout << "Estoy en: " << entidad.getPosition().x << " " << entidad.getPosition().y << "\n";

      window.clear();
      window.draw(entidad);
      window.draw(suelo);
      window.display();
    }

    while (entidad.getPosition().y < 500 - (sz_suelo + entidad.getSize().y))
    {
      entidad.move(x, + (++aceleracion - 1/2 * 9.807));
      std::cout << "Bajando" << "\n";

      if (sf::Keyboard::isKeyPressed (sf::Keyboard::Left) && entidad.getPosition().x >= 10)
      {
        x -= 1;
      }

      else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right) && entidad.getPosition().x <= window.getSize().y - 100 - 10)  
      {
        x += 1;
      }

      window.clear();
      window.draw(entidad);
      window.draw(suelo);
      window.display();
    }
  }
