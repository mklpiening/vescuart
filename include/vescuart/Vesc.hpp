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

    void sendPacket(const VescMessage& message) const;

  private:
    std::unique_ptr<boost::asio::io_service> m_io;
    std::unique_ptr<boost::asio::serial_port> m_serial;
};

} // namespace vescuart

#endif
