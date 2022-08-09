class DataStack{
    private int[] items = new int[10];
    private int length;

    public DataStack(){
        length = -1;
    }

    public DataStack(DataStack myStack){
        this.items = myStack.items;
        this.length = myStack.length;
    }

    public int[] getItems(){
        return items;
    }

    public int getLength(){
        return length;
    }

    public void push(int value){
        items[++length] = value;
    }

    public int pop(){
        return items[length--];
    }

    public static boolean equals(DataStack myStack1, DataStack myStack2){
        StackIterator it1 = new StackIterator(myStack1),
                it2 = new StackIterator(myStack2);

        while (it1.isEnd() || it2.isEnd()){
            if (it1.get() != it2.get()) break;
            StackIterator.increment(it1);
            StackIterator.increment(it2);
        }

        return !it1.isEnd() && !it2.isEnd();
    }
}

class StackIterator
{
    private DataStack stack;
    private int index;

    public StackIterator(DataStack myStack){
        this.stack = myStack;
        this.index = 0;
    }

    public static StackIterator increment(StackIterator s){
        s.index++;
        return s;
    }

    public int get(){
        if (index < stack.getLength())
            return stack.getItems()[index];
        return 0;
    }

    public boolean isEnd(){
        return index != stack.getLength() + 1;
    }
}

public class Main {
    public static void main(String[] args){

        DataStack myStack1 = new DataStack();
        
        for (int i = 0; i < 5; i++){
            myStack1.push(i);
        }

        DataStack myStack2 = new DataStack(myStack1);

        System.out.println(DataStack.equals(myStack1, myStack2));

        myStack2.push(10);

        System.out.println(DataStack.equals(myStack1, myStack2));
    }
}