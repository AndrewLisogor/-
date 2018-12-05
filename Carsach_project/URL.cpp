//
// Created by Andrew on 12/8/17.
//

#include "URL.h"


    void url_exeption::display() {		// ????????? ?-?? display()
        std::cout << "Error #" << num_of_error << " Description : " << description_of_error << "\n";
    }

    void URL::correct_url() {			// ????????? ?-?? correct_url()

        int position;
        std::string http = "http://www.";
        std::string https = "https://www.";
        for (int i = 0; i < http.size(); i++) {
            if (http[i] != url[i] && https[i] != url[i]) {
                throw url_exeption(i * i, "Inncorrect url");
            }
            position = i;
        }
        while (url[position] != '.') {
            position++;
            if (position == url.size()) {
                throw url_exeption(position, "Inncorrect url");
            }
        }
    }
    URL::URL() {						// ????????? ???????????? ????? URL
        url = parsed_to_words[2];
        writable = new char[url.size() + 1];
        std::copy(url.begin(), url.end(), writable);
        try {
            correct_url();
        } catch (url_exeption & exp) {
            exp.display();
        }

    }

