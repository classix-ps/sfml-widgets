#ifndef GUI_VBOXLAYOUT_SINGLE_HPP
#define GUI_VBOXLAYOUT_SINGLE_HPP

#include "Layout.hpp"

namespace guiSingle
{

/**
 * Vertically stacked layout
 */
class VBoxLayout: public Layout
{
private:
    void recomputeGeometry() override;
};

}

#endif // GUI_VBOXLAYOUT_SINGLE_HPP
