package person5;

import personexception.PersonException;

public class Person5 {
    private String name;

    public Person5(String name) throws PersonException {
        if (name == null) {
            throw new PersonException();
        } else {
            this.name = name;
        }
    }

    @Override
    public String toString() {
        return "Name:" + name;
    }

}