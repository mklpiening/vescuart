#include "vescuart/VescUart.hpp"

#include <boost/crc.hpp>

namespace vescuart
{

VescUart::VescUart(const std::string& port, int baudrate) : m_io(), m_serial(m_io, port)
{
    m_serial.set_option(boost::asio::serial_port_base::baud_rate(baudrate));

    boost::thread t(boost::bind(&boost::asio::io_service::run, &m_io));
    m_ioThread.swap(t);
}

void VescUart::setRpm(int rpm) const {}

void VescUart::sendPacket(const char* data, std::size_t length) const {
    // calculate crc
    boost::crc_16_type crc; 
    crc.process_bytes(data, length);
    uint16_t crcValue = crc.checksum();

    // build message
    char message[length + 2];
    std::memcpy(message, data, length);
    message[length + 0] = crcValue & 0xFF;
    message[length + 1] = (crcValue & 0x00FF) << 0x2;

    // send message
    //boost::asio::write(m_serial, boost::asio::buffer(message, length + 2));
}

} // namespace vescuart
