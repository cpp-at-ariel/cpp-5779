/**
 * Specialization of a vector class to handle vector<bool> more efficiently.
 * 
 * Author: Peter Gottschling
 * Url: https://github.com/petergottschling/discovering_modern_cpp/blob/master/c%2B%2B11/derivative.cpp
 */

#include <cassert>
#include <iostream>
#include <memory>
#include <algorithm>

template <typename T>
class vector 
{
    void check_size(int that_size) const { assert(my_size == that_size); }
    void check_index(int i) const { assert(i >= 0 && i < my_size); }
  public:
    explicit vector(int size)
      : my_size(size), data( new T[my_size] )
    {}

    vector()
      : my_size(0), data(0)
    {}

    vector(const vector& that)
      : my_size(that.my_size), data(new T[my_size])
    {
    	std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
    }

    vector& operator=(const vector& that) 
    {
      check_size(that.my_size);
      std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
      return *this;
    }

    int size() const { return my_size; }

    const T& operator[](int i) const 
    {
        check_index(i);
        return data[i];
    }
		     
    T& operator[](int i) 
    {
        check_index(i);
        return data[i];
    }

    vector operator+(const vector& that) const 
    {
        check_size(that.my_size);
        vector sum(my_size);
        for (int i= 0; i < my_size; ++i) 
            sum[i] = data[i] + that[i];
        return sum;
    }
  private:
    int                   my_size;
    std::unique_ptr<T[]>  data;
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v)
{
  os << '[';
  for (int i= 0; i < v.size(); ++i) 
    os << v[i] << ',';
  os << ']';
  return os;
}


/**
 * Represents a reference to a single bit 
 *    inside a char.
 */
class vector_bool_proxy
{
  private:
    unsigned char& byte;
    unsigned char  mask;
    
  public:
    vector_bool_proxy(unsigned char& byte, int p): 
      byte(byte), 
      mask(1 << p) {}

    operator bool() const { 
      return byte & mask; 
    }

    vector_bool_proxy& operator=(bool b) 
    { 
        if (b==true)
            byte |= mask;
        else // b==false
            byte &= ~mask;
        return *this; 
    }

};

template <>
class vector<bool> 
{
  private:
    int   my_size;
    unsigned char* data;
  public:
    explicit vector(int size)
      : my_size(size),
      data(new unsigned char
        [(my_size+7) / 8])
    {}

    vector() : my_size(0) {}
  
    bool operator[](int i) const { 
      return (data[i/8] >> i%8) & 1; 
    }

    vector_bool_proxy operator[](int i) 
    { return {data[i/8], i%8};   }

    int size() const { return my_size; }
    // NOTE: size() is not "inherited" from the generic vector!
    // You must define it, with all other methods,
    // in each specialization!

};





int main() {
    vector<float> v( 4 );
    v[0]= v[1]= 1.0; v[2]= 2.0; v[3] = -3.0;

    std::cout << "v = " << v << std::endl;

    vector<float> w(v.size());
    w = v;

    vector<float> sum( w + v );
    std::cout << "w + v = " << sum << std::endl;

    vector<float> z( v );


    vector<bool>  b(13);
    for (int i= 0; i < 13; i++)
		  b[i] = i % 3;
    std::cout << "b = " << b << std::endl;
    for (int i= 0; i < 13; i++)
		  std::cout << b[i];
    std::cout << '\n';

    return 0;
}
