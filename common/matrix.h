#ifndef common_matrix_h
#define common_matrix_h

#include <cmath>
#include <iostream>
#include <type_traits>


namespace matrix {


void pack(int dim, double* a, double* b)
{

  for (int irow = dim-1; irow > -1; --irow)
  {
    for (int icol = irow; icol > -1; --icol)
    {
      int index_a = dim * irow + icol;
      int index_b = icol + irow * (irow + 1)/2;

      std::cout << " [" << irow << ", " << icol << "]   a[" << index_a << "]   b[" << index_b << "]: " << a[index_a] << " -> " << b[index_b] << std::endl;
    }
  }
}


void pack_recurr(int dim, double* a, double* b, int irow, int icol)
{
  int index_a = dim * irow + icol;
  int index_b = icol + irow * (irow + 1)/2;

  std::cout << " [" << irow << ", " << icol << "]   a[" << index_a << "]   b[" << index_b << "]: " << a[index_a] << " -> " << b[index_b] << std::endl;
 
  if (icol == 0 && irow == 0)
    return;

  if (icol <= irow && icol > 0)
    pack_recurr(dim, a, b, irow, icol-1);

  if (icol < irow && icol == 0)
    pack_recurr(dim, a, b, irow-1, irow-1);
}


void pack_recurr_start(int dim, double* a, double* b)
{
  pack_recurr(dim, a, b, dim-1, dim-1);
}


void unpack_recurr(int dim, double* b, double* a, int irow, int icol)
{
  int index_a = dim * irow + icol;
  int index_b = icol + irow * (irow + 1)/2;

  std::cout << " [" << irow << ", " << icol << "]   b[" << index_b << "]   a[" << index_a << "]: " << b[index_b] << " -> " << a[index_a] << std::endl;
 
  if (icol == 0 && irow == 0)
  {
    a[0] = b[0];
    return;
  }

  if (icol < irow && icol > 0)
  {
    std::cout << "this none-diag. next none-diag\n";

    int index_a_T = dim * icol + irow;
    std::cout << " [" << icol << ", " << irow << "]T  b[" << index_b << "]   a[" << index_a_T << "]: " << b[index_b] << " -> " << a[index_a_T] << std::endl;
 
    a[index_a]   = b[index_b];
    a[index_a_T] = b[index_b];

    unpack_recurr(dim, b, a, irow, icol-1);
  }

  if (icol == irow && icol > 0)
  {
    std::cout << "this diag\n";
    a[index_a]   = b[index_b];

    unpack_recurr(dim, b, a, irow, icol-1);
  }

  if (icol < irow && icol == 0)
  {
    std::cout << "this none-diag. next diag\n";

    int index_a_T = dim * icol + irow;
    std::cout << " [" << icol << ", " << irow << "]T  b[" << index_b << "]   a[" << index_a_T << "]: " << b[index_b] << " -> " << a[index_a_T] << std::endl;
 
    a[index_a]   = b[index_b];
    a[index_a_T] = b[index_b];

    unpack_recurr(dim, b, a, irow-1, irow-1);
  }
}


void unpack_recurr_start(int dim, double* b, double* a)
{
  unpack_recurr(dim, b, a, dim-1, dim-1);
}



/**
 * A struct to pack and unpack plain C-arrays by treating them as triangular
 * matrices.
 *
 * The packing/unpacking is done at compile time by creating a chain of
 * functions.
 */
template<int _Dim, typename _InputType = double, typename _OutputType = double>
struct Matrix
{
public:

  static void pack(const _InputType* a, _OutputType* b)
  {
    pack_impl<_Dim - 1, _Dim - 1>(a, b); 
  }

  static void unpack(const _InputType* b, _OutputType* a)
  {
    unpack_impl<_Dim - 1, _Dim - 1>(b, a); 
  }


private:

  template<int _IRow, int _ICol, typename std::enable_if< _IRow == 0 && _ICol == 0>::type * = nullptr >
  static void pack_impl(const _InputType* a, _OutputType* b)
  {
    b[0] = a[0];

    std::cout << " [" << _IRow << ", " << _ICol << "]   a[0] -> b[0]: " << a[0] << " -> " << b[0] << std::endl;
  }


