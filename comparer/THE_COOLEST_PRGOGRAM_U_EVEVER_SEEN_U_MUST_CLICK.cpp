#include <bits/stdc++.h>

void erasing_special_characters ();

struct Text {

	std::string line, input_line, word, input_word, directory, line_buffer;

	std::vector <std::string> resulted_lines;

	int allwords, notcorrect, line_counter, words_in_line, iwords_in_line, line_number, inc;
	bool ok;

} text;


int main () {

	text.input_line 	= "";
	text.words_in_line	= 0;
	text.iwords_in_line	= 0;
	text.allwords		= 0;
	text.notcorrect		= 0;
	text.line_counter	= 0;
	text.inc		= 0;
	text.ok			= false;


	std::cout << "directory?"
		  << std::endl;
	std::cin >> text.directory;
	std::cout << std::endl << std::endl;
	
	std::ifstream tekst (text.directory);

	while (std::getline (tekst, text.line)) {

		text.line_counter++;

	}

	tekst.clear();
	tekst.seekg(0, std::ios::beg);

	std::cout << "Which line you want to start with? [1 - " << text.line_counter 
		  << "]" << std::endl;
	std::cin >> text.line_number;
	std::cout << std::endl << std::endl;
	
	text.line_number--;


	if (text.line_number == 69419) {

		std::cout << "All that shit here" << std::endl;


		return 0;

	}

	for (int i = 0; i < text.line_number; i++) {

		std::getline (tekst, text.line);
	} 

	std::cin.ignore();

	for (text.inc = text.line_number; text.inc < text.line_counter; text.inc++) {

		std::cout << "Line " << text.inc + 1 << ":" << std::endl;

		std::getline (std::cin, text.input_line);
		std::getline (tekst, text.line);

		std::cout << std::endl;
		erasing_special_characters ();
		
		std::stringstream iss_input(text.input_line);

		while (iss_input >> text.input_word) {

			std::stringstream iss(text.line);

			text.words_in_line = 0;

			while (iss >> text.word) {

				if (text.word == text.input_word) {
				       text.ok = true;
				}
				
				text.words_in_line++;
			}

			if (text.ok != true) {
				
				text.notcorrect++;
				
				std::for_each(text.input_word.begin(),
                                              text.input_word.end(),
                                              [](char & c) {

                                     c = ::toupper(c);

                                });
			}


			text.line_buffer = text.line_buffer + " " + text.input_word;

			text.ok = false;

			text.iwords_in_line++;
		}
		
		text.allwords = text.allwords + text.words_in_line;

		if (text.words_in_line > text.iwords_in_line) {
			
			text.notcorrect = text.notcorrect + text.words_in_line-text.iwords_in_line;
		}

		text.resulted_lines.push_back (text.line_buffer);
		
		text.iwords_in_line = 0;
		text.line_buffer = "";

	}

	std::cout << std::endl << std::endl;
	tekst.clear();
	tekst.seekg(0,std::ios::beg);

	for (int i = 0; i < text.line_number; i++) {

                std::getline (tekst, text.line);
        }

	for (text.inc = text.line_number; text.inc < text.line_counter; text.inc++) {

		static int i = 0;

		std::cout << "Line " << text.inc + 1 << ":" << std::endl;

		std::cout << text.resulted_lines[i] << std::endl;
		i++;

		std::getline (tekst, text.line);
		std::cout << " " << text.line << std::endl << std::endl;

	}

	std::cout << std::endl << std::endl;
	std::cout << "Not corecct words: " << text.notcorrect << std::endl;
	std::cout << "All words: " << text.allwords << std::endl;
	std::cout << (text.allwords - text.notcorrect) * 100 / text.allwords << "%    ";

	tekst.close();

	
	return 0;

}


void erasing_special_characters () {

	int len_input_line = 0, len_line = 0;

	while (text.input_line[len_input_line]) {
		len_input_line++;
	}

	while (text.line[len_line]) {
		len_line++;
	}


	for (int i = 0; i < len_input_line; i++) {

		if (text.input_line[i] == '`' ||
		    text.input_line[i] == '~' ||
		    text.input_line[i] == '!' ||
		    text.input_line[i] == '@' ||
		    text.input_line[i] == '#' ||
		    text.input_line[i] == '$' ||
		    text.input_line[i] == '%' ||
		    text.input_line[i] == '^' ||
		    text.input_line[i] == '&' ||
		    text.input_line[i] == '*' ||
		    text.input_line[i] == '(' ||
		    text.input_line[i] == ')' ||
		    text.input_line[i] == '-' ||
		    text.input_line[i] == '_' ||
		    text.input_line[i] == '+' ||
		    text.input_line[i] == '=' ||
		    text.input_line[i] == '[' ||
		    text.input_line[i] == ']' ||
		    text.input_line[i] == '{' ||
		    text.input_line[i] == '}' ||
		    text.input_line[i] == '|' ||
		    text.input_line[i] == ';' ||
		    text.input_line[i] == ':' ||
		    text.input_line[i] == '"' ||
		    text.input_line[i] == ',' ||
		    text.input_line[i] == '.' ||
		    text.input_line[i] == '<' ||
		    text.input_line[i] == '>' ||
		    text.input_line[i] == '/' ||
		    text.input_line[i] == '?') {

			    len_input_line--;
			    text.input_line.erase (text.input_line.begin() + i);
			    i--;

		}
	}

	std::for_each(text.input_line.begin(), text.input_line.end(), [](char & c) {
                c = ::tolower(c);
        });

	for (int i = 0; i < len_line; i++) {

                if (text.line[i] == '`' ||
                    text.line[i] == '~' ||
                    text.line[i] == '!' ||
                    text.line[i] == '@' ||
                    text.line[i] == '#' ||
                    text.line[i] == '$' ||
                    text.line[i] == '%' ||
                    text.line[i] == '^' ||
                    text.line[i] == '&' ||
                    text.line[i] == '*' ||
                    text.line[i] == '(' ||
                    text.line[i] == ')' ||
                    text.line[i] == '-' ||
                    text.line[i] == '_' ||
                    text.line[i] == '+' ||
                    text.line[i] == '=' ||
                    text.line[i] == '[' ||
                    text.line[i] == ']' ||
                    text.line[i] == '{' ||
                    text.line[i] == '}' ||
                    text.line[i] == '|' ||
                    text.line[i] == ';' ||
                    text.line[i] == ':' ||
                    text.line[i] == '"' ||
                    text.line[i] == ',' ||
                    text.line[i] == '.' ||
                    text.line[i] == '<' ||
                    text.line[i] == '>' ||
                    text.line[i] == '/' ||
                    text.line[i] == '?') {

                            len_line--;
                            text.line.erase (text.line.begin() + i);
                            i--;

                }
        }

	std::for_each(text.line.begin(), text.line.end(), [](char & c) {
		c = ::tolower(c);
	});
}

