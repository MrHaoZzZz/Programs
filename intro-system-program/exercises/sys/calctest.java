import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

class calcrTest {
    @Test
    void testAddition() {
        Calculator calc = new Calculator();
        assertNotNull(calc);
        assertEquals(5, calc.add(2, 3), "2 + 3 应该等于 5");
    }
}