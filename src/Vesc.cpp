#include "vescuart/Vesc.hpp"

#include <boost/crc.hpp>
#include <iostream>

namespace vescuart
{

Vesc::Vesc(std::string port, int baudrate)
    : m_io(std::make_unique<boost::asio::io_service>()),
      m_serial(std::make_unique<boost::asio::serial_port>(*m_io, port))
{
    m_serial->set_option(boost::asio::serial_port_base::baud_rate(baudrate));
}

void Vesc::sendPacket(const VescMessage& message) const
{
    VescMessage finalMessage = message;

    // calculate crc
    boost::crc_16_type crc;
    crc.process_bytes(finalMessage.data(), finalMessage.size());
    uint16_t crcValue = crc.checksum();
    finalMessage.add<uint16_t>(crcValue);

    // send message
    boost::asio::write(*m_serial, boost::asio::buffer(finalMessage.data(), finalMessage.size()));
}

} // namespace vescuart
