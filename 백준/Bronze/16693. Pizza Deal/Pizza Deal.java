import java.util.*;
import java.lang.*;
import java.io.*;

interface Pizza {
    double pizzaPerDollar();
}

class SlicePizza implements Pizza {
    int area;
    int cost;

    SlicePizza(int area, int cost) {
        this.area = area;
        this.cost = cost;
    }

    public double pizzaPerDollar() {
        return (double) area / cost;
    }
}

class WholePizza implements Pizza {
    int radius;
    int cost;

    WholePizza(int radius, int cost) {
        this.radius = radius;
        this.cost = cost;
    }

    public double pizzaPerDollar() {
        return (double) Math.PI * Math.pow(radius, 2) / cost;
    }    
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Pizza[] pizzas = {
            new SlicePizza(sc.nextInt(), sc.nextInt()),
            new WholePizza(sc.nextInt(), sc.nextInt())
        };

        System.out.println(
            pizzas[0].pizzaPerDollar() > pizzas[1].pizzaPerDollar()
            ? "Slice of pizza"
            : "Whole pizza"
        );
    }
}