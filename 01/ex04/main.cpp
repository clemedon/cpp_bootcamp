#include <cstring>
#include <fstream>
#include <iostream>

void replace( std::string& str, std::string const& s1, std::string const& s2 ) {
  int i;
  int len;
  int pos;

  pos = 0;
  len = str.size();
  for( i = 0; i < len; i += 1 ) {
    pos = str.find( s1, pos );
    if( pos != -1 ) {
      str.erase( pos, s1.size() );
      str.insert( pos, s2 );
    }
  }
}

void info( void ) {
  std::cerr << ".::::::::::> Search And Replace <:::::::::::." << std::endl;
  std::cerr << "::                                         ::" << std::endl;
  std::cerr << "::  Usage: ./replace file old new          ::" << std::endl;
  std::cerr << "::                                         ::" << std::endl;
  std::cerr << "::  Where:                                 ::" << std::endl;
  std::cerr << "::         file is a text file             ::" << std::endl;
  std::cerr << "::         s1   is the string to replace   ::" << std::endl;
  std::cerr << "::         s2   is the replacement string  ::" << std::endl;
  std::cerr << "::                                         ::" << std::endl;
  std::cerr << "::  Replace all the occurences of s1 with  ::" << std::endl;
  std::cerr << "::  s2 in the given file, thus s1 and s2   ::" << std::endl;
  std::cerr << "::  should be two differents strings.      ::" << std::endl;
  std::cerr << "::                                         ::" << std::endl;
  std::cerr << "'::::::::::::::::::::::::::::::::::::::::::'" << std::endl;
}

int main( int ac, char** av ) {
  std::ifstream ifs;
  std::ofstream ofs;
  std::string   buf;
  std::string   s1;
  std::string   s2;

  if( ac == 4 ) {
    s1 = av[2];
    s2 = av[3];
    if( !s1.compare( s2 ) ) {
      info();
      return 1;
    }
    ifs.open( av[1] );
    if( !ifs.is_open() ) {
      std::cerr << "Failure" << std::endl;
      return 1;
    }
    ofs.open( strcat( av[1], ".replace" ) );
    if( !ofs.is_open() ) {
      std::cerr << "Failure" << std::endl;
      return 1;
    }
    while( getline( ifs, buf ) ) {
      replace( buf, s1, s2 );
      ofs << buf << std::endl;
    }
    ifs.close();
    ofs.close();
  } else {
    info();
    return 1;
  }
  return 0;
}
