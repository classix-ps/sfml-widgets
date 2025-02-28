#ifndef GUI_LABEL_SINGLE_HPP
#define GUI_LABEL_SINGLE_HPP

#include "Widget.hpp"


namespace guiSingle
{

/**
 * Widget for displaying a simple text
 * Passive widget: cannot be focused or trigger event
 */
class Label: public Widget
{
public:
    Label(const sf::String& string = "");

    /**
     * Label's text
     */
    void setText(const sf::String& string);
    const sf::String& getText() const;

    /**
     * Label's color
     */
    void setFillColor(const sf::Color& color);
    const sf::Color& getFillColor() const;

    void setTextSize(size_t size);
    size_t getTextSize() const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void updateGeometry();

    sf::Text m_text;
};

}

#endif // GUI_LABEL_SINGLE_HPP
