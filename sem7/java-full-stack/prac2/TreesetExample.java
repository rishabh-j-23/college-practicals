import java.util.Iterator;
import java.util.TreeSet;

public class TreeSetExample {
    public static void main(String[] args) {
        TreeSet<Integer> treeSet = new TreeSet<>();

        treeSet.add(40);
        treeSet.add(12);
        treeSet.add(24);
        treeSet.add(34);

        treeSet.forEach(System.out::println);

        treeSet.remove(34);

        System.out.println("Smallest element: " + treeSet.first());

        Iterator<Integer> it = treeSet.iterator();

        while (it.hasNext()) {
            System.out.println(it.next());
        }

        System.out.println("Size of treeSet: " + treeSet.size());
    }
}
