#include "Label.hpp"
#include "Theme.hpp"

namespace guiSingle
{

Label::Label(const sf::String& string)
{
    m_text.setFont(Theme::getFont());
    m_text.setPosition(Theme::PADDING, Theme::PADDING);
    m_text.setFillColor(Theme::click.textColor);
    m_text.setCharacterSize(Theme::textSize);
    setSelectable(false);
    setText(string);
}


void Label::setText(const sf::String& string)
{
    m_text.setString(string);
    updateGeometry();
}


const sf::String& Label::getText() const
{
    return m_text.getString();
}


void Label::setFillColor(const sf::Color& color)
{
    m_text.setFillColor(color);
}


const sf::Color& Label::getFillColor() const
{
    return m_text.getFillColor();
}


void Label::setTextSize(size_t size)
{
    m_text.setCharacterSize(size);
    updateGeometry();
}


size_t Label::getTextSize() const
{
    return m_text.getCharacterSize();
}


void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_text, states);
}


void Label::updateGeometry()
{
    Widget::setSize(
        m_text.getLocalBounds().width + Theme::PADDING * 2,
        m_text.getLocalBounds().height + Theme::PADDING * 2
    );
}

}
