/**
 * @author Rudolf Sneep
 * My Java Solution for Project Euler Problem 15: Lattice paths
 *
 * https://projecteuler.net/problem=15
 * Starting in the top left corner of a 2×2 grid, and only being able to move
 * to the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 * ********************************************************
 *
 * I will solve this by calculating the number of paths to a certain
 * coordinate "x:y". All the paths of a certain coordinate
 * are just the sum of all the paths of the sub branches.
 * Using a TreeMap we can automatically sort and save all the solutions.
 * At the end we retrieve the number of all possible paths,
 * by just retrieving the last solution in the TreeMap.
 *
 * Parts
 * 1. Customizable Variables
 *      - you can change their values
 *      - the algorithm also works with rectangles
 * 2. Model of the Problem
 * 3. Initializing variables used in the for loops
 * 4. Start the calculation
 * 5. Print the Solution
 * 6. Methods
 */

import java.util.TreeMap;

public class Problem15 {
    public static void main(String[] args){

/******************* 1. Customizable Variables *******************/

        //Sized of nxm rectangle
        //Length and width are split, so the code will work for rectangles
        final int horizontalSide = 20;
        final int verticalSide   = 20;

        //If the size of the rectangle is below this limit
        //Print out all the paths for the individual nodes/coordinates
        int printLimit = 5;

/******************** 2. Model of the Problem ********************/

    /*        Example for a 2x2 sided 3x3 noded grid
     *
     *        x:y =   [0][0] -- [0][1] -- [0][2]    ->
     *                   |         |         |       x
     *         y|     [1][0] -- [1][1] -- [1][2]
     *         \/        |         |         |
     *                [2][0] -- [2][1] -- [2][2]
     */

/******** 3. Initializing variables used in the for loops ********/

        //a nxn sided square will have
        //(n+1)x(n+1) nodes.
        int width  = horizontalSide+1; //maxStepsRight
        int height =   verticalSide+1; //maxStepsDown

        //Coordinates   x:y
        int x; //goes to the right
        int y; //goes downward

        //Initializing the TreeMap where we store the answers
        //Use long, because the numbers grow exponentially with the grid size
        TreeMap<String,Long> answers = new TreeMap<>();

        //Variable used to store and change path counts
        long subPathsTotal;

/******************** 4. Start the calculation ********************/

        for(x=0; x<width; x++){
            for(y=0; y<height; y++){
                //calculating the all paths for coordinate 0:0

                //Initialize the List to store the new paths for x:y
                subPathsTotal = 0; //reset the path counter

                //Setup the first coordinate
                //If not setup properly, the whole TreeMap will be blank
                if(x==0 && y==0){
                    subPathsTotal = 1;
                }

                if(x>0){ //*if there are branches on the left*
                //Retrieve the number of paths of the branch left of it (x-1,y)
                //and add that count to the total for this coordinate
                    subPathsTotal += answers.get(coordinateString(x-1,y));
                }
                if(y>0){//*if there are branches above,*
                //Retrieve the number of paths of the branch above it in (x,y-1)
                //and add that count to the total for this coordinate
                    subPathsTotal += answers.get(coordinateString(x,y-1));
                }

                //Finally put the sum of all the paths for x:y
                //into the 'answers' TreeMap
                answers.put(coordinateString(x,y),subPathsTotal);

       /***** For smaller rectangles print out the paths for each node *****/
                if(horizontalSide<printLimit
                  && verticalSide<printLimit){
                    System.out.printf("%d:%d ",x,y);
                    System.out.println(subPathsTotal);
                }
            }
        }

/******************** 5. Print the Solution ********************/
        System.out.println("***Number of Possible Paths***");
        System.out.println(answers.get(coordinateString(horizontalSide,verticalSide)));
    }

/************************* 6. Methods *************************/

    /**
     * Converts {@code int} coordinates into a a String form,
     * so it can be more easily stored in the 'answers' TreeMap.
     * @param xInteger this {@code int} is the x coordinate
     * @param yInteger this {@code int} is the y coordinate
     * @return {@code String} of your coordinate in the format {@code x:y}
     */
    public static String coordinateString(int xInteger, int yInteger){
        return Integer.toString(xInteger)+":"+Integer.toString(yInteger);
    }

}
