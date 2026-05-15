class Solution {
    public int[] findDegrees(int[][] matrix) {
        int[] degrees = new int[matrix.length];

        for (int y = 0; y < matrix.length; y++) {
            for (int x = 0; x < matrix[y].length; x++) {
                if (matrix[y][x] == 1) {
                    degrees[y]++;
                }
            }
        }
        return degrees;
    }
}