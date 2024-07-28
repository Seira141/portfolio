package personexception;

public class PersonException extends Exception {
    @Override
    public String toString() {
        return "不正な値が指定されました";
    }
}