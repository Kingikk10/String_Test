/*******************
Refer to string.h for instructions

Your string class should make it through this
guantlet without an assertion failing.

If it succeeds, then everything is awesome!
If you are stumped on a particular test,
or there is an unusual looking test you can't seem to get past,
you may comment it out, temporarily, to check further tests.

e-mail terry and I if you have any further questions or trouble.
esmes@aie.edu.au, Esmeralda Salamone
terryn@aie.edu.au, Terry Nguyen
********************/

#define _CRTDBG_MAP_ALLOC
#include <cassert>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif// dbgnew
#ifndef GLB_DEBUG
#define GLB_DEBUG
_CrtMemState s1, s2, s3;

#define mem_test_start() do{  \
_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE); \
_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT); \
_CrtMemCheckpoint(&s1);\
					}while (0)

#define mem_test_check() do{_CrtMemCheckpoint(&s2);\
						if(_CrtMemDifference(&s3, &s1, &s2))\
						{\
							_CrtMemDumpStatistics(&s3); \
							assert(_CrtDumpMemoryLeaks() == 0); \
						}\
						_CrtMemCheckpoint(&s1);\
					   }while(0)

#endif //glb
#else
#define mem_test_start()
#define mem_test_check()
#endif //debug


#include <sstream>
#include <iostream>
#include <climits>

#include "string.h"


//if you change the name of the namespace or class, adjust the typedef appropriately.
typedef sfw::string string;
using namespace sfw::literals;

void TEST_ALL_STRING_STUFF();

int main()
{
	TEST_ALL_STRING_STUFF();
	return 0;
}


void TEST_ALL_STRING_STUFF()
{
#ifndef _DEBUG
	return;
#endif
	//spit memory leaks to the console
	
	mem_test_start();

	// Constructors and length
	{
		//Default
		{
			assert(string().length() == 0);
			string a;
			string c = string();
			delete new string();
		}
		mem_test_check();
		//Size
		{
			assert(string(10).size() == 10);
			string b(10);
			string c = string(10);
			delete new string(10);
		}
		mem_test_check();
		//array
		{
			assert(string("Dinosaur").length() == 8);
			string b("Dinosaur");
			string c = string("Dinosaur");
			delete new string("Dinosaur");
			char *n = nullptr;
			delete new string(n);
		}
		mem_test_check();
		//array and size
		{
			assert(string("Dinosaur", 4).length() == 3);
			delete new string("Dinosaur", 2000);
		}
		mem_test_check();
		// move
		{
			assert(string(string()).length() == 0);
			assert(string(string(10)).size() == 10);
			assert(string("dinosaur").length() == 8);
			assert(string("dinosaur", 4).length() == 4);
			string &&r  = string();
			string &q = string(r);

			string d("Dinosaur");
			string m(std::move(d));  

			assert(d.length() == 0);
			assert(m.length() == 8);
		}
		mem_test_check();
		// copy
		{
			string a = string("dinosaur", 4);
			string b(a);
			string *c = new string(b);
			delete c;
			assert(b.length() == 3);
		}
		mem_test_check();
		// literal
		{
			string() = "what?"_sfw;
			string("yep"_sfw);
		}
		mem_test_check();
	}

	//Assignment Operators
	{
		
		//string copy/move
		{
			string b;
			b = b;
			string a = string(a);
			b = std::move(a);
			assert(a.length() == 0);
			a = "Dinosaur";
			b = std::move(b);
			a = b;
			b = a;
			assert(a.length() == b.length());
		}
		mem_test_check();
		//char array
		{
			string a;
			a = "Dinosaur";
			a = "Whoopie";
			char t[] = "Wumpus";
			a = t;
			char *trouble = new char;
			a = trouble;
		}
		mem_test_check();
	}

	//relational operators
	{

		//equivalence
		{	
			assert(""_sfw == "");
			assert("" == ""_sfw);
			assert(""_sfw == ""_sfw);

			assert("a"_sfw == "a");
			assert("b" == "b"_sfw);
			assert("c"_sfw == "c"_sfw);

			assert(!("a"_sfw == "A"));
			assert(!("b" == "B"_sfw));
			assert(!("c"_sfw == "C"_sfw));
		}
		mem_test_check();
		//nequals
		{
			assert(""_sfw != " ");
			assert("" != " "_sfw);
			assert(""_sfw != " "_sfw);

			assert(!("a"_sfw != "a"));
			assert(!("b" != "b"_sfw));
			assert(!("c"_sfw != "c"_sfw));
		}
		mem_test_check();
		//lesser
		{
			assert("a"_sfw <=  "b");
			assert("a" <= "a"_sfw);
			assert(!("b"_sfw <= "a"_sfw));

			assert("a"_sfw < "b");
			assert(!("a" < "a"_sfw));
			assert(!("b"_sfw < "a"_sfw));	
		}
		mem_test_check();
		//greater
		{
			assert("b"_sfw >= "a");
			assert("b" >= "b"_sfw);
			assert(!("a"_sfw >= "b"_sfw));

			assert("b"_sfw > "a");
			assert(!("b" > "b"_sfw));
			assert(!("a"_sfw > "b"_sfw));
		}
		mem_test_check();
	}
	
	//concat and assignconcat
	{

		//assign
		{
			assert((string() += "Dinosaur") == "Dinosaur");
			assert((string() += string()) == string());
			string b("woo");
			assert((b += "psies"_sfw) == "woopsies"_sfw);
		}
		mem_test_check();
		{
			assert(""_sfw+""=="");
			assert("" + ""_sfw == "");
			assert(""_sfw + ""_sfw == "");

			assert("dino"_sfw + "saur" == "dinosaur");
			assert("dino" + "saur"_sfw == "dinosaur");
			assert("dino"_sfw + "saur"_sfw == "dinosaur");
		}
		mem_test_check();
	}
	
	//miscellaneous operations
	{
		//subcript
		{
			assert("blah"_sfw[2] == 'a');
			string b("hmmh");
			b[2] = 'p';
			assert(b == "hmph");
		}
		mem_test_check();
		//stream operator
		{
			std::stringstream s;
			s << "blah"_sfw;
			string b;
			s >> b;
			assert(b == "blah"_sfw);
		}
		mem_test_check();
		//cstring
		{
			assert(strlen("blah"_sfw.cstring()) == 4);
			string d("ddd");
			assert(d == "dfd");
		}
		mem_test_check();
		//empty
		{
			assert(string().length() == 0);
			assert(string().empty());
			assert(string(23).empty());
			assert(!string("Dinosaur").empty());
			assert(!string(string("Dinosaur")).empty());
		}
		mem_test_check();
		//resize
		{
			string().resize(0);
			string().resize(ULLONG_MAX); // TROLLOLOL
			string(string()).resize(0);
			string(string(10)).resize(0);
			string d;
			d.resize(10);
			assert(d.size() == 10);
		}
		mem_test_check();
		//empty
		{
			assert(string().length() == 0);
			assert(string().empty());
			assert(string(23).empty());
			assert(!string("Dinosaur").empty());
			assert(!string(string("Dinosaur")).empty());
		}
		mem_test_check();
		//clear
		{
			string d("RAURGH");
			d.clear();
			assert(d == "");
			assert(d.length() == 0);
		}
		mem_test_check();
	}
}
