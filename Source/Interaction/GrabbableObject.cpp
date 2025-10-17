#include "GrabbableObject.h"

bool GrabbableObject::IsGrabbed() const
{
    return m_IsGrabbed;
}

void GrabbableObject::SetIsGrabbed(const bool isGrabbed)
{
    m_IsGrabbed = isGrabbed;
}

void GrabbableObject::_bind_methods()
{
}
