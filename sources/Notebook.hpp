#include "Direction.hpp"
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
namespace ariel {
    // Defines a direction of a message on the board
     class Notebook {
     public:
         static constexpr int  ROW_LENGHT = 100;
         unordered_map<int ,unordered_map<int,char*>> MyNotebook;
         Notebook();
         void write( int page, int row, int columns,Direction direction,string  const & str) ;
         string read( int page, int row, int columns,Direction direction, int len) ;
         void erase( int page, int row, int columns,Direction direction, int len) ;
         string show( int p) ;
         bool check_if_already_written( int page,  int row,  int columns, ariel::Direction direction,  int length);
         static bool check_valid_string(string const &str);
         void init_row( int page,  int row) ;
     private:

    };

};