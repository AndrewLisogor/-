//
// Created by Andrew on 12/8/17.
//

#ifndef EXAMPLE_PARSER_H
#define EXAMPLE_PARSER_H

#include <iostream>
#include <vector>
#include <string>
#include "exeption.h"


class Parser {										// ???? ???????? ????? ???????????
private:
    std::string input_str;							// ?????? ???
protected:
    std::vector < std::string > parsed_to_words;	// ??? ????????? ?? ?????
public:

    Parser();										
    void get_l();
    inline bool correct_parsing();

};
class parser_exeption: public exeption {
public: parser_exeption(int num_of_exeption_, std::string description_of_exeption_) {
        this -> num_of_error = num_of_exeption_;
        this -> description_of_error = description_of_exeption_;

    }
    inline void display();

};

#endif //EXAMPLE_PARSER_H
