package com.company;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Lab {
    static  Scanner sc = new Scanner(System.in);
    static Goods[] goods = new Goods[100];
    public static void main(String[] args) {



        System.out.println("1. Add System");
        System.out.println("2. Delete of the System");
        System.out.println("3. Show All");
        System.out.println("4. Save to File");
        System.out.println("5. Load from File");

        int choice;
        while (true) {
            choice = sc.nextInt();
            if (choice == 1) {
                addSystem();
            } else if (choice == 2) {
                deleteFromSystem();
            } else if (choice == 3) {
                showAll();
            } else if (choice == 4) {
                saveToFile();
            } else if (choice == 5) {
                loafFromFile();
            } else break;
        }
    }

    // 1
    private static void addSystem() {
        Goods good = new Goods();
        good.setGoodsID(Goods.id);
        // name
        System.out.println("Input Name");
        String name = sc.next();
        good.setName(name);
        // count
        System.out.println("Input Count");
        String count = sc.next();
        good.setCount(count);
        // date
        System.out.println("Input Date");
        String date = sc.next();
        good.setDate(date);
        // price
        System.out.println("Input Price");
        String price = sc.next();
        good.setPrice(price);
        // sale
        System.out.println("Input Sale: Yes or No");
        String sale = sc.next();
        good.setSale(sale);
        // weight
        System.out.println("Input weight");
        String weight = sc.next();
        good.setWeight(weight);

        goods[Goods.id++] = good;
        System.out.println("Object add to the system");
    }

    // 2
    private static void deleteFromSystem() {
        int id = sc.nextInt();
        if (id < Goods.id) goods[id] = null;
    }

    // 3
    private static void showAll() {
        for (int i = 0; i < Goods.id; i++) {
            if (goods[i] != null) System.out.println(goods[i]);
        }
    }

    // 4
    private static void saveToFile() {

    }

    // 5
    private static void loafFromFile() {

    }


}
