#include "doctest.h"
#include "sources/Notebook.hpp"

#include <string>
using namespace ariel;
using namespace std;



TEST_CASE("TEST read/write function : valid write meaning we didnt write in that place yet and on the way we check read also"){
    Notebook note2;
    note2.write(0,0,0,Direction::Horizontal,"that the start of the notebook");
    CHECK(note2.read(0,0,0,Direction::Horizontal,30)=="that the start of the notebook");
    note2.write(0,1,0,Direction::Vertical,"second time writing");
    CHECK(note2.read(0,1,0,Direction::Vertical,19)=="second time writing");
    char msg[100];
    for (int i = 0; i <100 ; ++i) {
        msg[i]='_';
    }
    for ( int i = 0; i < 100; ++i) {
        note2.write(1,0,i,Direction::Horizontal,"a");
        msg[i]='a';
        CHECK(note2.read(1,0,0,Direction::Horizontal,100)==msg);

    }

}
TEST_CASE("TEST write function:: invalid writing meaning we already write to that place or invalid input"){
    Notebook note3;
    note3.write(0,0,0,Direction::Horizontal,"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    note3.write(1, 0, 0, Direction::Vertical, "Let's check if an error will occur if we'll write again");
    for ( int i = 0; i <45 ; i++) {
        CHECK_THROWS(note3.write(0,0,i,Direction::Horizontal,"t"));
        CHECK_THROWS(note3.write(0,0,i,Direction::Vertical,"y"));
        CHECK_THROWS(note3.write(1, i, 0, Direction::Vertical, "anything"));
    }
            CHECK_THROWS(note3.write(2, 0, 0, Direction::Horizontal, "this sentence is going to be larger than 100 chars so we need to throw an error because of what we have been told to do"));
            CHECK_THROWS(note3.write(2, 1, 80, Direction::Horizontal, "this sentence is going to be overload the 100 chars"));
            CHECK_THROWS(note3.write(-1, 0, 0, Direction::Horizontal, "anything"));
            CHECK_THROWS(note3.write(0, -1, 0, Direction::Horizontal, "anything"));
            CHECK_THROWS(note3.write(0, 0, -1, Direction::Horizontal, "anything"));
            CHECK_THROWS(note3.write(0, -1, -1, Direction::Horizontal, "anything"));
            CHECK_THROWS(note3.write(-1, -1, 0, Direction::Horizontal, "anything"));
            CHECK_THROWS(note3.write(-1, 0, -1, Direction::Horizontal, "anything"));
            CHECK_THROWS(note3.write(-1, -1, -1, Direction::Horizontal, "anything"));
            CHECK_THROWS(note3.read(-1, 0, 0, Direction::Horizontal, 10));
            CHECK_THROWS(note3.read(0, -1, 0, Direction::Horizontal, 10));
            CHECK_THROWS(note3.read(0, 0, -1, Direction::Horizontal, 10));
            CHECK_THROWS(note3.read(0, -1, -1, Direction::Horizontal, 10));
            CHECK_THROWS(note3.read(-1, -1, 0, Direction::Horizontal, 10));
            CHECK_THROWS(note3.read(-1, 0, -1, Direction::Horizontal, 10));
            CHECK_THROWS(note3.read(-1, -1, -1, Direction::Horizontal, 10));
            CHECK_THROWS(note3.read(-1, -1, -1, Direction::Horizontal, -1));
            CHECK_THROWS(note3.read(0, 0, 0, Direction::Horizontal, -1));

}
TEST_CASE("erase function"){
    Notebook note4;
    note4.erase(0,0,0,Direction::Horizontal,100);
    for ( int i = 0; i < 100; ++i) {
        CHECK(note4.read(0,0,i,Direction::Horizontal,1)=="~");
    }
    note4.write(1, 0, 0, Direction::Horizontal, "Let's check the erase function");
    note4.erase(1, 0, 0, Direction::Horizontal, 20);
            CHECK(note4.read(1, 0, 0, Direction::Vertical, 30) == "~_____________________________");
            CHECK(note4.read(1, 0, 0, Direction::Vertical, 20) == "~___________________");
            CHECK(note4.read(1, 0, 20, Direction::Horizontal, 10) == "e function");

            CHECK_THROWS(note4.erase(-1, 0, 0, Direction::Horizontal, 20));
            CHECK_THROWS(note4.erase(0, -1, 0, Direction::Horizontal, 20));
            CHECK_THROWS(note4.erase(0, 0, -1, Direction::Horizontal, 20));
            CHECK_THROWS(note4.erase(0, -1, -1, Direction::Horizontal, 20));
            CHECK_THROWS(note4.erase(-1, -1, 0, Direction::Horizontal, 20));
            CHECK_THROWS(note4.erase(-1, 0, -1, Direction::Horizontal, 20));
            CHECK_THROWS(note4.erase(-1, -1, -1, Direction::Horizontal, 20));
            CHECK_THROWS(note4.erase(-1, -1, -1, Direction::Horizontal, -1));
            CHECK_THROWS(note4.erase(0, 0, 0, Direction::Horizontal, -1));


}

TEST_CASE("TEST for write and read functions: good horizontal") {
    Notebook nb1;
    nb1.write(0, 0, 0, Direction::Horizontal, "notebook write function test");
            CHECK(nb1.read(0, 0, 0, Direction::Horizontal, 28) == "notebook write function test");
    nb1.write(0, 3, 0, Direction::Horizontal, "this is fun");
            CHECK(nb1.read(0, 3, 0, Direction::Horizontal, 11) == "this is fun");
    nb1.write(0, 10, 0, Direction::Horizontal, "now let's check in the middle");
            CHECK(nb1.read(0, 10, 16, Direction::Horizontal, 13) == "in the middle");
}

TEST_CASE("TEST for write and read functions: good vertical") {
    Notebook nb2;
    nb2.write(0, 0, 0, Direction::Vertical, "notebook write function test");
            CHECK(nb2.read(0, 0, 0, Direction::Vertical, 28) == "notebook write function test");
    nb2.write(0, 50, 0, Direction::Vertical, "this is fun");
            CHECK(nb2.read(0, 50, 0, Direction::Vertical, 11) == "this is fun");
}
