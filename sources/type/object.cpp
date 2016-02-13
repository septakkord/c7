#include <internal/type/object/scalar_holder>
#include <new>

namespace c7
{
    namespace type
    {
        object::object()
            : m_holder()
        {
        }

        object::~object()
        {
            if (m_holder)
                m_holder->~holder();
        }

        object object::clone() const
        {
            object result;
            if (m_holder)
                m_holder->clone(result.m_buffer);
            return result;
        }

        template <>
        void object::set_as(const std::int64_t& value)
        {
            m_holder = new(m_buffer)scalar_holder<std::int64_t>(value);
        }
    }
}
