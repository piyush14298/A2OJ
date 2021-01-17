class Test {
    {
        System.out.print("A");
    }
    public Test() {
        System.out.print("B");
    }
    static {
        System.out.print("C");
    }
}

class Test1 extends Test {
    static {
        System.out.print("D");
    }
    public Test1() {
        System.out.print("E");
    }
    {
        System.out.print("F");
    }
}

public class Test3 extends Test1 {
    public static void main(String args[]) {
        System.out.print("G");
        new Test3();
        System.out.print("H");
    }
}

