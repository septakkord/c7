#include "fail_info"
#include <sstream>

namespace test
{
    fail::info::info(const char* message, const char* file, int line)
        : m_message(message), m_file(file), m_line(line)
    {
        std::stringstream output;
        output << "FAIL @" << m_file << '[' << m_line << "]: " << message;
        m_output = output.str();
    }

    const std::string& fail::info::get_output() const
    {
        return m_output;
    }

    const std::string& fail::info::get_message() const
    {
        return m_message;
    }

    const std::string& fail::info::get_file() const
    {
        return m_file;
    }

    int fail::info::get_line() const
    {
        return m_line;
    }
}
