#ifndef GUI_WIDGET_SINGLE_HPP
#define GUI_WIDGET_SINGLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>

namespace guiSingle
{

enum State
{
    StateDefault,
    StateHovered,
    StatePressed,
    StateFocused
};

class Layout;

/**
 * Abstract base class for gui widgets
 */
class Widget: public sf::Drawable
{
public:
    Widget();

    /**
     * Widget's position
     */
    void setPosition(const sf::Vector2f& pos);
    void setPosition(float x, float y);
    const sf::Vector2f& getPosition() const;

    sf::Vector2f getAbsolutePosition() const;

    /**
     * Get widget's dimensions
     */
    const sf::Vector2f& getSize() const;

    /**
     * Check if a point is inside the widget
     */
    bool containsPoint(const sf::Vector2f& point) const;

    /**
     * Check if the widget can be selected and trigger events
     */
    bool isSelectable() const;

    /**
     * Check if the widget is currently focused
     */
    bool isFocused() const;

    /**
     * Set a function to be called when this widget is triggered
     */
    void setCallback(std::function<void(void)> callback);

    // Event callbacks ---------------------------------------------------------

    virtual void onStateChanged(State state);
    virtual void onMouseMoved(float x, float y);
    virtual void onMousePressed(float x, float y);
    virtual void onMouseReleased(float x, float y);
    virtual void onMouseWheelMoved(int delta);
    virtual void onKeyPressed(const sf::Event::KeyEvent& key);
    virtual void onKeyReleased(const sf::Event::KeyEvent& key);
    virtual void onTextEntered(sf::Uint32 unicode);

protected:
    void setSize(const sf::Vector2f& size);
    void setSize(float widget, float height);

    friend class Layout;
    friend class FormLayout;
    friend class HBoxLayout;
    friend class VBoxLayout;

    void setSelectable(bool selectable);

    /**
     * Notify parent that the widget has been triggered by user input
     */
    void triggerCallback();

    void setState(State state);
    State getState() const;

    /**
     * Set the widget's container (parent)
     */
    void setParent(Layout* parent);
    Layout* getParent() { return m_parent; }

    // hack...
    virtual Layout* toLayout() { return nullptr; }

    void centerText(sf::Text& text);

    virtual void recomputeGeometry() {};

    const sf::Transform& getTransform() const;

private:
    Layout*      m_parent;
    Widget*      m_previous;
    Widget*      m_next;

    State        m_state;
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    bool         m_selectable;

    std::function<void(void)> m_callback;

    sf::Transform m_transform;
};

}

#endif // GUI_WIDGET_SINGLE_HPP
