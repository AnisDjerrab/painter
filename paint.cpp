#include <iostream>
#include <SFML/graphics.hpp>
#include <vector>

using namespace std;

/*pour executer
g++ paint.cpp -o paint.exe -I /c/SFML/include -L /c/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system && ./paint.exe
*/

int Cinq(int nombre)
{
    int intermediaire = nombre;
    intermediaire %= 10;
    if (intermediaire == 1 or intermediaire == 6)
    {
        nombre -= 1;
    }
    else if (intermediaire == 2 or intermediaire == 7)
    {
        nombre -= 2;
    }
    else if (intermediaire == 3 or intermediaire == 8)
    {
        nombre += 2;
    }
    else if (intermediaire == 4 or intermediaire == 9)
    {
        nombre += 1;
    }
    return nombre;
}

int dix(int nombre)
{
    int intermediaire = nombre;
    intermediaire %= 10;
    if (intermediaire == 1)
    {
        nombre -= 1;
    }
    if (intermediaire == 2)
    {
        nombre -= 2;
    }
    if (intermediaire == 3)
    {
        nombre -= 3;
    }
    if (intermediaire == 4)
    {
        nombre -= 4;
    }
    if (intermediaire == 5)
    {
        nombre += 5;
    }
    if (intermediaire == 6)
    {
        nombre += 4;
    }
    if (intermediaire == 7)
    {
        nombre += 3;
    }
    if (intermediaire == 8)
    {
        nombre += 2;
    }
    if (intermediaire == 9)
    {
        nombre += 1;
    }
    return nombre;
}

