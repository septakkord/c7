#include <test/run>
#include <test/check>
#include <test/suite>
#include <string>

namespace test
{
    class run_test : public suite
    {
    public:
        virtual const char* name() const override
        {
            return "Test of test run";
        }

        virtual void run() override
        {
            c7check(5) > -5;
            c7check(std::string()) == "";
            c7check(10) < 20;
            c7check(-5) <= -5.0f;
            c7check(1.0f) >= 0.9999999;
            c7check("a") < "b";
        }

    } g_run_test;
}
