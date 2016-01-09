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
        int g_test_count = 0;
        int g_fail_count = 0;
        int g_error_count = 0;

        void run_suite(suite* current)
        {
            try
            {
                ++g_test_count;
                {
                    current->run();
                }
                *g_output << current->name() << " OK!" << std::endl;
            }
            catch (fail& failure)
            {
                ++g_fail_count;
                *g_output << current->name() << " FAIL!\n > " << failure.what() << std::endl; // TODO: traceback
            }
            catch (std::exception& error)
            {
                ++g_error_count;
                *g_output << current->name() << " ERROR!\n > " << error.what() << std::endl;
            }
            catch (...)
            {
                ++g_error_count;
                *g_output << current->name() << " UNKNOWN ERROR!" << std::endl;
            }
        }

        void output_result()
        {
            const char* result = g_fail_count || g_error_count ? "FAILURE" : "SUCCESS";
            *g_output << "\n > Errors:     " << g_error_count
                      << "\n > Fails:      " << g_fail_count
                      << "\n > Total:      " << g_test_count
                      << "\n > Result:  " << result << std::endl;
        }
    }

    run::run()
    {
        std::for_each(g_scope.begin(), g_scope.end(), run_suite);
        output_result();
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
