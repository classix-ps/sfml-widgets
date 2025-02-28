#ifndef GUI_SLIDER_SINGLE_HPP
#define GUI_SLIDER_SINGLE_HPP

#include "Widget.hpp"
#include "Utils/Box.hpp"

namespace guiSingle
{

/**
 * This widget provides a vertical or horizontal slider.
 * The slider is the classic widget for controlling a bounded value.
 * The callback is triggered when 'Return' key is pressed.
 */
class Slider: public Widget
{
public:
    enum Type { Horizontal, Vertical };

    Slider(float length = 200, Type type = Horizontal);
    Slider(float length, Type type, int size);

    int getStep() const;

    /**
     * Define the amount of units to change the slider when adjusting by drag and drop
     */
    void setStep(int step);

    int getValue() const;

    void setValue(int value);

    // callbacks ---------------------------------------------------------------
    void onKeyPressed(const sf::Event::KeyEvent& key) override;
    void onMousePressed(float x, float y) override;
    void onMouseMoved(float x, float y) override;
    void onMouseReleased(float x, float y) override;
    void onMouseWheelMoved(int delta) override;
    void onStateChanged(State state) override;

private:
    void updateHandlePosition();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    Type m_type;
    int  m_step;
    int  m_value;
    Box  m_box;
    sf::Vertex m_progression[4];
    Box  m_handle;
};

}

#endif // GUI_SLIDER_SINGLE_HPP
