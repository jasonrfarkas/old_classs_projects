import java.util. *;

public class ArrayList<E> implements Lists<E>
{
  public static final int CAPACITY = 100;
  private E[] data;
  private int size = 0;

  public ArrayList() { this(CAPACITY); }
  public ArrayList(int capacity) { data = (E[]) new Object[capacity]; }

  public int size() { return size; }
  public boolean isEmpty() { return size == 0; }
  // 
  public E get(int i) throws IndexOutOfBoundsException
  {
    checkIndex(i, size);
    return data[i];
  }
  // 
  public E set(int i, E e) throws IndexOutOfBoundsException
  {
    checkIndex(i, size);
    E temp = data[i];
    data[i] = e;
    return temp;
  }
  // 
  public void add(int i, E e) throws IndexOutOfBoundsException, IllegalStateException
  {
    checkIndex(i, size + 1);
    if (size == data.length) { throw new IllegalStateException("Array is full"); }
    for (int k=size-1; k >= i; k--)
      data[k+1] = data[k];
    data[i] = e;
    size++;
  }
  //Method to auto add to the end of the array
  public void add(E e) throws IllegalStateException
  {
    if (size == data.length) { throw new IllegalStateException("Array is full"); }
    data[size] = e;
    size++;
  }
  // 
  public E remove(int i) throws IndexOutOfBoundsException
  {
    checkIndex(i, size);
    E temp = data[i];
    for (int k=i; k < size-1; k++)
      data[k] = data[k+1];
    data[size-1] = null;
    size--;
    return temp;
  }
  // 
  protected void checkIndex(int i, int n) throws IndexOutOfBoundsException
  {
    if (i < 0 || i >= n)
      throw new IndexOutOfBoundsException(" Illegal index: " + i);
  }

  //---------------- nested ArrayIterator class ---------------- /∗∗
  //∗ A (nonstatic) inner class. Note well that each instance contains an implicit ∗ reference to the containing list, allowing it to access the list's members. ∗/
  private class ArrayIterator implements Iterator<E> {
      private int j = 0; // index of the next element to report 
      private boolean removable = false; // can remove be called at this time?

      ///∗∗
      //∗ Tests whether the iterator has a next object.
      //∗ @return true if there are further objects, false otherwise ∗/
      public boolean hasNext() { return j < size; } // size is field of outer instance

      ///∗∗
      //∗ Returns the next object in the iterator.
      //∗ @return next object
      //∗ @throws NoSuchElementException if there are no further elements ∗/
      public E next() throws NoSuchElementException {
      if (j == size) { throw new NoSuchElementException("No next element"); }
        removable = true; // this element can subsequently be removed
      return data[j++]; // post-increment j, so it is ready for future call to next
      }

      ///∗∗
      //∗ Removes the element returned by most recent call to next.
      //∗ @throws IllegalStateException if next has not yet been called
      //∗ @throws IllegalStateException if remove was already called since recent next ∗/
      public void remove() throws IllegalStateException {
      if (!removable) throw new IllegalStateException("nothing to remove");
        ArrayList.this.remove(j-1); 
        j--;
        removable = false;
      // that was the last one returned
      // next element has shifted one cell to the left // do not allow remove again until next is called
      }
  } //------------ end of nested ArrayIterator class ------------

  ///∗∗ Returns an iterator of the elements stored in the list. ∗/
  public Iterator<E> iterator( ) { 
    return new ArrayIterator();
  }
}

