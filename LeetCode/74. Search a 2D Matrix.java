public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        int m = matrix.length;
        int n = matrix[0].length;
        
        if(m == 0 || n == 0) return false;
        
        int i = 0;
        int j = m * n - 1;
        
        while(i <= j){
            int mid = (j + i) / 2;
            if(matrix[mid / n][mid % n] == target) return true;
            else if(matrix[mid / n][mid % n] < target) i = mid + 1;
            else j = mid - 1;
        }
        
        return false;
    }
}