#ifndef GUI_ARROW_SINGLE_HPP
#define GUI_ARROW_SINGLE_HPP

#include <SFML/Graphics.hpp>

namespace guiSingle
{

class Arrow: public sf::Drawable
{
public:
    enum Direction { Left, Right, Top, Bottom };

    Arrow(Direction direction);

    void setFillColor(const sf::Color& color);

    void move(float dx, float dy);
    void setPosition(float x, float y);

    sf::Vector2f getSize() const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void updateGeometry(float x, float y, Direction direction);

    sf::Vertex m_vertices[4];
    Direction m_direction;
};

}

#endif // GUI_ARROW_SINGLE_HPP
