using System.Collections;

namespace collections;
using inter;

public class MyCustomCollection<T> : ICustomCollection<T>, IEnumerable<T>
{
    private class Node
    {
        public T Data { get; set; }
        public Node Next { get; set; }

        public Node(T data)
        {
            Data = data;
            Next = null;
        }
    }

    private Node head;
    private Node current;
    private int count;

    public MyCustomCollection()
    {
        head = null;
        current = null;
        count = 0;
    }

    public T this[int index]
    {
        get
        {
            if (index < 0 || index >= count)
                throw new IndexOutOfRangeException("Index is out of range.");
            
            Node currentNode = head;
            for (int i = 0; i < index; i++)
            {
                currentNode = currentNode.Next;
            }
            return currentNode.Data;
        }
        set
        {
            if (index < 0 || index >= count)
                throw new IndexOutOfRangeException("Index is out of range.");
            
            Node currentNode = head;
            for (int i = 0; i < index; i++)
            {
                currentNode = currentNode.Next;
            }
            currentNode.Data = value;
        }
    }

    public void Reset()
    {
        current = head;
    }

    public void Next()
    {
        if (current != null)
        {
            current = current.Next;
        }
    }

    public T Current()
    {
        if (current != null)
        {
            return current.Data;
        }
        throw new InvalidOperationException("No current element.");
    }

    public int Count
    {
        get { return count; }
    }

    public void Add(T item)
    {
        Node newNode = new Node(item);
        if (head == null)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current.Next = newNode;
            current = newNode;
        }
        count++;
    }

    public void Remove(T item)
    {
        if (head == null)
            return;

        if (head.Data.Equals(item))
        {
            head = head.Next;
            count--;
            return;
        }

        Node previous = head;
        Node current = head.Next;

        while (current != null)
        {
            if (current.Data.Equals(item))
            {
                previous.Next = current.Next;
                count--;
                return;
            }

            previous = current;
            current = current.Next;
        }

        throw new InvalidOperationException("Item not found.");
    }

    public T RemoveCurrent()
    {
        if (current == null)
            throw new InvalidOperationException("No current element.");

        T data = current.Data;
        Remove(data);
        return data;
    }

    public IEnumerator<T> GetEnumerator()
    {
        Node? currentNode = head;
        while (currentNode != null)
        {
            yield return currentNode.Data;
            currentNode = currentNode.Next;
        }
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }

}