package com.company;

public class Goods {
    public static int id = 0;

    private int goodsID;
    private String name;
    private int weight;
    private int price;
    private int count;
    private String date;
    private boolean sale;


    public void setGoodsID(int goodsID) {
        this.goodsID = goodsID;
    }


    public void setName(String name) {
        boolean okName = true;
        for (int i = 1; i < name.length() && okName; i++) {
            if (!(name.charAt(i) >= 97 && name.charAt(i)<= 122)) {
                okName = false;
            }
        }
        if (okName) this.name = name;
        else {
            this.name = "";
            System.out.println("Введено некорректное значение");
        }
    }


    public void setWeight(String weight) {
        boolean okWeight = weight.charAt(0) != '0';
        for (int i = 0; i < weight.length() && okWeight; i++) {
            if (!(weight.charAt(i) >= '1' && weight.charAt(i) <= '9')) {
                okWeight = false;
            }
        }
        if (okWeight) this.weight = Integer.parseInt(weight);
        else {
            this.weight = 0;
            System.out.println("Введено некорректное значение");
        }
    }


    public void setPrice(String price) {
        boolean okPrice = price.charAt(0) != '0';
        for (int i = 0; i < price.length() && okPrice; i++) {
            if (!(price.charAt(i) >= '0' && price.charAt(i) <= '9')) {
                okPrice = false;
            }
        }
        if (okPrice) this.price = Integer.parseInt(price);
        else {
            this.price = 0;
            System.out.println("Введено некорректное значение");
        }
    }


    public void setCount(String count) {
        boolean okCount = count.charAt(0) != '0';
        for (int i = 0; i < count.length() && okCount; i++) {
            if (!(count.charAt(i) >= '1' && count.charAt(i) <= '9')) {
                okCount = false;
            }
        }
        if (okCount) this.count = Integer.parseInt(count);
        else {
            this.count = 0;
            System.out.println("Введено некорректное значение");
        }
    }

    public void setDate(String date) {
        boolean okDate = true;
        String[] arrDate  = date.split("\\.");
        if (arrDate.length < 3) {
            this.date = "00.00.00";
            System.out.println("Введено некорректное значение");
        }
        else {
            for (int i = 0; i < arrDate.length && okDate; i++) {
                for (int j = 0; j < arrDate[i].length() && okDate; j++) {
                    if ((arrDate[i].charAt(0) >= '0' && arrDate[i].charAt(0) <= '3' && arrDate[i].charAt(1) >= '0' && arrDate[i].charAt(1) <= '9'))
                        okDate = false;
                }
            }
            if (okDate) this.date = date;
            else {
                this.date = "00.00.00";
                System.out.println("Введено некорректное значение");
            }
        }
    }

    public void setSale(String sale) {
        if (sale.equals("Yes"))
            this.sale = true;
        else if (sale.equals("No"))
            this.sale = false;
        else {
            this.sale = false;
            System.out.println("Введено некорректное значение");
        }

    }

    @Override
    public String toString() {
        return "Goods {" +
                "goodsID=" + goodsID +
                ", name='" + name + '\'' +
                ", weight=" + weight +
                ", price=" + price +
                ", count=" + count +
                ", date=" + date +
                ", sale=" + sale +
                '}';
    }
}
