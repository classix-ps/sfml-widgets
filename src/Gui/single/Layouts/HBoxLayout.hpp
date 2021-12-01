#ifndef GUI_HBOXLAYOUT_SINGLE_HPP
#define GUI_HBOXLAYOUT_SINGLE_HPP

#include "Layout.hpp"

namespace guiSingle
{

/**
 * Horizontally stacked layout
 */
class HBoxLayout: public Layout
{
public:
private:
    void recomputeGeometry() override;
};

}

#endif // GUI_HBOXLAYOUT_SINGLE_HPP
