public interface Lists<E> extends Iterable<E> {
  int size(); // returns the number of elements in the list.
  boolean isEmpty(); // returns a Boolean indicating whether the list is empty.
  E get(int i) throws IndexOutOfBoundsException; // return -without removing- the element at index i
  E set(int i, E e) throws IndexOutOfBoundsException; // replaces the element at index i with e, and returns the replaced element.
  void add(int i, E e) throws IndexOutOfBoundsException; // insert element e to be at index i, shifting all subsequent elements later. 
  void add(E e); //  may throw throws IllegalStateException;
  E remove(int i) throws IndexOutOfBoundsException; // removes/returns the element at index i, shifting all subsequent elements earlier.
}






