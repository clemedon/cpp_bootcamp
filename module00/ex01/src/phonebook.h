// @author    Clément Vidon
// @created   230324 11:42:17  by  clem@spectre
// @modified  230324 11:42:22  by  clem@spectre
// @filename  phonebook.h

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#ifdef DEV
#  define MAX_CONTACT 3
#  define CLEAR       std::cout << ""
#else
#  define MAX_CONTACT 8
#  define CLEAR       std::cout << "\033[2J\033[1;1H"
#endif

#endif
