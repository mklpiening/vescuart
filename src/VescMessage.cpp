#include "vescuart/VescMessage.hpp"

namespace vescuart
{

VescMessage::VescMessage(VescMessageType type)
{
    addMessageType(type);
}

void VescMessage::addMessageType(VescMessageType type)
{
    add<uint8_t>(static_cast<uint8_t>(type));
}

void VescMessage::addForwardCan(std::optional<int> canId) {
    if (canId)
    {
        add<uint8_t>(static_cast<uint8_t>(canId.value()));
        addMessageType(VescMessageType::forwardCan);
    }
}

} // namespace vescuart
