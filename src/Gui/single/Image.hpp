#ifndef GUI_IMAGE_SINGLE_HPP
#define GUI_IMAGE_SINGLE_HPP

#include "Widget.hpp"

namespace guiSingle
{

/**
 * Widget for displaying a picture
 * Passive widget: cannot be focused or trigger event
 */
class Image: public Widget
{
public:
    Image();
    Image(const sf::Texture& texture);

    void setTexture(const sf::Texture& texture);

    void setColor(const sf::Color& color);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vertex         m_vertices[4];
    const sf::Texture* m_texture;
};

}

#endif // GUI_IMAGE_SINGLE_HPP
