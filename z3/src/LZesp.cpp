#include "LZesp.hh"
#include<cmath>
#include<iostream>

LZesp::LZesp(){
  re = 0;
  im = 0;
}



LZesp LZesp::operator + (const LZesp & Z) const {
  LZesp  W;
  W.re = this->re + Z.re;
  W.im = this->im + Z.im;
  return W;
}

LZesp LZesp::operator += (const LZesp & Z) const {
  LZesp W;
  W.re = this->re + Z.re;
  W.im = this->im + Z.im;
  return W;
}

LZesp LZesp::operator - (const LZesp & Z) const {
  LZesp  W;
  W.re = this->re - Z.re;
  W.im = this->im - Z.im;
  return W;
}

LZesp LZesp::operator * (const LZesp & Z) const {
  LZesp  W;
  W.re = (this->re * Z.re) - (this->im * Z.im);
  W.im = (this->re * Z.im) + (this->im * Z.re);
  return W;
}

bool LZesp::operator == (const LZesp & W) const {
  if (this->re == W.re){
    if (this->im == W.im)
      return true;
  }
  return false;
}

LZesp LZesp::sprzezenie()const{
  LZesp X;
  X.re=this->re;
  X.im=(-1)*this->im;

  return X;
}

LZesp LZesp :: operator /(const LZesp & Z) const {
  LZesp X;

  X=(*this*Z.sprzezenie())/(Z*Z.sprzezenie());

  return X;  
}


LZesp LZesp :: operator * (double li)const{
  LZesp X;

  X.re=this->re*li;
  X.im=this->im*li;
  return X;
}




double LZesp :: mnoz() const{
  LZesp x;
  x=*this*(*this).sprzezenie();
  
  return x.re+x.im;
}


std::ostream & operator << (std::ostream &strm, const LZesp & Z){

  strm << '(' << Z.re << std::showpos << Z.im << std::noshowpos << "i" <<")";
  return strm;
}


std::istream & operator >> (std::istream &strm, LZesp &Z) {
  char znak;
  strm >> znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit);

  strm >> Z.re >> Z.im >> znak;
  if (znak != 'i')
    strm.setstate(std::ios::failbit);

  strm >> znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit);
  return strm;
}





