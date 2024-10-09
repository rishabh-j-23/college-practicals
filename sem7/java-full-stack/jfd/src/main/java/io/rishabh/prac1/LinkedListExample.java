package io.rishabh.prac1;

import java.util.LinkedList;
import java.util.Iterator;

public class LinkedListExample {
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();

        list.add(40);
        list.add(12);
        list.add(24);
        list.add(34);
        System.out.println("After adding elements: " + list);

        Integer number = list.get(1);
        System.out.println("Element at index 1: " + number);

        list.remove(2);
        System.out.println("After removing element at index 2: " + list);

        Iterator<Integer> iterator = list.iterator();
        System.out.print("Iterating through the list: ");
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }
        System.out.println();

        boolean hasTwelve = list.contains(12);
        System.out.println("List contains 12: " + hasTwelve);

        int size = list.size();
        System.out.println("Size of the list: " + size);

        list.clear();
        System.out.println("After clearing the list: " + list);
    }
}
