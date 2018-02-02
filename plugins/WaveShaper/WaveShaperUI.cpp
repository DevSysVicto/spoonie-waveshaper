#include "DistrhoUI.hpp"

#include "WaveShaperUI.hpp"

START_NAMESPACE_DISTRHO

WaveShaperUI::WaveShaperUI() : UI(600, 600),
                               graphWidgetSocket(this, getParentWindow())
{
}

WaveShaperUI::~WaveShaperUI()
{
}

void WaveShaperUI::parameterChanged(uint32_t index, float value)
{
    parameters[index] = value;

    repaint();
}

void WaveShaperUI::stateChanged(const char *key, const char *value)
{
    if (std::strcmp(key, "graph") == 0)
        graphWidgetSocket.graphWidget.rebuildFromString(value);

    repaint();
}

void WaveShaperUI::onNanoDisplay()
{
}

void WaveShaperUI::uiIdle()
{
}

UI *createUI()
{
    return new WaveShaperUI();
}

END_NAMESPACE_DISTRHO