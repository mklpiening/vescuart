#ifndef VESCUART_HPP
#define VESCUART_HPP

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <string>

namespace vescuart
{

class VescUart
{
  public:
    /**
     * @param port serial port for communication
     * @param baudrate baud rate of uart communication
     */
    VescUart(const std::string& port, int baudrate);

    /**
     * @brief sets the rpm of the motor that is connected to the vesc
     *
     * @param rpm targetted rpm of motor
     */
    void setRpm(int rpm) const;

  private:
    boost::thread m_ioThread;
    boost::asio::io_service m_io;
    boost::asio::serial_port m_serial;

    void sendPacket(const char* data, std::size_t length) const;
};

} // namespace vescuart

#endif
