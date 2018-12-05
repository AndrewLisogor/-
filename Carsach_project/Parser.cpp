//
// Created by Andrew on 12/8/17.
//

#include "Parser.h"

    inline void parser_exeption:: display() {
            std::cout << "Error #" << num_of_error << " Description : " << description_of_error << "\n";
        }

    Parser::Parser() {
        get_l();
        try {
            if (!correct_parsing()) {
                throw parser_exeption(parsed_to_words.size(), "Inncorrect input!");
            }
        } catch (parser_exeption & exp) {
            exp.display();
        }

    }
    void Parser::get_l() {
        size_t pos = 0;
        getline(std::cin, input_str);
        std::string temp_str = input_str;
        temp_str.push_back(' ');
        while ((pos = temp_str.find(" ")) != std::string::npos) {
            parsed_to_words.push_back(temp_str.substr(0, pos));
            temp_str.erase(0, pos + 1);
        }
    }
    inline bool Parser::correct_parsing() {
        return (parsed_to_words.size() == 4);
    }

