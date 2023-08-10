import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}

class AgeComparator implements Comparator<Person> {
    @Override
    public int compare(Person person1, Person person2) {
        // Compare the ages of two Person objects
        // For ascending order, use "return person1.getAge() - person2.getAge();"
        // For descending order, use "return person2.getAge() - person1.getAge();"
        return person1.getAge() - person2.getAge();
    }
}

public class Main {
    public static void main(String[] args) {
        List<Person> people = new ArrayList<>();
        people.add(new Person("Alice", 25));
        people.add(new Person("Bob", 30));
        people.add(new Person("Charlie", 20));

        // Sorting the list of people based on age using the AgeComparator
        Collections.sort(people, new AgeComparator());

        // Print the sorted list
        for (Person person : people) {
            System.out.println(person.getName() + " - " + person.getAge());
        }
    }
}
