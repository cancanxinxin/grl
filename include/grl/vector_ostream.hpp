#ifndef GRL_VECTOR_OSTREAM_HPP
#define GRL_VECTOR_OSTREAM_HPP
#include <vector>
#include <ostream>
#include <boost/container/static_vector.hpp>

template< typename T >
inline std::ostream& write(std::ostream& out, const T& v)
{
  out << "[";
  size_t last = v.size() - 1;
  for(size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last)
      out << ", ";
  }
  out << "]";
  return out;
}

/// @todo figure out what to do if this conflicts with others' implementations of outputting vectors
template<typename T, typename U>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,U>& v)
{
  return write(out,v);
}


/// @todo move elsewhere, because it will conflict with others' implementations of outputting vectors
template<typename T, std::size_t U>
inline std::ostream& operator<<(std::ostream& out,  boost::container::static_vector<T,U>& v)
{
  return write(out,v);
}



/// @todo move somewhere that won't cause conflicts
template <typename T, size_t N>
inline std::ostream& operator<<(std::ostream &out,
                         const boost::container::static_vector<T, N> &v) {

  return write(out,v);
}


#endif // GRL_VECTOR_OSTREAM_HPP
