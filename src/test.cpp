/** 
 * @file 
 * @author   Jason M. Carter (jmcarter9t@gmail.com)
 * @date     July 2017
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "tool.hpp"

class Test : public tool::Tool {

    public:

        Test( const std::string& description );
        ~Test();
        int operator()(void);

    private:
};

Test::Test( const std::string& description ) :
    Tool{ "test", description }
{
}

Test::~Test() 
{
}

int Test::operator()(void) {
    std::cout << "testing...\n";
    return EXIT_SUCCESS;
}

#ifndef _TESTS

int main( int argc, char* argv[] )
{
    Test test{"Test stub for Tool"};
    test.addOption( 'h', "help", "print out some help" );
    test.addOption( 'r', "run", "run the tests" );

    if (!test.parseArgs(argc, argv)) {
        test.usage();
        std::exit( EXIT_FAILURE );
    }

    if (test.optIsSet('h')) {
        test.help();
        std::exit( EXIT_SUCCESS );
    }

    if (test.optIsSet('r')) {
        std::exit( test.run() );
    } else {
        test.usage();
        std::exit( EXIT_FAILURE );
    }
}

#endif
