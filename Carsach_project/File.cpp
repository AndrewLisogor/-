//
// Created by Andrew on 12/8/17.
//

#include "File.h"

    bool File::correct_file_name() {						// ????????? ?-?? correct_file_name()

        struct stat buffer;
        return (stat(file_name.c_str(), & buffer) == 0);

    }
    File::File() {											// ????????? ???????????? ????? File
        file_name = parsed_to_words[3];
        try{
            if(!correct_file_name()){
                throw file_name_exeption(file_name.size(), "Inncorrect file name!");
            }
        }
        catch(file_name_exeption & exp) {
            exp.display();
        }

    }


    void file_name_exeption::display() {					// ????????? ?-?? display()
        std::cout << "Error #" << num_of_error << "\nDescription : " << description_of_error;
    }
