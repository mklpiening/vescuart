#ifndef VESCUART_HPP
#define VESCUART_HPP

#include "vescuart/VescMessage.hpp"

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <string>

namespace vescuart
{

class Vesc
{
  public:
    using Ptr = std::shared_ptr<Vesc>;

    /**
     * @param port serial port for communication
     * @param baudrate baud rate of uart communication
     */
    Vesc(std::string port, int baudrate);

    /**
     * @brief sends a message to the configured device
     *
     * @param message message to send 
     */
    void sendPacket(const VescMessage& message) const;

  private:
    std::unique_ptr<boost::asio::io_service> m_io;
    std::unique_ptr<boost::asio::serial_port> m_serial;
    boost::thread m_ioThread;

    uint8_t m_receiveBuffer[16];

    /**
     * @brief gets called on incoming UART message
     *
     * @param error error of transmission
     * @param bytes_transferred amount of bytes transferred
     */
    void uartCallback(const boost::system::error_code& error, std::size_t bytes_transferred);

    /**
     * @brief starts listening to UART messages
     */
    void listenUart();
};

} // namespace vescuart

#endif
