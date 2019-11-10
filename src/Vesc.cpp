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

    // wait for connection
    sleep(2);
    listenUart();

    boost::thread t(boost::bind(&boost::asio::io_service::run, m_io.get()));
    m_ioThread.swap(t);
}

void Vesc::sendPacket(const VescMessage& message) const
{
    VescMessage finalMessage = message.finalize();

    // send message
    boost::asio::write(*m_serial, boost::asio::buffer(finalMessage.data(), finalMessage.size()));
}

void Vesc::uartCallback(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    if (!error && bytes_transferred > 0)
    {
    }
    listenUart();
}

void Vesc::listenUart()
{
    m_serial->async_read_some(boost::asio::buffer(m_receiveBuffer, 16),
                              boost::bind(&Vesc::uartCallback,
                                          this,
                                          boost::asio::placeholders::error,
                                          boost::asio::placeholders::bytes_transferred));
}

} // namespace vescuart
