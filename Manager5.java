package manager5;

import employee5.Employee5;
import personexception.PersonException;

public class Manager5 extends Employee5 {
    private String post;

    public Manager5(String name, String department, String post) throws PersonException {
        super(name, department);
        if (post.equals("社長")||post.equals("部長")||post.equals("課長")||post.equals("係長")) {
            this.post=post;
        } else {
            throw new PersonException();
        }
    }

    @Override
    public String toString() {
        return super.toString() + " Post:" + post;
    }

}
