public class L01 {
    public static void main(String[] args) {
        Complex c1 = new Complex(0, 1);
        Complex c2 = new Complex(0, 1);
        System.out.println(c1.multiply(c2));
    }
}

class Cursor {

// Methods

    Cursor() { // Constructor
        this.x = 0;
        this.y = 0;
    }

    int getX() {
        return this.x;
    }

    int getY() {
        return this.y;
    }

    void moveLeft() {
        this.x--;
    }

    void moveRight() {
        this.x++;
    }

    void moveUp() {
        this.y++;
    }

    void moveDown() {
        this.y--;
    }

// Fields
    private int x;
    private int y;

}

class Complex {
    // Methods
    Complex(float a, float b) {
        this.a = a;
        this.b = b;
    }

    float realPart() {
        return this.a;
    }

    float imaginaryPart() {
        return this.b;
    }

    Complex multiplyByScalar(float scalar) {
        return new Complex(
            this.realPart() * scalar,
            this.imaginaryPart() * scalar
        );
    }

    Complex add(Complex other) {
        float newRealPart = this.realPart() + other.realPart();
        float newImaginaryPart = this.imaginaryPart() + other.imaginaryPart();
        return new Complex(newRealPart, newImaginaryPart);
    }

    Complex multiply(Complex other) {
        return new Complex(
            this.realPart() * other.realPart() - this.imaginaryPart() * other.imaginaryPart(),
            this.realPart() * other.imaginaryPart() + this.imaginaryPart() * other.realPart()
        );
    }

    public String toString() {
        if (this.imaginaryPart() > 0) {
            return this.realPart() + "+" + this.imaginaryPart() + "i";
        } else {
            return this.realPart() + "-" + (- this.imaginaryPart()) + "i";
        }
    }
    
    // Fields
    private float a;
    private float b;
}
