#include <test/run>
#include <test/fail>
#include <test/suite>
#include <algorithm>
#include <iostream>
#include <deque>

namespace test
{
    namespace
    {
        std::deque<suite*> g_scope;
        std::ostream* g_output = &std::cout;
    }

    run::run()
    {
        std::for_each(g_scope.begin(), g_scope.end(),
            [](suite* current)
            {
                try
                {
                    current->run();
                    *g_output << current->name() << " OK!" << std::endl;
                }
                catch (fail& failure)
                {
                    *g_output << current->name() << " FAIL: " << failure.what() << std::endl; // TODO: traceback
                }
                catch (std::exception& error)
                {
                    *g_output << current->name() << " ERROR: " << error.what() << std::endl;
                }
                catch (...)
                {
                    *g_output << current->name() << " ERROR: Unknown error." << std::endl;
                }
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
