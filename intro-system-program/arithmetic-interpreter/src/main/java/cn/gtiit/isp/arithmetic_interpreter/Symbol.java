package cn.gtiit.isp.arithmetic_interpreter;

public class Symbol {

    Symbol(String name) {
        this.name = name;
    }

    String getName() {
        return this.name;
    }

    public String toString() {
        return this.name;
    }

    public boolean equals(Object obj) {
        if (obj == null || this.getClass() != obj.getClass()) {
            return false;
        }
        Symbol other = (Symbol)obj;
        return this.getName().equals(other.getName());
    }

    private String name;
}