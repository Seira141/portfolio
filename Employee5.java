package employee5;

import person5.Person5;
import personexception.PersonException;

public class Employee5 extends Person5{
    
    private String department;

    public Employee5(String name,String department) throws PersonException{
        super(name);
        if(department.equals("総務部")
         ||department.equals("財務部")
         ||department.equals("営業部")
         ||department.equals("開発部")
         ||department.equals("製造部")){
        this.department=department;
        }else{
            throw new PersonException();
        }
    }

    @Override
    public String toString(){
        return super.toString()+" Department:"+department;
    }
    
}