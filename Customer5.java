package customer5;

import person5.Person5;
import personexception.PersonException;


public class Customer5 extends Person5 {
    private String address;
    private int age;

    public Customer5(String name,String address,int age) throws PersonException{
        super(name);

        if(address==null || (age<0 || age>130)){
            throw new PersonException();
        }
        this.address=address;
        this.age=age;
    }
        @Override
        public String toString(){
            return super.toString()+" Address:"+address+" Age:"+age;
        }
}