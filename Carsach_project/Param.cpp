//
// Created by Andrew on 12/8/17.
//

#include "Param.h"
    void param_exeption:: display() {		// ????????? ?-?? display()
        std::cout << "Error #" << num_of_error << " Description : " << description_of_error << "\n";
    }

    inline bool Param::correct_param() {	// ????????? ?-?? correct_param()

        return (parametr >= 'a' && parametr <= 'd');

    }
    Param::Param() {						// ????????? ??????????? ????? Param
        parametr = parsed_to_words[1][1];
        try {
            if (!correct_param()) {
                throw param_exeption(parametr, "Inncorrect parametr");
            }
        } catch (param_exeption & exp) {
            exp.display();
        }
    }
