#pragma once

#include <random>
#include <limits>

/// This is an adaptor to uniform_int_distribution that works with
/// std::random_device{}() as the generator
template <class IntType = int> 
class dice {

private:

	std::default_random_engine _generator;
	std::uniform_int_distribution<IntType> _distribution;

public:

	typedef IntType result_type;
	
	///@see http://www.cplusplus.com/reference/random/uniform_int_distribution/uniform_int_distribution/
    dice(result_type a=0,
		 result_type b=std::numeric_limits<result_type>::max())
		: _generator(std::random_device{}()),
		  _distribution(a,b) {
    }

	///@see http://www.cplusplus.com/reference/random/uniform_int_distribution/min/
    result_type min() const {
        return _distribution.min();
    }

	///@see http://www.cplusplus.com/reference/random/uniform_int_distribution/max/
    result_type max() const {
        return _distribution.max();
    }
    
    /// Returns a random number between min() and max()
	///@see also http://www.cplusplus.com/reference/random/uniform_int_distribution/operator()/
    result_type operator()() {
		return _distribution(_generator);
    }
    
};
