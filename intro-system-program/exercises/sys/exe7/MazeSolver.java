import java.util.ArrayList;

public class MazeSolver {
    public static void main(String[] args) {
        Maze maze = new Maze(
              "  ###################################\n"
            + "# #           #         #           #\n"
            + "# # ######### # ##### # ##### #######\n"
            + "# #   # #     # #     #       #   # #\n"
            + "# ### # # ##### # ############# ### #\n"
            + "#     # #       # #     #   #       #\n"
            + "####### ####### # # ### # # ### #####\n"
            + "#       #       #     #   #   #   # #\n"
            + "# ####### ################### ##### #\n"
            + "#         #   #       #       #     #\n"
            + "# ######### # # # ### # ####### #####\n"
            + "#       #   # # # #   #    #        #\n"
            + "####### ### # # # # ### # ### # #####\n"
            + "# #   #     # # # #  #  # #   # #   #\n"
            + "# # # ####### ### ####### # ### # # #\n"
            + "#   #       #   # #         # #   # #\n"
            + "# ####### ##### # # ######### ##### #\n"
            + "# #     # #   # # #         #   #   #\n"
            + "# # ### # # # # # ######### ### # ###\n"
            + "#   #   #   #     #             #   #\n"
            + "##################################   \n"
            );
        ArrayList<Position> solution = solveMaze(maze);
        maze.showPath(solution);
    }

    public static ArrayList<Position> solveMaze(Maze maze) {
        // *** COMPLETE HERE ***
        // The solution below is just an illustrative example.
        // You should erase this code and define a function that
        // finds the path that starts (0,0) and arrives at (n-1,m-1)
        // where n = maze.rows() and m = maze.columns().
        ArrayList<Position> solution = new ArrayList();
        solution.add(new Position(0, 0));
        solution.add(new Position(0, 1));
        solution.add(new Position(1, 1));
        solution.add(new Position(2, 1));
        return solution;
    }
}

enum Cell {
    Floor,
    Wall
}

class Position {
    int row;
    int column;
    Position(int row, int column) {
        this.row = row;
        this.column = column;
    }
}

class Maze {

    /* Methods */

    Maze(String map) {
        String[] rows = map.split("\n");
        this.n = rows.length;
        this.m = rows[0].length();
        this.map = new ArrayList<ArrayList<Cell>>();
        for (int i = 0; i < this.n; i++) {
            ArrayList<Cell> row = new ArrayList<Cell>();
            for (int j = 0; j < this.m; j++) {
                char c = rows[i].charAt(j);
                if (c == '#') {
                    row.add(Cell.Wall);
                } else {
                    row.add(Cell.Floor);
                }
            }
            this.map.add(row);
        }
    }
    
    int rows() {
        return this.n;
    }

    int columns() {
        return this.m;
    }

    Cell at(Position p) {
        return this.map.get(p.row).get(p.column);
    }

    void showPath(ArrayList<Position> path) {
        String res = "";
        for (int i = 0; i < this.n; i++) {
            String line = "";
            for (int j = 0; j < this.m; j++) {
                if (this.map.get(i).get(j) == Cell.Wall) {
                    line += "#";
                } else {
                    boolean b = false;
                    for (Position p : path) {
                        if (p.row == i && p.column == j) {
                            b = true;
                        }
                    }
                    if (b) {
                        line += ".";
                    } else {
                        line += " ";
                    }
                }
            }
            if (i > 0) {
                res += "\n";
            }
            res += line;
        }
        System.out.println(res);
    }

    /* Fields */
    int n;
    int m;
    ArrayList<ArrayList<Cell>> map;

}
