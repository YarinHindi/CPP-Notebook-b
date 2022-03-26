#include "Notebook.hpp"
#include <iostream>
#include "Direction.hpp"
#include <stdexcept>
#include <string>
using ariel::Notebook;
using namespace std;

   Notebook::Notebook(){

};
    void  Notebook::init_row( int page,  int row)  {
        try {
            this->MyNotebook.at(page).at(row);
        }
        catch (exception& ex) {
            char *arr = new char[ROW_LENGHT];
            for ( int i = 0; i < ROW_LENGHT; ++i) {
                arr[i] ='_';
            }
            this->MyNotebook[page][row] = arr;
        }
    }
        bool Notebook::check_if_already_written(int page, int row, int columns, ariel::Direction direction, int length) {

        if(direction==Direction::Horizontal){

            for ( int i = columns; i < columns+length; ++i) {
                if(this->MyNotebook.at(page).at(row)[i]=='~'||this->MyNotebook.at(page).at(row)[i]!='_'){
                    return true;
                }
            }
        }else{
            for ( int i = row; i < row+length; ++i) {
                if(this->MyNotebook.at(page).at(i)[columns]=='~'||this->MyNotebook.at(page).at(i)[columns]!='_'){
                    return true;
                }
            }
        }
        return false;

        }

         bool Notebook::check_valid_string(string const &str){
            for (int i = 0; i < str.length(); i++) {
                unsigned int pos = (unsigned int)(i);
                if (str.at(pos)<' '|| str.at(pos) >= '~'){
                    return true;
                }

            }
            return false;

    }
        void Notebook::write(int page, int row, int columns, ariel::Direction direction, string const &str)  {
        int len = str.length();
        if(columns>ROW_LENGHT || (direction==Direction::Horizontal&&columns+len>ROW_LENGHT)||page<0||row<0||columns<0||str.length()<0||check_valid_string(str)){
            throw std::invalid_argument("you cant write in more than  written");

        }
        if(direction==Direction::Horizontal){
            init_row(page,row);
        }else{
            for ( int i = row; i < row+len ; ++i) {
                init_row(page,i);
            }
        }
        if(check_if_already_written(page,row,columns,direction,str.length())){
           throw std::invalid_argument("you cant write in place that already been written");
        }if(direction==Direction::Horizontal){
                for ( int i = columns; i <columns +len ; ++i) {
                    unsigned int pos = (unsigned int)(i-columns);
                    this->MyNotebook.at(page).at(row)[i] = str.at(pos);

                }
            }else{
                for ( int i = row; i <row +len ; ++i) {
                    unsigned int pos = (unsigned int)(i-row);
                    this->MyNotebook.at(page).at(i)[columns] = str.at(pos);
                }
            }
        }


         string Notebook::read(int page, int row, int columns, ariel::Direction direction, int len) {


        if(columns>ROW_LENGHT || (direction==Direction::Horizontal&&columns+len>ROW_LENGHT)||page<0||row<0||columns<0||len<0){
            throw std::invalid_argument("Invalid read");
        }
        if(direction==Direction::Horizontal){
            init_row(page,row);
        }else{
            for ( int i = row; i < row+len ; ++i) {
                init_row(page,i);
            }
        }
            string ans;
        if(direction==Direction::Horizontal){
            for ( int i = columns; i <columns +len ; ++i) {
               ans += this->MyNotebook.at(page).at(row)[i] ;
            }
        }else{
            for ( int i = row; i <row +len ; ++i) {
                ans += this->MyNotebook.at(page).at(i)[columns] ;
            }
        }
            return ans;
        }

        void Notebook::erase(int page, int row, int columns, ariel::Direction direction, int len)  {
            if (columns > ROW_LENGHT || (direction == Direction::Horizontal && columns + len > ROW_LENGHT) ||
                page < 0 || row < 0 || columns < 0 || len < 0) {
                throw std::invalid_argument("Invalid erase");
            }
            if (direction == Direction::Horizontal) {
                init_row(page, row);
            } else {
                for (int i = row; i < row + len; ++i) {
                    init_row(page, i);
                }
            }
            if (direction == Direction::Horizontal) {
                for (int i = columns; i < columns + len; ++i) {
                    this->MyNotebook.at(page).at(row)[i] = '~';
                }
            } else {
                for (int i = row; i < row + len; ++i) {
                    this->MyNotebook.at(page).at(i)[columns] = '~';
                }
            }
        }

        string Notebook::show(int p) {
            if (p < 0) {
                throw std::invalid_argument("Invalid page number");
            }
            string ans;
        for (int i = 0; i <ROW_LENGHT+3 ; ++i) {
            if(i>0){
                ans+='\n';
            }
            try {
                for (int j = 0; j < ROW_LENGHT+3; ++j) {
                    ans+= this->MyNotebook.at(p).at(i)[j];
                }
            }catch (exception ex){
                for (int j = 0; j < ROW_LENGHT; ++j)
                {
                    ans += '_';
                }
            }

        }
        ans+='\n';

            for (auto x: this->MyNotebook) {

            }
            return ans;

        }

