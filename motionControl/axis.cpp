#include "axis.h"

Axis::Axis()
{
    this->bIsEnable = false;
}

void Axis::Enable()
{
    this->bIsEnable = true;
}

void Axis::Disable()
{
    this->bIsEnable = false;
}
