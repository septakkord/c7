#include <test/suite>
#include <test/run>

namespace test
{
    suite::suite()
    {
        run::add(this);
    }
}
