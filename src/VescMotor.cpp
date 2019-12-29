#include "vescuart/VescMotor.hpp"

#include <cstdint>

namespace vescuart
{

VescMotor::VescMotor(std::string port, int baudrate)
    : m_vesc(std::make_shared<Vesc>(port, baudrate)), m_canId(std::nullopt)
{
}

VescMotor::VescMotor(Vesc::Ptr vesc, std::optional<int> canId) : m_vesc(vesc), m_canId(canId) {}

bool VescMotor::setRpm(int rpm)
{
    VescMessage message(VescMessageType::setRpm, m_canId);
    message.add<int32_t>(static_cast<int32_t>(rpm));

    return m_vesc->sendPacket(message);
}

} // namespace vescuart