int main()
{
    sf::RenderWindow screen(sf::VideoMode(1100, 800), "painter");
    sf::Clock clock;
    
    vector<vector<int>> coordonnees;
    int numbre = 0;
    bool dessiner(false);
    int options(0);
    sf::Color color = sf::Color::Black;

    sf::Texture texture1;
    texture1.loadFromFile("C:/users/Anis Djerrab/Downloads/stylo.jpg");
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);
    sprite1.setPosition(25.f, 25.f);
    sprite1.setScale(0.05f, 0.05f);

    sf::Texture texture2;
    texture2.loadFromFile("C:/users/Anis Djerrab/Downloads/marker.jpg");
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setPosition(35.f, 90.f);
    sprite2.setScale(0.25f, 0.25f);

    sf::Texture texture3;
    texture3.loadFromFile("C:/users/Anis Djerrab/Downloads/gomme.jpg");
    sf::Sprite sprite3;
    sprite3.setTexture(texture3);
    sprite3.setPosition(30.f, 155.f);
    sprite3.setScale(0.1f, 0.1f);

    sf::Texture texture4;
    texture4.loadFromFile("C:/users/Anis Djerrab/Downloads/Reset.jpg");
    sf::Sprite sprite4;
    sprite4.setTexture(texture4);
    sprite4.setPosition(38.f, 550.f);
    sprite4.setScale(0.25f, 0.25f);


    vector<sf::CircleShape> couleurs;
    vector<sf::Color> couleur = {
        sf::Color::Black,
        sf::Color::Red,
        sf::Color::Blue,
        sf::Color::Green,
        sf::Color::Yellow
    };

    for (size_t i(0); i < couleur.size(); i++)
    {
        sf::CircleShape circle(25.f);
        circle.setFillColor(couleur[i]);
        circle.setPosition(35.f, 220.f + 65*i);
        couleurs.push_back(circle);
    }

    sf::FloatRect bounds1 = sprite1.getGlobalBounds();
    sf::FloatRect bounds2 = sprite2.getGlobalBounds();
    sf::FloatRect bounds3 = sprite3.getGlobalBounds();
    sf::FloatRect bounds9 = sprite4.getGlobalBounds();
    sf::FloatRect bounds4 = couleurs[0].getGlobalBounds();
    sf::FloatRect bounds5 = couleurs[1].getGlobalBounds();
    sf::FloatRect bounds6 = couleurs[2].getGlobalBounds();
    sf::FloatRect bounds7 = couleurs[3].getGlobalBounds();
    sf::FloatRect bounds8 = couleurs[4].getGlobalBounds();

    while (screen.isOpen())
    {
        sf::Event event;
        sf::Time deltaTime = clock.restart();

        while (screen.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                screen.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left && numbre > 10)
                {
                    numbre = 0;
                    if (dessiner == false)
                    {
                        dessiner = true;
                    }
                    else 
                    {
                        dessiner = false;
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    if (bounds1.contains(mousePos))
                    {
                        options = 0;
                        dessiner = false;
                        numbre = 5;
                    }
                    else if (bounds2.contains(mousePos))
                    {
                        options = 1;
                        dessiner = false;
                        numbre = 5;
                    }
                    else if (bounds3.contains(mousePos))
                    {
                        color = sf::Color::White;
                        dessiner = false;
                        numbre = 5;
                    }
                    else if (bounds4.contains(mousePos))
                    {
                        color = sf::Color::Black;
                        dessiner = false;
                        numbre = 5;
                    }
                    else if (bounds5.contains(mousePos))
                    {
                        color = sf::Color::Red;
                        dessiner = false;
                        numbre = 5;
                    }
                    else if (bounds6.contains(mousePos))
                    {
                        color = sf::Color::Blue;
                        dessiner = false;
                        numbre = 5;
                    }
                    else if (bounds7.contains(mousePos))
                    {
                        color = sf::Color::Green;
                        dessiner = false;
                        numbre = 5;
                    }
                    else if (bounds8.contains(mousePos))
                    {
                        color = sf::Color::Yellow;
                        dessiner = false;
                        numbre = 5;
                    }
                    else if (bounds9.contains(mousePos))
                    {
                        coordonnees = {};
                        dessiner = false;
                        numbre = 5;
                    }
                }
            }
            if (dessiner)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(screen);
                vector<int> coordonnees_locales;
                if (options == 0)
                {
                    mousePosition.x = Cinq(mousePosition.x);
                    mousePosition.y = Cinq(mousePosition.y);
                }
                else
                {
                    mousePosition.x = dix(mousePosition.x);
                    mousePosition.y = dix(mousePosition.y);
                }
                coordonnees_locales.push_back(mousePosition.x);
                coordonnees_locales.push_back(mousePosition.y); 
                if (options == 0)
                {
                    coordonnees_locales.push_back(5);
                }
                else if (options == 1)
                {
                    coordonnees_locales.push_back(10);
                }
                if (color == sf::Color::Black)
                {
                    coordonnees_locales.push_back(0);
                }
                else if (color == sf::Color::White)
                {
                    coordonnees_locales.push_back(1);
                }
                else if (color == sf::Color::Red)
                {
                    coordonnees_locales.push_back(2);
                }
                else if (color == sf::Color::Blue)
                {
                    coordonnees_locales.push_back(3);
                }
                else if (color == sf::Color::Yellow)
                {
                    coordonnees_locales.push_back(4);
                }
                else if (color == sf::Color::Green)
                {
                    coordonnees_locales.push_back(5);
                }
                coordonnees.push_back(coordonnees_locales);
            }
            numbre += 1;
            
        }   
            screen.clear(sf::Color::White);

            for (size_t i(0); i < coordonnees.size(); i++)
            {
                if (coordonnees[i][2] == 5)
                {
                    sf::RectangleShape rectangle(sf::Vector2f(5.f, 5.f));
                    rectangle.setPosition(static_cast<float>(coordonnees[i][0]), static_cast<float>(coordonnees[i][1]));
                    if (coordonnees[i][3] == 0)
                    {
                        rectangle.setFillColor(sf::Color::Black);
                    }
                    else if (coordonnees[i][3] == 1)
                    {
                        rectangle.setFillColor(sf::Color::White);
                    }
                    else if (coordonnees[i][3] == 2)
                    {
                        rectangle.setFillColor(sf::Color::Red);
                    }
                    else if (coordonnees[i][3] == 3)
                    {
                        rectangle.setFillColor(sf::Color::Blue);
                    }
                    else if (coordonnees[i][3] == 4)
                    {
                        rectangle.setFillColor(sf::Color::Yellow);
                    }
                    else if (coordonnees[i][3] == 5)
                    {
                        rectangle.setFillColor(sf::Color::Green);
                    }
                    screen.draw(rectangle);
                }
                else 
                {
                    sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));
                    rectangle.setPosition(static_cast<float>(coordonnees[i][0]), static_cast<float>(coordonnees[i][1]));
                    screen.draw(rectangle);
                    if (coordonnees[i][3] == 0)
                    {
                        rectangle.setFillColor(sf::Color::Black);
                    }
                    else if (coordonnees[i][3] == 1)
                    {
                        rectangle.setFillColor(sf::Color::White);
                    }
                    else if (coordonnees[i][3] == 2)
                    {
                        rectangle.setFillColor(sf::Color::Red);
                    }
                    else if (coordonnees[i][3] == 3)
                    {
                        rectangle.setFillColor(sf::Color::Blue);
                    }
                    else if (coordonnees[i][3] == 4)
                    {
                        rectangle.setFillColor(sf::Color::Yellow);
                    }
                    else if (coordonnees[i][3] == 5)
                    {
                        rectangle.setFillColor(sf::Color::Green);
                    }
                    screen.draw(rectangle);
                }
                
            }

            for (auto& element : couleurs)
            {
                screen.draw(element);
            }



            screen.draw(sprite1);
            screen.draw(sprite2);
            screen.draw(sprite3);
            screen.draw(sprite4);

            screen.display();
        
    }

    return 0;
}