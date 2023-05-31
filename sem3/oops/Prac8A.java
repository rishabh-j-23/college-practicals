import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Prac8A {
    public static void main(String[] args) {
        ArrayList list = new ArrayList<>();

        Scanner sc = new Scanner(System.in);
        boolean runMenu = true;
        while (runMenu) {

            System.out.println("1. Add element");
            System.out.println("2. Add element at index");
            System.out.println("3. Set element at index");
            System.out.println("4. Delete element at index");
            System.out.println("5. Size of arraylist");
            System.out.println("6. Loop through list");
            System.out.println("7. Sort the list");

            System.out.print("Response : ");
            int response = sc.nextInt();
            switch (response) {
                case 1: // add element
                {
                    boolean run = true;
                    while (run) {
                        System.out.print("element to add : ");
                        String ele = sc.next();
                        list.add(ele);

                        System.out.println("Continue adding? (true/false)");
                        run = sc.nextBoolean();
                    }
                    break;
                }

                case 2: // add element at index
                {
                    boolean run = true;
                    while (run) {
                        System.out.print("element to add : ");
                        String ele = sc.next();
                        System.out.println();
                        System.out.print("at index : ");
                        int index = sc.nextInt();
                        list.add(index, ele);

                        System.out.println("Continue adding? (true/false)");
                        run = sc.nextBoolean();
                    }
                }
                    break;

                case 3: // set element at index
                {
                    boolean run = true;
                    while (run) {
                        System.out.print("element to add : ");
                        String ele = sc.next();
                        System.out.println();
                        System.out.print("at index : ");
                        int index = sc.nextInt();
                        list.set(index, ele);

                        System.out.println("Continue setting? (true/false)");
                        run = sc.nextBoolean();
                    }
                }
                    break;

                case 4: // delete element at index
                {
                    boolean run = true;
                    while (run) {
                        System.out.print("delete element at index : ");
                        int index = sc.nextInt();
                        list.remove(index);

                        System.out.println("Continue deleting? (true/false)");
                        run = sc.nextBoolean();
                    }
                }
                    break;

                case 5: // size
                    System.out.println("Size of arraylist : " + list.size());
                    break;

                case 6:
                    System.out.print("[ ");
                    for (Object o : list) {
                        System.out.print(o + " ");
                    }
                    System.out.println("]");
                    System.out.println();
                    break;

                case 7: // sort
                    Collections.sort(list);
                    System.out.println("arraylist was sorted");
                    break;

                default:
                    System.out.println("Enter valid response");
            }

            System.out.println("Back to menu? (true/false)");
            runMenu = sc.nextBoolean();
        }
        sc.close();
    }
}