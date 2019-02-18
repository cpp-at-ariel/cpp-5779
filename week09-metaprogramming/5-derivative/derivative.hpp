/**
 * Template for numerically calculating the n-th derivative.
 * 
 * Author: Peter Gottschling
 * Url: https://github.com/petergottschling/discovering_modern_cpp/blob/master/c%2B%2B11/derivative.cpp
 * Shortened by: Erel Segal-Halevi
 */

#include <cmath>
#include <iostream>
#include <boost/mpl/bool.hpp>

double SinCos(double x) {
    return sin(x) + cos(x);
}

struct SinCosFunctor {
    double operator() (double x) const { 
	    return sin(x) + cos(x);
    }
};


/**
 * A class for parametric sin-cos function objects.
 */
class paramSinCosFunctor {
  public:
    paramSinCosFunctor(double alpha) : alpha(alpha) {}
    double operator() (double x) const { 
	    return sin(alpha * x) + cos(x);
    }
  private:
    double alpha;
};

#if 0 
// We could do derivative with function pointers
double fin_diff(double f(double), double x, double h) 
{
    return ( f(x+h) - f(x) ) / h;
}
#endif

template <typename Function>
inline  double fin_diff(Function f, const  double& x, const  double& h) {
    return ( f(x+h) - f(x) ) / h;
}

template <typename Function>
class derivative
{
  private:
    const Function& f;
    double        h;
  public:
    derivative(
        const Function& f, 
        const  double& h): 
        f(f), h(h) {}

    double operator()(const  double& x) const {
	    return ( f(x+h) - f(x) ) / h;
    }
};

template<typename Function> 
auto derive(const Function& f, const  double& h) {
    return derivative<Function>(f,h);
}


#if 0
template <typename Function, unsigned N>
class nth_derivative
{
    using prev_derivative= nth_derivative<Function,  N-1>;
  public:
    nth_derivative(const Function& f, const  double& h) : h(h), fp(f, h) {}

     double operator()(const  double& x) const
    {
	return ( fp(x+h) - fp(x) ) / h;
    }    
  private:
     double        h;
    prev_derivative fp;
};

#else

//using Coordinate=vector<int>;
//typedef vector<int> Coordinate;

template <typename Function, unsigned N>
class nth_derivative
{
    using prev_derivative = 
        nth_derivative<Function,  N-1>;

  private:
     double          h;
     prev_derivative fp;   // (N-1)-th derivative of f
        
  public:
    nth_derivative(const Function& f, const  double& h): 
        h(h), 
        fp(f, h) {}      // Set fp to (N-1)-th derivative of f

     double operator()(const  double& x) const {
        return N & 1 ? 
            ( fp(x+h) - fp(x) ) / h 
                    : 
            ( fp(x) - fp(x-h) ) / h;
    }
};


#if 0 // for meta-programming, maybe
template <typename Function, unsigned N>
class nth_derivative
{
    using prev_derivative= nth_derivative<Function,  N-1>;
  public:
    nth_derivative(const Function& f, const  double& h) : h(h), fp(f, h) {}

     double operator()(const  double& x) const
    {
	return diff(x, boost::mpl::bool_<N & 1>());
    }
	
  private:

     double diff(const  double& x, boost::mpl::true_) const
    {
	return ( fp(x+h) - fp(x) ) / h;
    }    

     double diff(const  double& x, boost::mpl::false_) const
    {
	return ( fp(x) - fp(x-h) ) / h;
    }    

     double        h;
    prev_derivative fp;
};
#endif

#endif 

#if 0
template <typename Function>
class nth_derivative<Function,  1>
{
  public:
    nth_derivative(const Function& f, const  double& h): f(f), h(h) {}

     double operator()(const  double& x) const
    {
	    return ( f(x+h) - f(x) ) / h;
    }   
  private:
    const Function& f;
     double        h;
};
#else
template <typename Function>
class nth_derivative<Function,  1>
  : public derivative<Function>
{
    using derivative<Function>::derivative;

  // public:
  //   nth_derivative(const Function& f, const  double& h) : derivative<Function>(f, h) {}
};
#endif 


#if 0
template <typename Function, unsigned N> // Not clever
nth_derivative<Function,  N> 
make_nth_derivative(const Function& f, const  double& h)
{
    return nth_derivative<Function,  N>(f, h);
}
#endif




template <unsigned N, typename Function>
nth_derivative<Function,  N> 
make_nth_derivative(const Function& f, const  double& h)
{
    return nth_derivative<Function,  N>(f, h);
}

struct et {};

template <typename Function>
void error(const Function& f)
{
    et e= f;
}
