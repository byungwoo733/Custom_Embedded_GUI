#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(640, 480), "Hello SFML");
    CircleShape shape(100.0f, 5);
    shape.setFillColor(Color::Blue);
    shape.setPosition(320.0f, 240.0f-50.0f);

    RectangleShape myRect(Vector2f(30.0f, 10.0f));
    myRect.setFillColor(Color::Cyan);
    myRect.setPosition(30.0f, 30.0f);

        while (window.isOpen())
        {
            //Shape Key Control Event
            Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if(Keyboard::isKeyPressed(Keyboard::Left) == true)
                    {
                        shape.move(-30.0f, 0.0f);
                    }
                    else if(Keyboard::isKeyPressed(Keyboard::Right) == true)
                    {
                        shape.move(30.0f, 0.0f);
                    }
                    break;
                    default:
                    break;
                }
                if(event.type == Event::Closed)
                {
                    window.close();
                }
            }

            window.clear();
            window.draw(shape);
            window.draw(myRect);
            window.display();
        }
    return 0;
}
