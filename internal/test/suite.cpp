#include <c7/test/suite>
#include <c7/test/run>

namespace c7
{
    namespace test
    {
        suite::suite()
        {
            run::add(this);
        }
    }
}
