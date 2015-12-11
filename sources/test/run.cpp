#include <test/run>
#include <test/suite>
#include <algorithm>
#include <deque>

namespace test
{
    namespace
    {
        std::deque<suite*> g_scope;
    }

    run::run()
    {
        std::for_each(g_scope.begin(), g_scope.end(),
            [](suite* current)
            {
                current->run();
            }
        );
    }

    run::~run()
    {
        g_scope.clear();
    }

    void run::add(suite* new_suite)
    {
        g_scope.push_back(new_suite);
    }
}
