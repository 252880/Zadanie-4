#include "Macierz.cpp"


template class Macierz<LZesp,5>;
template std::istream & operator >> (std::istream &strm, Macierz<LZesp,5> &M);
template std::ostream & operator << (std::ostream &strm, const Macierz<LZesp,5> &M);


template class Macierz<double,5>;
template std::istream & operator >> (std::istream &strm, Macierz<double,5> &M);
template std::ostream & operator << (std::ostream &strm, const Macierz<double,5> &M);
