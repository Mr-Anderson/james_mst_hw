//////////////////////////////////////////////////////////////////////
/// @file main.cpp
/// @author James Anderson  Section A
/// @brief Main implementation file for assignment 1
////////////////////////////////////////////////////////////////////// 
// compilation code g++ *.cpp-I/usr/local/include -L/usr/local/lib -lcppunit -ldl

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main ()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry
        = CppUnit::TestFactoryRegistry::getRegistry();

    runner.addTest (registry.makeTest ());

    return runner.run ("", false);
}