  template<int _IRow, int _ICol, typename std::enable_if< (_ICol <= _IRow && _ICol > 0) >::type * = nullptr >
  static void pack_impl(const _InputType* a, _OutputType* b)
  {
    int index_a = _Dim * _IRow + _ICol;
    int index_b = _ICol + _IRow * (_IRow + 1)/2;

    b[index_b] = a[index_a];

    std::cout << " [" << _IRow << ", " << _ICol << "]   a[" << index_a << "] ->  b[" << index_b << "]: " << a[index_a] << " -> " << b[index_b] << std::endl;

    pack_impl<_IRow, _ICol - 1>(a, b);
  }


  template<int _IRow, int _ICol, typename std::enable_if< _ICol < _IRow && _ICol == 0>::type * = nullptr >
  static void pack_impl(const _InputType* a, _OutputType* b)
  {
    int index_a = _Dim * _IRow + _ICol;
    int index_b = _ICol + _IRow * (_IRow + 1)/2;

    b[index_b] = a[index_a];

    std::cout << " [" << _IRow << ", " << _ICol << "]   a[" << index_a << "] -> b[" << index_b << "]: " << a[index_a] << " -> " << b[index_b] << std::endl;

    pack_impl<_IRow - 1, _IRow - 1>(a, b);
  }



  template<int _IRow, int _ICol, typename std::enable_if< _IRow == 0 && _ICol == 0>::type * = nullptr >
  static void unpack_impl(const _InputType* b, _OutputType* a)
  {
    a[0] = b[0];

    std::cout << " [" << _IRow << ", " << _ICol << "]   a[0] -> b[0]: " << a[0] << " -> " << b[0] << std::endl;
  }


  template<int _IRow, int _ICol, typename std::enable_if< (_ICol < _IRow && _ICol > 0) >::type * = nullptr >
  static void unpack_impl(const _InputType* b, _OutputType* a)
  {
    int index_a   = _Dim * _IRow + _ICol;
    int index_a_T = _Dim * _ICol + _IRow;
    int index_b   = _ICol + _IRow * (_IRow + 1)/2;

    a[index_a]   = b[index_b];
    a[index_a_T] = b[index_b];

    std::cout << " [" << _IRow << ", " << _ICol << "]   b[" << index_b << "] -> a[" << index_a << "]: " << b[index_b] << " -> " << a[index_a] << std::endl;

    unpack_impl<_IRow, _ICol - 1>(b, a);
  }


  template<int _IRow, int _ICol, typename std::enable_if< _ICol == _IRow && (_ICol > 0) >::type * = nullptr >
  static void unpack_impl(const _InputType* b, _OutputType* a)
  {
    int index_a = _Dim * _IRow + _ICol;
    int index_b = _ICol + _IRow * (_IRow + 1)/2;

    a[index_a] = b[index_b];

    std::cout << " [" << _IRow << ", " << _ICol << "]   b[" << index_b << "] -> a[" << index_a << "]: " << b[index_b] << " -> " << a[index_a] << std::endl;

    unpack_impl<_IRow, _ICol - 1>(b, a);
  }


  template<int _IRow, int _ICol, typename std::enable_if< _ICol < _IRow && _ICol == 0>::type * = nullptr >
  static void unpack_impl(const _InputType* b, _OutputType* a)
  {
    int index_a   = _Dim * _IRow + _ICol;
    int index_a_T = _Dim * _ICol + _IRow;
    int index_b   = _ICol + _IRow * (_IRow + 1)/2;

    a[index_a]   = b[index_b];
    a[index_a_T] = b[index_b];

    std::cout << " [" << _IRow << ", " << _ICol << "]   b[" << index_b << "] -> a[" << index_a << "]: " << b[index_b] << " -> " << a[index_a] << std::endl;

    unpack_impl<_IRow - 1, _IRow - 1>(b, a);
  }
};


}

#endif
