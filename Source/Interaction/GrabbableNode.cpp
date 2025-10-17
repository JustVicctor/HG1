#include "GrabbableNode.h"

bool GrabbableNode::IsGrabbed() const
{
    return m_IsGrabbed;
}

void GrabbableNode::SetIsGrabbed(const bool isGrabbed)
{
    m_IsGrabbed = isGrabbed;
}

void GrabbableNode::_bind_methods()
{
}
