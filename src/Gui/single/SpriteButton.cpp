#include "SpriteButton.hpp"
#include "Theme.hpp"

namespace guiSingle
{

SpriteButton::SpriteButton(const sf::Texture& texture, const sf::String& string):
    Widget(),
    m_pressed(false)
{
    size_t width = texture.getSize().x;
    size_t height = texture.getSize().y / 3; // default, hover, focus

    m_background.setTexture(texture);
    m_background.setTextureRect(sf::IntRect(0, 0, width, height));

    setSize(width, height);

    m_text.setFont(Theme::getFont());
    m_text.setCharacterSize(Theme::textSize);

    setString(string);
}


void SpriteButton::setString(const sf::String& string)
{
    m_text.setString(string);
    centerText(m_text);
    std::cout << "text at " << m_text.getPosition().y << std::endl;
    std::cout << "line spacing = " << m_text.getLineSpacing() << std::endl;
}


const sf::String& SpriteButton::getString() const
{
    return m_text.getString();
}


void SpriteButton::setFont(const sf::Font& font)
{
    m_text.setFont(font);
    centerText(m_text);
}


const sf::Font& SpriteButton::getFont() const
{
    return *m_text.getFont();
}

State SpriteButton::getState() const {
  return m_state;
}

void SpriteButton::setTextSize(size_t size)
{
    m_text.setCharacterSize(size);
    centerText(m_text);
}


void SpriteButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_background, states);
    target.draw(m_text, states);
}


// Callbacks -------------------------------------------------------------------

void SpriteButton::onStateChanged(State state)
{
    sf::Vector2f size = getSize();
    switch (state)
    {
    case StateDefault:
        m_background.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
        break;
    case StateHovered:
        m_background.setTextureRect(sf::IntRect(0, size.y, size.x, size.y));
        break;
    case StatePressed:
    case StateFocused:
        m_background.setTextureRect(sf::IntRect(0, size.y * 2, size.x, size.y));
        break;
    }

    m_state = state;
}


void SpriteButton::onMouseMoved(float x, float y)
{
    if (isFocused())
    {
        if (containsPoint({x, y}) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            press();
        else
            release();
    }
}


void SpriteButton::onMousePressed(float, float)
{
    press();
}


void SpriteButton::onMouseReleased(float x, float y)
{

    release();
    if (containsPoint({x, y}))
    {
        triggerCallback();
    }
}


void SpriteButton::onKeyPressed(const sf::Event::KeyEvent& key)
{
    if (key.code == sf::Keyboard::Return)
    {
        triggerCallback();
        press();
    }
}


void SpriteButton::onKeyReleased(const sf::Event::KeyEvent& key)
{
    if (key.code == sf::Keyboard::Return)
        release();
}


void SpriteButton::press()
{
    if (!m_pressed)
    {
        m_pressed = true;
        m_text.move(0, 1);
    }
}


void SpriteButton::release()
{
    if (m_pressed)
    {
        m_pressed = false;
        m_text.move(0, -1);
    }
}

}

