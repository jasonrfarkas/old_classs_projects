/*
 * SafeArray.h
 *
 *  Created on: May 5, 2014
 *      Author: SruliF
 */

#ifndef SAFEARRAY_H_
#define SAFEARRAY_H_

template <class T>
class SafeArray
{
   private:
      T* array;
      int size;

   public:
      SafeArray();
      SafeArray(int s);
      int length() const;
      T& operator [] (int index);
      ~SafeArray();
      SafeArray(const SafeArray<T>& other);
      SafeArray<T>& operator = (const SafeArray<T>& other);
};

#endif /* SAFEARRAY_H_ */
