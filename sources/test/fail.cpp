#include "fail/fail_info"

namespace c7
{
    namespace test
    {
        fail::fail(const char* message, const char* file, int line)
            : m_info(std::make_shared<fail::info>(message, file, line))
        {
        }

        const char* fail::what() const
        {
            return m_info->get_output().c_str();
        }

        const char* fail::get_message() const
        {
            return m_info->get_message().c_str();
        }

        const char* fail::get_file() const
        {
            return m_info->get_file().c_str();
        }

        int fail::get_line() const
        {
            return m_info->get_line();
        }
    }
}
