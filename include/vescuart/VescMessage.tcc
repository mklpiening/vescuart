template <typename T>
void VescMessage::add(T data)
{
    for (int i = sizeof(T) - 1; i >= 0; i--)
    {
        push_back(static_cast<uint8_t>((data >> (8 * i)) & 0xFF));
    }
}
